//
//  Common.h
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once

#define EONIL_PLATFORM_APPLE_NAMESPACE_BEGIN						namespace Eonil { namespace CocoaCPP {
#define EONIL_PLATFORM_APPLE_NAMESPACE_END							} }

#define EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_BEGIN		namespace Eonil { namespace CocoaCPP { namespace CoreFoundation {
#define EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_END			} } }

#define EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN			namespace Eonil { namespace CocoaCPP { namespace CoreGraphics {
#define EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END			} } }

#define EONIL_PLATFORM_APPLE_CORE_ANIMATION_NAMESPACE_BEGIN			namespace Eonil { namespace CocoaCPP { namespace CoreAnimation {
#define EONIL_PLATFORM_APPLE_CORE_ANIMATION_NAMESPACE_END			} } }

#define EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN				namespace Eonil { namespace CocoaCPP { namespace Foundation {
#define EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END				} } }

#define EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN					namespace Eonil { namespace CocoaCPP { namespace AppKit {
#define EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END					} } }

#define EONIL_PLATFORM_APPLE_UIKIT_NAMESPACE_BEGIN					namespace Eonil { namespace CocoaCPP { namespace UIKit {
#define EONIL_PLATFORM_APPLE_UIKIT_NAMESPACE_END					} } }



#ifdef __cplusplus
#include <memory>
#include <functional>
#include <set>
#include <vector>
#endif

#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>
#include <ImageIO/ImageIO.h>
#include <CoreServices/CoreServices.h>
#include <objc/NSObjCRuntime.h>

#ifdef __OBJC__
#import	<Cocoa/Cocoa.h>
#endif

#include "../Debugging/Exception.h"
















#ifdef __cplusplus

EONIL_PLATFORM_APPLE_NAMESPACE_BEGIN

using	Integer		=	NSInteger;
using	UInteger	=	NSUInteger;
UInteger const	UIntegerMax	=	NSUIntegerMax;

template <typename T>	using	uptr	=	std::unique_ptr<T>;
template <typename T>	using	sptr	=	std::shared_ptr<T>;
template <typename T>	using	set		=	std::set<T>;
template <typename T>	using	vec		=	std::vector<T>;

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
#else
#define	EONIL_COCOA_ASSERT_OBJC_TYPE(object,type)
#define	EONIL_COCOA_ASSERT_OBJC_TYPE_OR_NIL(object,type)
#endif





#ifdef __OBJC__

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
using	Index	=	CFIndex;
class	Type;
class	Data;
class	MutableData;
class	String;
EONIL_PLATFORM_APPLE_CORE_FOUNDATION_NAMESPACE_END

EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN
using	Float		=	CGFloat;
class	Point;
class	Size;
class	Rect;
class	Color;
class	ColorSpace;
class	DataProvider;
class	Image;
class	ImageDestination;
EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END

EONIL_PLATFORM_APPLE_CORE_ANIMATION_NAMESPACE_BEGIN
class	Layer;
EONIL_PLATFORM_APPLE_CORE_ANIMATION_NAMESPACE_END

EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_BEGIN
class	Object;
class	String;
class	Data;
class	AnytypeArray;
template <typename T>	class	SpecificTypeArray;
class	URL;
class	Date;
using	TimeInterval	=	double;
EONIL_PLATFORM_APPLE_FOUNDATION_NAMESPACE_END

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN
class	Color;
class	Image;
class	View;
class	Control;
class	ImageView;
class	Window;
class	WindowController;
using	Float		=	CoreGraphics::Float;
using	Size		=	CoreGraphics::Size;
using	Rect		=	CoreGraphics::Rect;
class	Pasteboard;
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END

#endif
