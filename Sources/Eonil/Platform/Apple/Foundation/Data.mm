//
//  Data.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Data.h"

EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN









Data::operator __unsafe_unretained id() const
{
	return	get_objc_object<NSData>();
}

















EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END