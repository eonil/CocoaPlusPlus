//
//  Color.h
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../CoreFoundation/Type.h"

EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN




class
Color : CoreFoundation::Type
{
public:
	using	Type::Type;
	
	Color(CGColorRef);
	
public:
	operator CGColorRef();
};















EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END