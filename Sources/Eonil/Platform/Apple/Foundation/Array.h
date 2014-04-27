//
//  Array.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../Foundation/Object.h"

EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN





/*!
 Wraps `NSArray`.
 */
class
AnytypeArray : protected Object
{
public:
	using	Object::Object;
	
	operator __unsafe_unretained id() const;
	
public:
	AnytypeArray(vec<Any> const& objects);
	
	auto	equals(AnytypeArray) const -> bool;
	auto	copy() const -> AnytypeArray;
	
	auto	vector() const -> vec<Any>;
};



/*!
 Provides type-specialization for `AnytypeArray`.
 */
template <typename T>
class
SpecificTypeArray : public AnytypeArray
{
public:
	using	AnytypeArray::AnytypeArray;
	
public:
	SpecificTypeArray(vec<T> const& objects) : AnytypeArray(static_cast<vec<Any> const&>(objects))
	{
	}
	
	auto
	equals(SpecificTypeArray o) const -> bool
	{
		return	AnytypeArray::equals(o);
	}
	auto
	copy() const -> SpecificTypeArray
	{
		return	AnytypeArray::copy();
	}
	
	auto
	vector() const -> vec<T>
	{
		vec<Any>	a1	{AnytypeArray::vector()};
		vec<T>		a2	{};
		a2.reserve(a1.size());
		for (Any o1: a1)
		{
			T	o2	=	(id)o1;
			a2.push_back(o2);
		}
		return	a2;
	}
};









EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END