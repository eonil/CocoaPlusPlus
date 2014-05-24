//
//  WindowController.h
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "Common.h"
#include "Responder.h"
#include "Window.h"
#include "Document.h"
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN





/*!
 @classdesign
 NIB related stuffs are not supported at all.
 Duplicated methods and event handlers are not supported.
 
 -	`close`		Not for UI manipulation. See Cocoa manual. Use `Window::performClose` method.
 
 */
class
WindowController final : public Responder
{
	template <typename T>	using	query	=	std::function<auto(void)->T>;
	
	using	super	=	Responder;
	
public:
	using	super::super;
	
public:
	struct
	Hooks
	{
		query<String>		windowTitleForDocumentDisplayName		=	nullptr;
	};
	
public:
	WindowController(Hooks);
	
public:
	auto	document() -> Document;
	auto	setDocument(Document) -> void;
	auto	unsetDocument() -> void;
	
	auto	window() -> Window;
	auto	setWindow(Window) -> void;
	auto	unsetWindow() -> void;
};




EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END


