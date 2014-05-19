//
//  URL.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "URL.h"
#include "String.h"
#include "../ObjectiveC/InternalRawStuffs/ErrorCheck.h"
EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN

using namespace	Platform::Debugging;






URL::operator __unsafe_unretained id() const
{
	if (USE_EXCEPTION_CHECKINGS)
	{
		InternalRawStuffs::ErrorCheck::crash_if_not_a_kind_of_class<NSData>(*this);
	}
	
	////
	
	return	Object::operator __unsafe_unretained id();
}




auto
URL::equals(URL o) const -> bool
{
	auto	self	=	get_objc_object<NSURL>();
	return	toCPP([self isEqual:o]);
}
auto
URL::copy() const -> URL
{
	auto	self	=	get_objc_object<NSURL>();
	return	[self copy];
}

auto
URL::path() const -> String
{
	auto	self	=	get_objc_object<NSURL>();
	return	[self path];
}

auto
URL::urlWithString(Eonil::CocoaCPP::Foundation::String o) -> URL
{
	return	[[NSURL alloc] initWithString:o];
}











EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END