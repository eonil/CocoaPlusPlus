//
//  Date.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/28.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Date.h"
#include "String.h"
#include "../ObjectiveC/InternalRawStuffs/ErrorCheck.h"
EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN

using namespace	Platform::Debugging;



Date::operator __unsafe_unretained id() const
{
	if (USE_EXCEPTION_CHECKINGS)
	{
		InternalRawStuffs::ErrorCheck::crash_if_not_a_kind_of_class<NSDate>(*this);
	}
	
	////
	
	return	Object::operator __unsafe_unretained id();
}







auto
Date::equals(Eonil::CocoaCPP::Foundation::Date o) const -> bool
{
	auto	self	=	get_objc_object<NSDate>();
	return	[self isEqualToDate:o];
}
auto
Date::copy() const -> Date
{
	auto	self	=	get_objc_object<NSDate>();
	return	[self copy];
}
auto
Date::timeIntervalSince1970() const -> TimeInterval
{
	auto	self	=	get_objc_object<NSDate>();
	return	[self timeIntervalSince1970];
}




auto
Date::dateOfNow() -> Date
{
	return	[[NSDate alloc] init];
}
auto
Date::dateWithString(Eonil::CocoaCPP::Foundation::String expression) -> Date
{
	return	[[NSDate alloc] initWithString:expression];
}









EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END
