//
//  Type.cpp
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Type.h"

EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_BEGIN


















Type::Type(std::nullptr_t) : _cftype(NULL)
{
}
Type::Type(Type const& o) : _cftype(o._cftype)
{
	CFRetain(_cftype);
}
Type::Type(Type&& o) : _cftype(o._cftype)
{
	o._cftype	=	NULL;
}
Type::Type(CFTypeRef o) : _cftype(o)
{
	CFRetain(_cftype);
}
Type::~Type()
{
	if (_cftype != NULL)
	{
		CFRelease(_cftype);
		_cftype		=	NULL;
	}
}





auto
Type::operator=(Eonil::CocoaCPP::CoreFoundation::Type const& o) -> Type&
{
	_cftype	=	o._cftype;
	CFRetain(_cftype);
	return	*this;
}
auto
Type::operator=(Eonil::CocoaCPP::CoreFoundation::Type &&o) -> Type&
{
	_cftype		=	o._cftype;
	o._cftype	=	NULL;
	return	*this;
}

auto
Type::operator==(std::nullptr_t) const -> bool
{
	return	_cftype == NULL;
}
auto
Type::operator!=(std::nullptr_t) const -> bool
{
	return	_cftype != NULL;
}




Type::operator CFTypeRef() const
{
	return	_cftype;
}































//Type::Type(std::nullptr_t) : _cftype(NULL)
//{
//}
//Type::Type(Type&& o) : _cftype(o._cftype)
//{
//	o._cftype	=	NULL;
//}
//Type::Type(CFTypeRef o) : _cftype(o)
//{
//	CFRetain(_cftype);
//}
//Type::~Type()
//{
//	CFRelease(_cftype);
//	_cftype		=	NULL;
//}
//
//
//
//
//
//
//auto
//Type::operator==(std::nullptr_t) const -> bool
//{
//	return	_cftype == NULL;
//}
//auto
//Type::operator!=(std::nullptr_t) const -> bool
//{
//	return	_cftype != NULL;
//}
//
//
//
//auto
//Type::operator=(Type&& o) -> Type&
//{
//	/*
//	 No change on ownership.
//	 */
//	_cftype		=	o._cftype;
//	o._cftype	=	NULL;
//	return	*this;
//}
//
//
//
//
//Type::operator CFTypeRef()
//{
//	return	_cftype;
//}










EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_END
