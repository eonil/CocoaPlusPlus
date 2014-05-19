//
//  ErrorCheck.h
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../../Common.h"
#include "../Any.h"
EONIL_PLATFORM_APPLE_NAMESPACE_BEGIN
namespace
InternalRawStuffs
{
	namespace
	ErrorCheck
	{
		using namespace	Platform::Debugging;
		
		
		template <typename OBJC_TYPE>
		inline auto
		crash_if_not_a_kind_of_class(Any anyone) -> void
		{
			id		obj	=	anyone;
			BOOL	ok	=	[obj isKindOfClass:[OBJC_TYPE class]];
			crash_if(not ok, "The object is not expected type.");
		}
		
		
		
		
		
		
		
		
		
	}
}
EONIL_PLATFORM_APPLE_NAMESPACE_END