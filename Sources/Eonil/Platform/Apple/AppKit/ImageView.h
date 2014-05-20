//
//  ImageView.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "Control.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN





/*!
 @note
 `NSImageView` registers itself as a dragging destination by default.
 This class removes the behavior, to become just like any other plain views.
 If you want to make it droppable for images, register these types.
 
	[NSImage imagePasteboardTypes]
 
 */
class
ImageView : public Control
{
public:
	using	Control::Control;
	
public:
	static auto	imageView() -> ImageView;
	
public:
	auto	image() const -> Image;
	auto	setImage(Image) -> void;
};








EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
