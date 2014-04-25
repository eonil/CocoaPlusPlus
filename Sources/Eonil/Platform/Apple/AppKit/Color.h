//
//  Color.h
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../Foundation/Object.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN






class
Color : public Foundation::Object
{
public:
	struct
	Components
	{
		Float	red		{};
		Float	green	{};
		Float	blue	{};
		Float	alpha	{};
		
		Components()
		{
		}
		Components(Float red, Float green, Float blue, Float alpha) : red(red), green(green), blue(blue), alpha(alpha)
		{
		}
	};
	
public:
	static auto	color(Components const&) -> Color;
	
public:
	using	Object::Object;
	
public:
	auto	components() const -> Components;
	auto	CGColor() const -> CoreGraphics::Color;
};











EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END