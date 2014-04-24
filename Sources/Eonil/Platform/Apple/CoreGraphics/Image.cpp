//
//  Image.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/24.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Image.h"
#include "DataProvider.h"
#include "ColorSpace.h"

EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN








Image::Image(CGImageRef o) : Type(o)
{
}

Image::operator CGImageRef() const
{
	return	(CGImageRef)operator CFTypeRef();
}

































auto
Image::Metadata::deviceAlphaOnly8(const Eonil::CocoaCPP::CoreGraphics::Image::Metadata::Dimension &dimension) -> Metadata
{
	Metadata	inf2	{};
	
	inf2.dimension					=	dimension;
	inf2.layout.bitsPerComponent	=	8;
	inf2.layout.bitsPerPixel		=	8 * 1;
	inf2.layout.bytesPerRow			=	1 * dimension.width;
	inf2.colorSpace					=	ColorSpace::deviceGray();
	inf2.bitmapInfo.alphaInfo		=	Image::ALPHA_INFO::ONLY;
	inf2.bitmapInfo.floatComponents	=	false;
	inf2.bitmapInfo.byteOrder		=	Image::BYTE_ORDER_INFO::DEFAULT;
	inf2.decode						=	nullptr;
	inf2.shouldInterpolate			=	false;
	inf2.renderingIntent			=	ColorSpace::RENDERING_INTENT::DEFAULT;
	
	return	inf2;
}

auto
Image::Metadata::deviceRGB888(const Eonil::CocoaCPP::CoreGraphics::Image::Metadata::Dimension &dimension) -> Metadata
{
	Metadata	inf2	{};
	
	inf2.dimension					=	dimension;
	inf2.layout.bitsPerComponent	=	8;
	inf2.layout.bitsPerPixel		=	8 * 3;
	inf2.layout.bytesPerRow			=	3 * dimension.width;
	inf2.colorSpace					=	ColorSpace::deviceRGB();
	inf2.bitmapInfo.alphaInfo		=	Image::ALPHA_INFO::NONE;
	inf2.bitmapInfo.floatComponents	=	false;
	inf2.bitmapInfo.byteOrder		=	Image::BYTE_ORDER_INFO::DEFAULT;
	inf2.decode						=	nullptr;
	inf2.shouldInterpolate			=	false;
	inf2.renderingIntent			=	ColorSpace::RENDERING_INTENT::DEFAULT;
	
	return	inf2;
}
auto
Image::Metadata::deviceRGBA8888(const Eonil::CocoaCPP::CoreGraphics::Image::Metadata::Dimension &dimension) -> Metadata
{
	Metadata	inf2	{};
	
	inf2.dimension					=	dimension;
	inf2.layout.bitsPerComponent	=	8;
	inf2.layout.bitsPerPixel		=	8 * 4;
	inf2.layout.bytesPerRow			=	4 * dimension.width;
	inf2.colorSpace					=	ColorSpace::deviceRGB();
	inf2.bitmapInfo.alphaInfo		=	Image::ALPHA_INFO::LAST;
	inf2.bitmapInfo.floatComponents	=	false;
	inf2.bitmapInfo.byteOrder		=	Image::BYTE_ORDER_INFO::DEFAULT;
	inf2.decode						=	nullptr;
	inf2.shouldInterpolate			=	false;
	inf2.renderingIntent			=	ColorSpace::RENDERING_INTENT::DEFAULT;
	
	return	inf2;
}














namespace
{
	static inline auto
	_to_cg(Image::BitmapInfo const& info) -> CGBitmapInfo
	{
		CGBitmapInfo	v	=	CGBitmapInfo(info.alphaInfo) | CGBitmapInfo(info.byteOrder);
		
		if (info.floatComponents)
		{
			v	|=	kCGBitmapFloatComponents;
		}
		
		return	v;
	}
	static inline auto
	_to_ee(CGBitmapInfo const& info) -> Image::BitmapInfo
	{
		CGBitmapInfo		alpha_ch		=	info & kCGBitmapAlphaInfoMask;
		CGBitmapInfo		byte_order		=	info & kCGBitmapByteOrderMask;
		
		Image::BitmapInfo	inf1	{};
		inf1.floatComponents	=	(info & kCGBitmapFloatComponents) == kCGBitmapFloatComponents;
		inf1.alphaInfo			=	Image::ALPHA_INFO(alpha_ch);
		inf1.byteOrder			=	Image::BYTE_ORDER_INFO(byte_order);
		
		return	inf1;
	}
	
	static inline auto
	_makeup(Image::Metadata const& info, DataProvider& content) -> CGImageRef
	{
		CGColorRenderingIntent	rend_intent	=	CGColorRenderingIntent(info.renderingIntent);
		return	CGImageCreate(info.dimension.width, info.dimension.height, info.layout.bitsPerComponent, info.layout.bitsPerPixel, info.layout.bytesPerRow, info.colorSpace, _to_cg(info.bitmapInfo), content, info.decode, info.shouldInterpolate, rend_intent);
	}
}

Image::Image(Metadata const& info, DataProvider& content) : Type(_makeup(info, content))
{
	
}


auto
Image::copy() const -> Image
{
	return	CGImageCreateCopy(*this);
}

auto
Image::width() const -> size_t
{
	return	CGImageGetWidth(*this);
}
auto
Image::height() const -> size_t
{
	return	CGImageGetHeight(*this);
}

auto
Image::bitsPerComponent() const -> size_t
{
	return	CGImageGetBitsPerComponent(*this);
}
auto
Image::bitsPerPixel() const -> size_t
{
	return	CGImageGetBitsPerPixel(*this);
}
auto
Image::bytesPerRow() const -> size_t
{
	return	CGImageGetBytesPerRow(*this);
}

auto
Image::isMask() const -> bool
{
	return	CGImageIsMask(*this);
}
auto
Image::shouldInterpolate() const -> bool
{
	return	CGImageGetShouldInterpolate(*this);
}

auto
Image::dataProvider() const -> DataProvider
{
	return	CGImageGetDataProvider(*this);
}
auto
Image::colorSpace() const -> ColorSpace
{
	return	CGImageGetColorSpace(*this);
}






auto
Image::metadata() const -> Metadata
{
	Metadata		inf3	{};
	
	inf3.dimension.width			=	width();
	inf3.dimension.height			=	height();
	inf3.layout.bitsPerComponent	=	bitsPerComponent();
	inf3.layout.bitsPerPixel		=	bitsPerPixel();
	inf3.layout.bytesPerRow			=	bytesPerRow();
	inf3.colorSpace					=	colorSpace();
	inf3.bitmapInfo					=	_to_ee(CGImageGetBitmapInfo(*this));
	inf3.decode						=	CGImageGetDecode(*this);
	inf3.shouldInterpolate			=	shouldInterpolate();
	inf3.renderingIntent			=	ColorSpace::RENDERING_INTENT(CGImageGetRenderingIntent(*this));
	
	return	inf3;
}






EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END
