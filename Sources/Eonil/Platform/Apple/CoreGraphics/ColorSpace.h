//
//  ColorSpace.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/24.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../CoreFoundation/Type.h"

EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN












class
ColorSpace : CoreFoundation::Type
{
public:
	using	Type::Type;
	
	ColorSpace(CGColorSpaceRef);
	
public:
	operator CGColorSpaceRef() const;
	
//public:
//	ColorSpace(str const& name);
	
public:
//	enum class
//	NAME
//	{
//		GENERIC_GRAY,
//		GENERIC_RGB,
//		SRGB,
//		GENERIC_GRAY_GAMMA_2_2,
//	};
	
	enum class
	MODEL : int32_t
	{
		UNKNOWN			=	kCGColorSpaceModelUnknown,
		MONOCHROME		=	kCGColorSpaceModelMonochrome,
		RGB				=	kCGColorSpaceModelRGB,
		CMYK			=	kCGColorSpaceModelCMYK,
		LAB				=	kCGColorSpaceModelLab,
		DEVICE_N		=	kCGColorSpaceModelDeviceN,
		INDEXES			=	kCGColorSpaceModelIndexed,
		PATTERN			=	kCGColorSpaceModelPattern,
	};
	
	
	enum class
	RENDERING_INTENT
	{
		DEFAULT					=	kCGRenderingIntentDefault,
		ABSOLUTE_COLORIMETRIC	=	kCGRenderingIntentAbsoluteColorimetric,
		RELATIVE_COLORIMETRIC	=	kCGRenderingIntentRelativeColorimetric,
		PERCEPTUAL				=	kCGRenderingIntentPerceptual,
		SATURATION				=	kCGRenderingIntentSaturation,
	};

	
public:
	auto	name() const -> CoreFoundation::String;
	auto	model() const -> MODEL;
	
public:
	static auto		calibratedGray(Float const* whitePoint, Float const* blackPoint, Float gamma) -> ColorSpace;
	static auto		calibratedRGB(Float const* whitePoint, Float const* blackPoint, Float const* gamma, Float const* matrix) -> ColorSpace;
	
	static auto		deviceGray() -> ColorSpace;
	static auto		deviceRGB() -> ColorSpace;
	
//	static auto		withName(NAME const& name) -> ColorSpace;
//	static auto		withPlatformColorSpace(void* platformColorSpaceReference) -> ColorSpace;
};















EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END
