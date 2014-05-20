//
//  Any.cpp
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Any.h"
#include "../ObjectiveC/InternalRawStuffs/ErrorCheck.h"
#include <objc/runtime.h>
EONIL_PLATFORM_APPLE_NAMESPACE_BEGIN





Any::Any(std::nullptr_t) : _objc_object_ptr(nil)
{
}
Any::Any(__unsafe_unretained id o) : _objc_object_ptr(o)
{
	[_objc_object_ptr retain];
}
Any::~Any()
{
	[_objc_object_ptr release];
	_objc_object_ptr	=	nil;
}

Any::operator __unsafe_unretained id() const
{
	return	_objc_object_ptr;
}





Any::Any(Any const& o) : _objc_object_ptr(o._objc_object_ptr)
{
	[_objc_object_ptr retain];
}
Any::Any(Any&& o) : _objc_object_ptr(o._objc_object_ptr)
{
	o._objc_object_ptr	=	nil;
}

auto
Any::operator=(const Eonil::CocoaCPP::Any &o) -> Any&
{
	/*
	 Retain first to be safe on self-assignment situation.
	 */
	
	[o._objc_object_ptr retain];
	[_objc_object_ptr release];
	
	_objc_object_ptr	=	o._objc_object_ptr;
	
	return	*this;
}
auto
Any::operator=(Eonil::CocoaCPP::Any &&o) -> Any&
{
	/*
	 No need to change ref-count if two objects are same.
	 */
	
	if (_objc_object_ptr != o._objc_object_ptr)
	{
		[_objc_object_ptr release];
	}
	
	_objc_object_ptr	=	o._objc_object_ptr;
	o._objc_object_ptr	=	nil;

	return	*this;
}







//auto
//Any::copy() const -> Any
//{
//	return	Any([_objc_object_ptr copy]);
//}
//auto
//Any::operator==(const Any &o) const -> bool
//{
//	return	toCPP([_objc_object_ptr isEqual:o._objc_object_ptr]);
//}
//auto
//Any::operator!=(const Any &o) const -> bool
//{
//	return	not toCPP([_objc_object_ptr isEqual:o._objc_object_ptr]);
//}






EONIL_PLATFORM_APPLE_NAMESPACE_END
