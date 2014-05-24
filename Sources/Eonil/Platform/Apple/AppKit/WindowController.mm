//
//  WindowController.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "WindowController.h"
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN







auto
WindowController::
document() -> Document
{
	auto	self	=	get_objc_object<NSWindowController>();
	return	[self document];
}

auto
WindowController::
setDocument(Eonil::CocoaCPP::AppKit::Document o) -> void
{
	EONIL_COCOA_ASSERT_OBJC_TYPE(o, NSDocument);
	
	////
	
	auto	self	=	get_objc_object<NSWindowController>();
	[self setDocument:o];
}

auto
WindowController::
unsetDocument() -> void
{
	auto	self	=	get_objc_object<NSWindowController>();
	[self setDocument:nil];
}













auto
WindowController::
window() -> Window
{
	auto	self	=	get_objc_object<NSWindowController>();
	return	[self window];
}

auto
WindowController::
setWindow(Eonil::CocoaCPP::AppKit::Window o) -> void
{
	EONIL_COCOA_ASSERT_OBJC_TYPE(o, NSWindow);
	
	////
	
	auto	self	=	get_objc_object<NSWindowController>();
	[self setWindow:o];
}

auto
WindowController::
unsetWindow() -> void
{
	auto	self	=	get_objc_object<NSWindowController>();
	[self setWindow:nil];
}



EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END


