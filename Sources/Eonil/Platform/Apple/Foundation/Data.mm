//
//  Data.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Data.h"
#include "URL.h"

EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN









Data::operator __unsafe_unretained id() const
{
	return	get_objc_object<NSData>();
}



auto
Data::equals(Eonil::CocoaCPP::Foundation::Data o) const -> bool
{
	id	o1	=	*this;
	return	[o1 isEqualToData:o];
}
auto
Data::copy() const -> Data
{
	id	o1	=	*this;
	return	[o1 copy];
}
auto
Data::writeToURLAtomically(Eonil::CocoaCPP::Foundation::URL o) const -> bool
{
	auto	self	=	get_objc_object<NSData>();
	return	toCPP([self writeToURL:o atomically:YES]);
}





auto
Data::dataWithBytes(const void *bytes, UInteger length) -> Data
{
	return	[NSData dataWithBytes:bytes length:length];
}








EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END