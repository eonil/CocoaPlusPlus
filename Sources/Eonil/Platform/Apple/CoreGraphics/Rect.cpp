//
//  Rect.cpp
//  CocoaTouch++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Rect.h"

EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN



//using namespace	___C_API;




Point::Point(Float const x, Float const y) : _cgpoint(CGPointMake(x, y))
{
}
Point::Point(CGPoint const cgpoint) : _cgpoint(cgpoint)
{
}
Point::operator CGPoint() const
{
	return	_cgpoint;
}
auto
Point::x() const -> Float const
{
	return	_cgpoint.x;
}
auto
Point::setX(Float o) -> void
{
	_cgpoint.x	=	o;
}
auto
Point::y() const -> Float const
{
	return	_cgpoint.y;
}
auto
Point::setY(Float o) -> void
{
	_cgpoint.x	=	o;
}







Size::Size(Float const w, Float const h) : _cgsize(CGSizeMake(w, h))
{
}
Size::Size(CGSize const cgsize) : _cgsize(cgsize)
{
}
Size::operator CGSize() const
{
	return	_cgsize;
}
auto
Size::width() const -> Float const
{
	return	_cgsize.width;
}
auto
Size::setWidth(Float o) -> void
{
	_cgsize.width	=	o;
}
auto
Size::height() const -> Float const
{
	return	_cgsize.height;
}
auto
Size::setHeight(Float o) -> void
{
	_cgsize.height	=	o;
}




Rect::Rect(Point const pt, Size const sz) : _cgrect(CGRectMake(pt.x(), pt.y(), sz.width(), sz.height()))
{
}
Rect::Rect(Float const x, Float const y, Float const width, Float const height) : _cgrect(CGRectMake(x, y, width, height))
{
}
Rect::Rect(CGRect const cgrect) : _cgrect(cgrect)
{
}

Rect::operator CGRect() const
{
	return	_cgrect;
}










EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END
