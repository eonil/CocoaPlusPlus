//
//  Date.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/28.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../Foundation/Object.h"

EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN





/*!
 Wraps `NSDate`.
 */
class
Date final : protected Object
{
public:
	using	Object::Object;
	
	operator __unsafe_unretained id() const;
	
public:
	
	auto	equals(Date) const -> bool;
	auto	copy() const -> Date;
	
	/*!
	 This returns Unix timestamp (seconds since 00:00:00 UTC January 1, 1970) in `double` type.
	 Cast this into `time_t` with proper value range test.
	 */
	auto	timeIntervalSince1970() const -> TimeInterval;
	
public:
	static auto		dateOfNow() -> Date;
	static auto		dateWithString(String expression) -> Date;
};










EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END
