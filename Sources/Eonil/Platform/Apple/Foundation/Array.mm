//
//  Array.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Array.h"

EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN









AnytypeArray::operator __unsafe_unretained id() const
{
	return	get_objc_object<NSString>();
}













namespace
{
	static inline auto
	_make(vec<Any> const& objects) -> NSArray*
	{
		vec<id>		v2	{};
		v2.reserve(objects.size());
		for (Any a1 : objects)
		{
			v2.push_back(a1);
		}
		return	[NSArray arrayWithObjects:v2.data() count:objects.size()];
	}
}

AnytypeArray::AnytypeArray(vec<Any> const& objects) : Object(_make(objects))
{
}


auto
AnytypeArray::equals(Eonil::CocoaCPP::Foundation::AnytypeArray o) const -> bool
{
	id	o1	=	*this;
	return	[o1 isEqualToArray:o];
}
auto
AnytypeArray::copy() const -> AnytypeArray
{
	id	o1	=	*this;
	return	[o1 copy];
}

auto
AnytypeArray::vector() const -> vec<Any>
{
	auto	self	=	get_objc_object<NSArray>();
	
	vec<Any>	a1	{};
	a1.reserve([self count]);
	for (id o1 in self)
	{
		a1.push_back(o1);
	}
	return	a1;
}










EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END