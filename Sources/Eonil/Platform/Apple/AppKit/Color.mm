//
//  Color.cpp
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Color.h"
#include "../CoreGraphics/Color.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN









auto
Color::color(Eonil::CocoaCPP::AppKit::Color::Components const& cs) -> Color
{
	return	{[NSColor colorWithDeviceRed:cs.red green:cs.green blue:cs.blue alpha:cs.alpha]};
}

auto
Color::components() const -> Components
{
	auto	self	=	get_objc_object<NSColor>();
	
	Components	cs	{};
	[self getRed:&cs.red green:&cs.green blue:&cs.blue alpha:&cs.alpha];
	return	cs;
}

auto
Color::CGColor() const -> CoreGraphics::Color
{
	auto	self	=	get_objc_object<NSColor>();

	return	CoreGraphics::Color([self CGColor]);
}









EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END