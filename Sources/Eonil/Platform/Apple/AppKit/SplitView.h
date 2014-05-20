//
//  SplitView.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "View.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN








class
SplitView : public View
{
public:
	using	View::View;
	
public:
	enum class	DIVIDER_ORIENTATION : bool;
	enum class	DIVIDER_STYLE : Integer;
	
//	static auto splitView() -> SplitView;
	static auto splitView(DIVIDER_ORIENTATION, DIVIDER_STYLE) -> SplitView;
	
public:
	
	enum class
	DIVIDER_ORIENTATION : bool
	{
		HORIZONTAL	=	false,
		VERTICAL	=	true,
	};
	
	enum class
	DIVIDER_STYLE : Integer
	{
		THICK			=	1,
		THIN			=	2,
		PANE_SPLITTER	=	3,
	};
	
	struct
	Delegate : Any
	{
		virtual auto	splitViewResizeSubviewsWithOldSize(SplitView, Size const& oldsize) -> void		{}
	};
	
	auto	delegate() const -> Delegate*;
	auto	setDelegate(Delegate*) -> void;
	auto	unsetDelegate() -> void;
	
	////
	
	auto	adjustSubviews() -> void;
	auto	isSubviewCollapsed(View) const -> bool;
	
	auto	dividerOrientation() const -> DIVIDER_ORIENTATION;
	auto	setDividerOrientation(DIVIDER_ORIENTATION) -> void;
	
	auto	dividerStyle() const -> DIVIDER_STYLE;
	auto	setDividerStyle(DIVIDER_STYLE) -> void;
	
	auto	dividerThickness() const -> Float;
	auto	dividerColor() const -> Color;
	
	auto	setPositionOfDividerAtIndex(Integer const index, Float const position) -> void;
};








EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END

