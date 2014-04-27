//
//  Data.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/24.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../CoreFoundation/Type.h"

EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_BEGIN




class
Data : public CoreFoundation::Type
{
public:
	using	Type::Type;
	
	Data(CFDataRef);
	
public:
	operator CFDataRef() const;
	
public:
	auto	length() const -> Index;
	auto	bytePtr() const -> UInt8 const*;
	
public:
	auto	mutableCopy() const -> MutableData;
};





class
MutableData : public Data
{
public:
	MutableData(CFMutableDataRef);
	
	operator CFMutableDataRef() const;
	
public:
	auto	mutableBytePtr() -> UInt8*;
	auto	setLength(Index) -> void;
	
public:
	static auto	mutableData() -> MutableData;
//	static auto	mutableDataWithCapacity(Index capacity) -> MutableData;
	static auto	mutableCopy(Data, Index capacity) -> MutableData;
};









EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_END
