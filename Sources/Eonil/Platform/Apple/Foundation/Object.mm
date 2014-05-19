//
//  Object.cpp
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Object.h"
#include "../ObjectiveC/InternalRawStuffs/ErrorCheck.h"
EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN






//Object::Object() : Any([[NSObject alloc] init])
//{
//}
//Object::Object(id o) : Any(o)
//{
//}
//Object::Object(Object const&o) : Any(o)
//{
//}
//
//Object::Object(Object&&o) : Any(std::move(o))
//{
//}




auto
Object::object() -> Object
{
	return	Object([[NSObject alloc] init]);
}






EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END