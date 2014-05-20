//
//  Color.cpp
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Color.h"

EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN









Color::Color(CGColorRef o) : Type(o)
{
}

Color::operator CGColorRef()
{
	return	(CGColorRef)operator CFTypeRef();
}









EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END
