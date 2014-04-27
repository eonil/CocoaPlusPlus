//
//  String.h
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
 Wraps `NSString`.
 */
class
String : protected Object
{
public:
	using	UNICHAR		=	uint16_t;
	
public:
	using	Object::Object;
	
	operator __unsafe_unretained id() const;
	
public:
	String(char const* utf8String);								//!	This copies the string.
	
	auto	equals(String) const -> bool;
	auto	copy() const -> String;
	
	auto	UTF8String() const -> char const*;					
	
public:
	auto	length() const -> UInteger;
	auto	characterAtIndex(UInteger) const -> UNICHAR;
	auto	hasPrefix(String) const -> bool;
	auto	hasSuffix(String) const -> bool;
	auto	stringByAppendingString(String) const -> String;
	auto	substringFromIndex(UInteger) const -> String;
	auto	substringToIndex(UInteger) const -> String;
	
public:
	static auto		stringWithUTF8String(char const*) -> String;
};










EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END