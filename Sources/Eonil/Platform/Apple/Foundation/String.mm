//
//  String.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "String.h"
#include "../ObjectiveC/InternalRawStuffs/ErrorCheck.h"
EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN

using namespace	Platform::Debugging;
static_assert(std::is_same<String::UNICHAR, unichar>::value, "Objective-C `unichar` must be same with String::UNICHAR type.");








String::operator __unsafe_unretained id() const
{
	if (USE_EXCEPTION_CHECKINGS)
	{
		InternalRawStuffs::ErrorCheck::crash_if_not_a_kind_of_class<NSString>(*this);
	}
	
	////
	
	return	get_objc_object<NSString>();
}









String::String(char const* utf8string) : Object([NSString stringWithUTF8String:utf8string])
{
}
String::String(std::string const& utf8string) : String(utf8string.c_str())
{
}


auto
String::equals(Eonil::CocoaCPP::Foundation::String o) const -> bool
{
	id	o1	=	*this;
	return	[o1 isEqualToString:o];
}
auto
String::copy() const -> String
{
	id	o1	=	*this;
	return	[o1 copy];
}

auto
String::UTF8String() const -> char const*
{
	auto	self	=	get_objc_object<NSString>();
	return	[self UTF8String];
}









auto
String::length() const -> UInteger
{
	auto	self	=	get_objc_object<NSString>();
	return	[self length];
}
auto
String::characterAtIndex(UInteger o) const -> UNICHAR
{
	auto	self	=	get_objc_object<NSString>();
	return	[self characterAtIndex:o];
}
auto
String::hasPrefix(Eonil::CocoaCPP::Foundation::String o) const -> bool
{
	auto	self	=	get_objc_object<NSString>();
	return	[self hasPrefix:o];
}
auto
String::hasSuffix(Eonil::CocoaCPP::Foundation::String o) const -> bool
{
	auto	self	=	get_objc_object<NSString>();
	return	[self hasSuffix:o];
}
auto
String::stringByAppendingString(Eonil::CocoaCPP::Foundation::String o) const -> String
{
	auto	self	=	get_objc_object<NSString>();
	return	[self stringByAppendingString:o];
}
auto
String::stringByAppendingPathComponent(Eonil::CocoaCPP::Foundation::String o) const -> String
{
	auto	self	=	get_objc_object<NSString>();
	return	[self stringByAppendingPathComponent:o];
}
auto
String::substringFromIndex(UInteger o) const -> String
{
	auto	self	=	get_objc_object<NSString>();
	return	[self substringFromIndex:o];
}
auto
String::substringToIndex(UInteger o) const -> String
{
	auto	self	=	get_objc_object<NSString>();
	return	[self substringToIndex:o];
}













auto
String::stringWithUTF8String(char const* o) -> String
{
	return	String{[[NSString alloc] initWithUTF8String:o]};
}
auto
String::stringWithUTF8String(std::string const& o) -> String
{
	return	stringWithUTF8String(o.c_str());
}









EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END