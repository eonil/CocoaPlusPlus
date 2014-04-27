//
//  String.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/24.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "String.h"

EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_BEGIN










String::String(CFStringRef o) : Type(o)
{
}

String::operator CFStringRef() const
{
	return	(CFStringRef)operator CFTypeRef();
}




auto
String::cStringPtr() const -> char const*
{
	return	CFStringGetCStringPtr(*this, kCFStringEncodingUTF8);
}
//auto
//String::CppString() const -> str
//{
//	
//}
	




EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_END
