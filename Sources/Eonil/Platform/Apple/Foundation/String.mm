//
//  String.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "String.h"

EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN









String::operator __unsafe_unretained id() const
{
	return	get_objc_object<NSString>();
}









String::String(char const* utf8string) : Object([NSString stringWithUTF8String:utf8string])
{
}

auto
String::UTF8String() const -> char const*
{
	auto	self	=	get_objc_object<NSString>();
	return	[self UTF8String];
}

auto
String::withUTF8String(char const* o) -> String
{
	return	String{[NSString stringWithUTF8String:o]};
}









EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END