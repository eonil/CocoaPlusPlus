//
//  Common.h
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once

#define EONIL_PLATFORM_APPLE_NAMESPACE_BEGIN			namespace Eonil { namespace CocoaCPP {
#define EONIL_PLATFORM_APPLE_NAMESPACE_END			} }

#define EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_BEGIN		namespace Eonil { namespace CocoaCPP { namespace CoreFoundation {
#define EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_END			} } }

#define EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN			namespace Eonil { namespace CocoaCPP { namespace CoreGraphics {
#define EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END			} } }

#define EONIL_PLATFORM_APPLE_CORE_ANIMATION_NAMESPACE_BEGIN			namespace Eonil { namespace CocoaCPP { namespace CoreAnimation {
#define EONIL_PLATFORM_APPLE_CORE_ANIMATION_NAMESPACE_END			} } }

#define EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN					namespace Eonil { namespace CocoaCPP { namespace AppKit {
#define EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END					} } }

#include <memory>
#include <functional>
#include <set>

#import	<CoreFoundation/CoreFoundation.h>
#import <CoreGraphics/CoreGraphics.h>

#ifdef __OBJC__
#import	<Cocoa/Cocoa.h>
#endif





EONIL_PLATFORM_APPLE_NAMESPACE_BEGIN

template <typename T>	using	uptr	=	std::unique_ptr<T>;
template <typename T>	using	sptr	=	std::shared_ptr<T>;
template <typename T>	using	set		=	std::set<T>;

using	PROC	=	std::function<auto() -> void>;


class	Any;
class	Object;

static inline void
EONIL_COCOA_DEBUG_ASSERT(bool cond)
{
	if (not cond)
	{
		std::terminate();
	}
}

#ifdef __OBJC__
#define	EONIL_COCOA_ASSERT_OBJC_TYPE(object,type)				{EONIL_COCOA_DEBUG_ASSERT([object isKindOfClass:[type class]] == YES);}
#define	EONIL_COCOA_ASSERT_OBJC_TYPE_OR_NIL(object,type)		{EONIL_COCOA_DEBUG_ASSERT(object == nil or [object isKindOfClass:[type class]] == YES);}
using	Integer		=	NSInteger;
using	UInteger	=	NSUInteger;
static inline auto
toOBJC(bool o) -> BOOL
{
	return	o ? YES : NO;
}
static inline auto
toCPP(BOOL o) -> bool
{
	return	o ? true : false;
}
#endif

EONIL_PLATFORM_APPLE_NAMESPACE_END






EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_BEGIN
class	Type;
EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_END

EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN
using	Float		=	CGFloat;
class	Point;
class	Size;
class	Rect;
class	Color;
EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END

EONIL_PLATFORM_APPLE_CORE_ANIMATION_NAMESPACE_BEGIN
class	Layer;
EONIL_PLATFORM_APPLE_CORE_ANIMATION_NAMESPACE_END

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN
class	View;
class	Window;
class	WindowController;
using	Float		=	CoreGraphics::Float;
using	Rect		=	CoreGraphics::Rect;
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
