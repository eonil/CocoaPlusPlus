//
//  Layer.h
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../Foundation/Object.h"

EONIL_PLATFORM_APPLE_CORE_ANIMATION_NAMESPACE_BEGIN





/*!
 Wraps `CALayer`.
 */
class
Layer : public Foundation::Object
{
public:
	static auto	layer() -> Layer;
	
public:
	using	Object::Object;

public:
//	auto	backgroundColor() const -> CoreGraphics::Color const&;
//	auto	setBackgroundColor(CoreGraphics::Color&&) -> void;
	
	auto	frame() const -> CoreGraphics::Rect;
	auto	setFrame(CoreGraphics::Rect) -> void;
	
	auto	backgroundColor() const -> CoreGraphics::Color;
	auto	setBackgroundColor(CoreGraphics::Color) -> void;
	
//private:
//	struct			Extras;
//	uptr<Extras>	_extras	{};
//	
//	Layer(
};







EONIL_PLATFORM_APPLE_CORE_ANIMATION_NAMESPACE_END