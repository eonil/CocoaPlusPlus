//
//  ImageView.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "ImageView.h"
#include "Image.h"





EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN


auto
ImageView::imageView() -> ImageView
{
	auto	self	=	[[NSImageView alloc] init];
	[self unregisterDraggedTypes];
	return	self;
}










auto
ImageView::image() const -> Image
{
	auto	self	=	get_objc_object<NSImageView>();
	return	[self image];
}
auto
ImageView::setImage(Eonil::CocoaCPP::AppKit::Image o) -> void
{
	auto	self	=	get_objc_object<NSImageView>();
	[self setImage:o];
}




EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
