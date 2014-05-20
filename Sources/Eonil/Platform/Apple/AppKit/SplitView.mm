//
//  SplitView.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "SplitView.h"
#include "Color.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN






//auto
//SplitView::splitView() -> SplitView
//{
//	return	[[NSSplitView alloc] init];
//}
auto
SplitView::splitView(Eonil::CocoaCPP::AppKit::SplitView::DIVIDER_ORIENTATION o, Eonil::CocoaCPP::AppKit::SplitView::DIVIDER_STYLE ds) -> SplitView
{
	SplitView	sv1		=	[[NSSplitView alloc] init];
	sv1.setDividerOrientation(o);
	sv1.setDividerStyle(ds);
	return	sv1;
}






auto
SplitView::adjustSubviews() -> void
{
	auto	self	=	get_objc_object<NSSplitView>();
	[self adjustSubviews];
}
auto
SplitView::isSubviewCollapsed(Eonil::CocoaCPP::AppKit::View o) const -> bool
{
	auto	self	=	get_objc_object<NSSplitView>();
	return	toCPP([self isSubviewCollapsed:o]);
}

auto
SplitView::dividerOrientation() const -> DIVIDER_ORIENTATION
{
	auto	self	=	get_objc_object<NSSplitView>();
	BOOL	vert	=	[self isVertical];
	return	DIVIDER_ORIENTATION(toCPP(vert));
}
auto
SplitView::setDividerOrientation(Eonil::CocoaCPP::AppKit::SplitView::DIVIDER_ORIENTATION o) -> void
{
	auto	self	=	get_objc_object<NSSplitView>();
	[self setVertical:toOBJC(bool(o))];
}

auto
SplitView::dividerStyle() const -> DIVIDER_STYLE
{
	auto	self	=	get_objc_object<NSSplitView>();
	return	DIVIDER_STYLE([self dividerStyle]);
}
auto
SplitView::setDividerStyle(Eonil::CocoaCPP::AppKit::SplitView::DIVIDER_STYLE o) -> void
{
	auto	self	=	get_objc_object<NSSplitView>();
	[self setDividerStyle:NSSplitViewDividerStyle(o)];
}

auto
SplitView::dividerThickness() const -> Float
{
	auto	self	=	get_objc_object<NSSplitView>();
	return	[self dividerThickness];
}
auto
SplitView::dividerColor() const -> Color
{
	auto	self	=	get_objc_object<NSSplitView>();
	return	[self dividerColor];
}

auto
SplitView::setPositionOfDividerAtIndex(const Integer index, const Float position) -> void
{
	auto	self	=	get_objc_object<NSSplitView>();
	[self setPosition:position ofDividerAtIndex:index];
}








EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
