//
//  Data.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Data.h"
#include "URL.h"
#include "../ObjectiveC/InternalRawStuffs/ErrorCheck.h"
EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN

using namespace	Platform::Debugging;








Data::operator __unsafe_unretained id() const
{
	if (USE_EXCEPTION_CHECKINGS)
	{
		InternalRawStuffs::ErrorCheck::crash_if_not_a_kind_of_class<NSData>(*this);
	}
	
	////
	
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
	return	[[NSData alloc] initWithBytes:bytes length:length];
}








EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END