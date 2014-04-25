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
	using	Object::Object;
	
	operator __unsafe_unretained id() const;
	
public:
	String(char const* utf8String);								//!	This copies the string.
	
	auto	UTF8String() const -> char const*;
	
public:
	static auto		withUTF8String(char const*) -> String;
};










EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END