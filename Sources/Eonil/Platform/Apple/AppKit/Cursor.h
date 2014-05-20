//
//  Cursor.h
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "Common.h"
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN





class
Cursor final : public Object
{
	using	base	=	Object;
public:
	using	base::base;
	
public:
	struct
	Utility
	{
		Utility() = delete;
		
		////
		
		static auto		hide() -> void;
		static auto		unhide() -> void;
		
		static auto		setHideUntilMouseMove(bool const) -> void;
		
		////
		
		static auto		current() -> Cursor;
		static auto		currentSystem() -> Cursor;
		
		////
		
		static auto		arrow() -> Cursor;
		static auto		IBeam() -> Cursor;
		static auto		IBeamForVerticalLayout() -> Cursor;
		static auto		crossHair() -> Cursor;
		
		/*!
		 @todo
		 There're many more. Add when you needed...
		 */
	};
};





EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END

