//
//  Data.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/24.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Data.h"

EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_BEGIN









Data::Data(CFDataRef o) : Type(o)
{
}

Data::operator CFDataRef() const
{
	return	(CFDataRef)operator CFTypeRef();
}

auto
Data::length() const -> Index
{
	return	CFDataGetLength(*this);
}
auto
Data::bytePtr() const -> UInt8 const*
{
	return	CFDataGetBytePtr(*this);
}

auto
Data::mutableCopy() const -> MutableData
{
	return	MutableData::mutableCopy(*this, length());
}

















MutableData::MutableData(CFMutableDataRef o) : Data(o)
{
}

MutableData::operator CFMutableDataRef() const
{
	return	(CFMutableDataRef)operator CFTypeRef();
}

auto
MutableData::mutableBytePtr() -> UInt8*
{
	return	CFDataGetMutableBytePtr(*this);
}
auto
MutableData::setLength(Index o) -> void
{
	CFDataSetLength(*this, o);
}

auto
MutableData::mutableData() -> MutableData
{
	return	CFDataCreateMutable(NULL, 0);
}
//auto
//MutableData::mutableDataWithCapacity(Index capacity) -> MutableData
//{
//	return	CFDataCreateMutable(NULL, capacity);
//}
auto
MutableData::mutableCopy(Eonil::CocoaCPP::CoreFoundation::Data o, Index capacity) -> MutableData
{
	return	CFDataCreateMutableCopy(NULL, capacity, o);
}







EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_END
