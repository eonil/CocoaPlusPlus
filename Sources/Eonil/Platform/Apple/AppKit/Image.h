//
//  Image.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../Foundation/Object.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN






class
Image : public Foundation::Object
{
public:
	using	Object::Object;
	
public:
	static auto	imageWithSize(Size) -> Image;
	static auto	image(CoreGraphics::Image) -> Image;
};










EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END