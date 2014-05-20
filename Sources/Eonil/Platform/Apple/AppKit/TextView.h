//
//  TextView.h
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "Common.h"
#include "Text.h"
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN




/*!
 @classdesign
 All overriding point will be provided
 
 @note
 Take care that `TextView` needs to be wrapped in a `ScrollView` to be
 spanned over multiple lines.
 */
class
TextView : public Text
{
	using	super	=	Text;
public:
	using	super::super;
	
public:
	struct
	Utility : NonInstantiatable
	{
		static auto		textView() -> TextView;
	};
};



EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
