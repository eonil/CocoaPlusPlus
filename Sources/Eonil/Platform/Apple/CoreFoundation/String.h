//
//  String.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/24.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../CoreFoundation/Type.h"

EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_BEGIN




class
String : public CoreFoundation::Type
{
public:
	using	Type::Type;
	
	String(CFStringRef);
	
public:
	operator CFStringRef() const;
	
public:
	auto	cStringPtr() const -> char const*;
//	auto	cppString() const -> str;			//!	Returns a copy.
};















EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_END
