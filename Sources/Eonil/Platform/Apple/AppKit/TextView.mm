//
//  TextView.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "TextView.h"
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN







auto
TextView::Utility::
textView() -> TextView
{
	return	[[NSTextView alloc] init];
}



EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
