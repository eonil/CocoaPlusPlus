//
//  Image.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/24.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../CoreFoundation/Type.h"
#include "ColorSpace.h"
#include "DataProvider.h"

EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN






class
Image : public CoreFoundation::Type
{
public:
	using	Type::Type;
	
	Image(CGImageRef);
	
public:
	operator CGImageRef() const;
	
public:
	enum class
	ALPHA_INFO : uint32_t
	{
		NONE					=	kCGImageAlphaNone,
		NONE_SKIP_FIRST			=	kCGImageAlphaNoneSkipFirst,
		NONE_SKIP_LAST			=	kCGImageAlphaNoneSkipLast,
		ONLY					=	kCGImageAlphaOnly,						//	No color channel. Alpha-only single channled image.
		LAST					=	kCGImageAlphaLast,						//	Straight alpha.
		FIRST					=	kCGImageAlphaFirst,						//	Straight alpha.
		PREMULTIPLIED_LAST		=	kCGImageAlphaPremultipliedLast,
		PREMULTIPLIED_FIRST		=	kCGImageAlphaPremultipliedFirst,
		
		MASK					=	kCGBitmapAlphaInfoMask,
	};
	enum class
	BYTE_ORDER_INFO : uint32_t
	{
		DEFAULT					=	kCGBitmapByteOrderDefault,
		LITTLE_16_BIT			=	kCGBitmapByteOrder16Little,
		LITTLE_32_BIT			=	kCGBitmapByteOrder32Little,
		BIG_16_BIT				=	kCGBitmapByteOrder16Big,
		BIG_32_BIT				=	kCGBitmapByteOrder32Big,
		
		MASK					=	kCGBitmapByteOrderMask,
	};
	struct
	BitmapInfo
	{
		ALPHA_INFO			alphaInfo			{ALPHA_INFO::NONE};
		bool				floatComponents		{false};
		BYTE_ORDER_INFO		byteOrder			{BYTE_ORDER_INFO::DEFAULT};
	};
	
	struct
	Metadata
	{
		struct
		Dimension
		{
			size_t								width				{};
			size_t								height				{};
			
			Dimension() {}
			Dimension(size_t width, size_t height) : width(width), height(height) {}
		};
		
		struct
		Layout
		{
			size_t								bitsPerComponent	{};
			size_t								bitsPerPixel		{};
			size_t								bytesPerRow			{};
		};
		
		Dimension							dimension			{};
		Layout								layout				{};
		ColorSpace							colorSpace			{nullptr};
		BitmapInfo							bitmapInfo			{};

		Float const*						decode				{};
		bool								shouldInterpolate	{false};
		ColorSpace::RENDERING_INTENT		renderingIntent		{ColorSpace::RENDERING_INTENT::DEFAULT};

		////
		
		static auto							deviceAlphaOnly8(Dimension const& dimension) -> Metadata;		//!	Single channel image info.
		static auto							deviceRGB888(Dimension const& dimension) -> Metadata;
		static auto							deviceRGBA8888(Dimension const& dimension) -> Metadata;			//!	Alpha channel is straight-alpha at last.
	};
	
public:
	Image(Metadata const& metadata, DataProvider& content);
	
	auto	copy() const -> Image;
	
	auto	width() const -> size_t;
	auto	height() const -> size_t;
	
	auto	bitsPerComponent() const -> size_t;
	auto	bitsPerPixel() const -> size_t;
	auto	bytesPerRow() const -> size_t;
	
	auto	isMask() const -> bool;
	auto	shouldInterpolate() const -> bool;
	
	auto	dataProvider() const -> DataProvider;
	auto	colorSpace() const -> ColorSpace;
	
public:
	auto	metadata() const -> Metadata;
	
};















EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END
