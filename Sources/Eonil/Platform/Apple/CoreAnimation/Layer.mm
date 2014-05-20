//
//  Layer.cpp
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Layer.h"
#include "../CoreGraphics/Rect.h"
#include "../CoreGraphics/Color.h"

EONIL_PLATFORM_APPLE_CORE_ANIMATION_NAMESPACE_BEGIN




//struct
//Layer::Extras
//{
//	CoreGraphics::Color		_bg_color		{nullptr};
//};
//
//auto
//Layer::backgroundColor() const -> CoreGraphics::Color const&
//{
//	auto	self		=	get_objc_object<CALayer>();
//	
//	_extras->_bg_color	=	[self backgroundColor];
//	
//	return	_extras->_bg_color;
//}
//auto
//Layer::setBackgroundColor(CoreGraphics::Color &&o) -> void
//{
//	_extras->_bg_color	=	std::move(o);
//	
//	////
//	
//	auto	self	=	get_objc_object<CALayer>();
//	
//	[self setBackgroundColor:_extras->_bg_color];
//}



auto
Layer::layer() -> Layer
{
	return	{[[CALayer alloc] init]};
}

auto
Layer::frame() const -> CoreGraphics::Rect
{
	auto	self	=	get_objc_object<CALayer>();
	return	[self frame];
}
auto
Layer::setFrame(CoreGraphics::Rect o) -> void
{
	auto	self	=	get_objc_object<CALayer>();
	[self setFrame:o];
}

auto
Layer::backgroundColor() const -> CoreGraphics::Color
{
	auto	self	=	get_objc_object<CALayer>();
	return	[self backgroundColor];
}
auto
Layer::setBackgroundColor(CoreGraphics::Color o) -> void
{
	auto	self	=	get_objc_object<CALayer>();
	[self setBackgroundColor:o];
}




EONIL_PLATFORM_APPLE_CORE_ANIMATION_NAMESPACE_END
