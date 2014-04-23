//
//  View.h
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "Common.h"
#include "Object.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN






class
View : public Object
{
public:
	static auto	view() -> View;
	
public:
	using	Object::Object;
	
public:
	auto	frame() const -> Rect;
	auto	setFrame(Rect) -> void;
	
	auto	addSubview(View) -> void;
	auto	removeFromSuperview() -> void;
	
	auto	wantsLayer() const -> bool;
	auto	setWantsLayer(bool) -> void;
	
	auto	layer() const -> CoreAnimation::Layer;
	auto	setLayer(CoreAnimation::Layer) -> void;
};




/*!
 If you want to override some methods of a view, you should use this class.
 */
class
OverridableView : public View
{
public:
	struct
	Behaviors
	{
		virtual auto	didMoveToSuperview() -> void	{}
	};
	
protected:
	OverridableView(uptr<Behaviors>&& overriding);
};










EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END