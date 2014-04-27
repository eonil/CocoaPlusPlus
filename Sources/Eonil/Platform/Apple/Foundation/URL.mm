//
//  URL.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "URL.h"
#include "String.h"

EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN




URL::operator __unsafe_unretained id() const
{
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
	return	[NSURL URLWithString:o];
}











EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END