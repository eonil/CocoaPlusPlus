//
//  Rect.h
//  CocoaTouch++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"

EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN







class
Point
{
	CGPoint		_cgpoint		=	CGPointZero;
	
public:
	Point() = default;
	
	Point(Float const x, Float const y);
	Point(CGPoint const);
	
	operator	CGPoint() const;
	
	auto		x() const -> Float;
	auto		setX(Float) -> void;
	
	auto		y() const -> Float;
	auto		setY(Float) -> void;
	
};

class
Size
{
	CGSize		_cgsize			=	CGSizeZero;
	
public:
	Size(Float const width, Float const height);
	Size(CGSize const);
	
	operator	CGSize() const;
	
	auto		width() const -> Float;
	auto		setWidth(Float) -> void;
	
	auto		height() const -> Float;
	auto		setHeight(Float) -> void;
};

class
Rect
{
	CGRect		_cgrect			=	CGRectZero;
	
public:
	Rect();
	Rect(Point const pt, Size const sz);
	Rect(Float const x, Float const y, Float const width, Float const height);
	Rect(CGRect const);
	
	auto	origin() const -> Point;
	auto	size() const -> Size;
	
	operator	CGRect() const;
};


















EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END
