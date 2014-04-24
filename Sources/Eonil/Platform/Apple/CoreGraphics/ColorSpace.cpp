//
//  ColorSpace.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/24.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "ColorSpace.h"
#include "../CoreFoundation/String.h"

EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN








ColorSpace::ColorSpace(CGColorSpaceRef o) : Type(o)
{
}

ColorSpace::operator CGColorSpaceRef() const
{
	return	(CGColorSpaceRef)operator CFTypeRef();
}



auto
ColorSpace::name() const -> CoreFoundation::String
{
	return	CGColorSpaceCopyName(*this);
}
auto
ColorSpace::model() const -> MODEL
{
	return	MODEL(CGColorSpaceGetModel(*this));
}





auto
ColorSpace::calibratedGray(const Float *whitePoint, const Float *blackPoint, Float gamma) -> ColorSpace
{
	return	CGColorSpaceCreateCalibratedGray(whitePoint, blackPoint, gamma);
}
auto
ColorSpace::calibratedRGB(const Float *whitePoint, const Float *blackPoint, Float const* gamma, const Float *matrix) -> ColorSpace
{
	return	CGColorSpaceCreateCalibratedRGB(whitePoint, blackPoint, gamma, matrix);
}

auto
ColorSpace::deviceGray() -> ColorSpace
{
	return	CGColorSpaceCreateDeviceGray();
}
auto
ColorSpace::deviceRGB() -> ColorSpace
{
	return	CGColorSpaceCreateDeviceRGB();
}






EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END
