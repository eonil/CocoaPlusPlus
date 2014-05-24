//
//  ScrollView.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "ScrollView.h"
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN





auto
ScrollView::
setDocumentView(Eonil::CocoaCPP::AppKit::View o) -> void
{
	EONIL_COCOA_ASSERT_OBJC_TYPE(o, NSView);
	
	////
	
	auto	self	=	get_objc_object<NSScrollView>();
	[self setDocumentView:o];
}


auto
ScrollView::
scrollView() -> ScrollView
{
	return	scrollViewWithParameters({});
}
auto
ScrollView::
scrollViewWithParameters(Eonil::CocoaCPP::AppKit::ScrollView::Parameters p1) -> ScrollView
{
	auto	sv1	=	[[NSScrollView alloc] init];
	
	[sv1 setHasVerticalScroller:toOBJC(p1.scrollers.vertical)];
	[sv1 setHasHorizontalScroller:toOBJC(p1.scrollers.horizontal)];
	
	if (p1.document != nullptr)
	{
		[sv1 setDocumentView:p1.document];
	}
	
	return	sv1;
}





EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END

