//
//  Cell.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Cell.h"
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN






auto
Cell::
stringValue() const -> String
{
	auto	self	=	get_objc_object<NSCell>();
	return	[self stringValue];
}
auto
Cell::
setStringValue(const String &o) -> void
{
	auto	self	=	get_objc_object<NSCell>();
	[self setStringValue:o];
}







TableHeaderCell::TableHeaderCell() : BASE([[NSTableHeaderCell alloc] init])
{
}







EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END