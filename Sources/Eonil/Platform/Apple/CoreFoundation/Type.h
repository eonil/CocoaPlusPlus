//
//  Type.h
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"

EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_BEGIN








/*!
 Provides `CFType` features.
 
 @discussion
 Represents CoreFoundation object type.
 */
class
Type
{
public:
	Type() = delete;
	Type(Type const&);
	Type(Type&&);
	~Type();
	
	Type(std::nullptr_t);
	Type(CFTypeRef);
	
public:
	auto	operator=(Type const&) -> Type&;
	auto	operator=(Type&&) -> Type&;
	
	auto	operator==(std::nullptr_t) const -> bool;
	auto	operator!=(std::nullptr_t) const -> bool;
	
public:
	operator	CFTypeRef() const;
	
protected:
	
private:
	CFTypeRef	_cftype		{NULL};
};




























//
///*!
// Provides `CFType` features.
// */
//class
//Type
//{
//public:
//	Type() = delete;
//	Type(std::nullptr_t);
//	Type(Type&&);
//	Type(CFTypeRef);
//	virtual ~Type();
//
//	Type(Type const&) = delete;			//!	Generic copy is not allowed.
//
//public:
//	auto	operator==(std::nullptr_t) const -> bool;
//	auto	operator!=(std::nullptr_t) const -> bool;
//
//	auto	operator=(Type&&) -> Type&;
//
//public:
//	operator	CFTypeRef();
//
//private:
//	CFTypeRef	_cftype		{NULL};
//};



EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_END
