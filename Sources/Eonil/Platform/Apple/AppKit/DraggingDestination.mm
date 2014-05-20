//
//  DraggingDestination.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "DraggingDestination.h"
#include "Pasteboard.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN





auto
DraggingInfo::draggingPasteboard() const -> Pasteboard
{
	id		self	=	*this;
	return	[self draggingPasteboard];
}
auto
DraggingInfo::draggingSource() const -> Any
{
	id		self	=	*this;
	return	[self draggingSource];
}









DraggingDestination::~DraggingDestination()
{
}




EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
