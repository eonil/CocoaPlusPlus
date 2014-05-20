//
//  Application.h
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "Common.h"
#include "Responder.h"
#include "DraggingDestination.h"
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN

class	Menu;





/*!
 Wraps `NSApplication`.
 */
class
Application : Responder
{
public:
	struct
	Delegate : Any
	{
		Delegate();
		Delegate(Delegate const&) = delete;
		Delegate(Delegate&&) = delete;
		virtual ~Delegate();
		
		virtual inline auto		applicationWillFinishLaunching() -> void		{}
		virtual inline auto		applicationDidFinishLaunching() -> void			{}
	};
	
public:
	using	Responder::Responder;
	
	static auto	sharingApplication() -> Application;
	
public:
	auto	delegate() const -> Delegate*;
	auto	setDelegate(Delegate*) -> void;
	auto	unsetDelegate() -> void;
	
	auto	setMainMenu(Menu&) -> void;
	
	auto	run() -> void;
	auto	stop() -> void;
	auto	terminate() -> void;
	
public:
	auto	asResponder() const -> Responder const&;
	auto	asResponder()  -> Responder&;
};










EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
