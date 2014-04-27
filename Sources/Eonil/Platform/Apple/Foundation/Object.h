//
//  Object.h
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../ObjectiveC/Any.h"
#include "../ObjectiveC/None.h"

EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN






///*!
// Virtual Objective-C semantic object.
// */
//class
//Semantic
//{
//public:
//	Semantic(Semantic const&);
//	
//	auto	operator==(Semantic) const -> bool;
//	auto	operator!=(Semantic) const -> bool;
//};





class
Object : public Any
{
public:
	using	Any::Any;
//	Object(id);
	
public:
	static auto	object() -> Object;
};


//class
//Copying : virtual public Any
//{
//public:
//	NoCopy() = default;
//	NoCopy(NoCopy const&) = delete;
//	virtual ~NoCopy() = default;
//	
//	virtual auto	copy() const -> Any = delete;
//};







EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END