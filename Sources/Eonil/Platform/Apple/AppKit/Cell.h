//
//  Cell.h
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "Common.h"
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN






class
Cell : public Object
{
	using	BASE	=	Object;
protected:
	using	BASE::BASE;
	
public:
	auto	stringValue() const -> String;
	auto	setStringValue(String const&) -> void;
};





class
ActionCell : public Cell
{
	using	BASE	=	Cell;
protected:
	using	BASE::BASE;
};





class
TextFieldCell : public ActionCell
{
	using	BASE	=	ActionCell;
protected:
	using	BASE::BASE;
};





class
TableHeaderCell final : public TextFieldCell
{
	using	BASE	=	TextFieldCell;
public:
	using	BASE::BASE;
	
public:
	TableHeaderCell();
};








EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
