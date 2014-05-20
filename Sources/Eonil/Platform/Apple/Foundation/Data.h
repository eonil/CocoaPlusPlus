//
//  Data.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../Foundation/Object.h"

EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN





/*!
 Wraps `NSData`.
 */
class
Data : protected Object
{
public:
	using	Object::Object;
	
	operator __unsafe_unretained id() const;
	
public:
	auto	equals(Data) const -> bool;
	auto	copy() const -> Data;
	
	auto	writeToURLAtomically(URL) const -> bool;
	
public:
	static auto		dataWithBytes(void const* bytes, UInteger length) -> Data;			//!	Memory content will be copied.
};










EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END
