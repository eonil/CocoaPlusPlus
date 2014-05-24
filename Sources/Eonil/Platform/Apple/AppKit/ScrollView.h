//
//  ScrollView.h
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "Common.h"
#include "View.h"
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN






class
ScrollView : public View
{
	using	super	=	View;

public:
	struct
	Parameters
	{
		struct
		{
			bool	vertical	=	false;
			bool	horizontal	=	false;
		}
		scrollers{};
		
		View	document	=	nullptr;
	};
	
public:
	using	super::super;
	
public:
	auto	setDocumentView(View) -> void;
	
public:
	static auto		scrollView() -> ScrollView;
	static auto		scrollViewWithParameters(Parameters) -> ScrollView;
};




EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
