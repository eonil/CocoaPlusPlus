//
//  String.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "String.h"

EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN

static_assert(std::is_same<String::UNICHAR, unichar>::value, "Objective-C `unichar` must be same with String::UNICHAR type.");








String::operator __unsafe_unretained id() const
{
	return	get_objc_object<NSString>();
}









String::String(char const* utf8string) : Object([NSString stringWithUTF8String:utf8string])
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
String::withUTF8String(char const* o) -> String
{
	return	String{[NSString stringWithUTF8String:o]};
}









EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END