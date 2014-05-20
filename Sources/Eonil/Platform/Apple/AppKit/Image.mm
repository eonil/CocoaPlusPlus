//
//  Image.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Image.h"
#include "../CoreGraphics/Rect.h"
#include "../CoreGraphics/Image.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN




auto
Image::imageWithSize(Size o) -> Image
{
	return	[[NSImage alloc] initWithSize:o];
}

auto
Image::image(CoreGraphics::Image image) -> Image
{
	return	[[NSImage alloc] initWithCGImage:image size:CGSizeZero];
}












EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
