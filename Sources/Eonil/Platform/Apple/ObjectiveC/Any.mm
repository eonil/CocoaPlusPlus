//
//  Any.cpp
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Any.h"

EONIL_PLATFORM_APPLE_NAMESPACE_BEGIN





Any::Any(std::nullptr_t) : _objc_object_ptr(nil)
{
}
Any::Any(__unsafe_unretained id o) : _objc_object_ptr(o)
{
	
}

Any::operator __unsafe_unretained id() const
{
	return	_objc_object_ptr;
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