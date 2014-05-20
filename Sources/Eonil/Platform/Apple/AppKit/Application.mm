//
//  Application.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Application.h"
#include "Menu.h"
using namespace	Eonil::CocoaCPP;
using namespace	Eonil::CocoaCPP::Foundation;
using namespace	Eonil::CocoaCPP::AppKit;

@interface	____Eonil_Cocoa_AppDelegate : NSObject <NSApplicationDelegate>
@end
@implementation	____Eonil_Cocoa_AppDelegate
{
@public
	struct
	{
		Application::Delegate*		cpp_delegate	{nullptr};
	}
	slots;
}
- (void)applicationWillFinishLaunching:(NSNotification *)notification
{
	slots.cpp_delegate->applicationWillFinishLaunching();
}
- (void)applicationDidFinishLaunching:(NSNotification *)notification
{
	slots.cpp_delegate->applicationDidFinishLaunching();
}
@end








EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN



Application::Delegate::Delegate() : Any([[____Eonil_Cocoa_AppDelegate alloc] init])
{
	auto	self	=	get_objc_object<____Eonil_Cocoa_AppDelegate>();
	self->slots.cpp_delegate	=	this;
}
Application::Delegate::~Delegate()
{
}




auto
Application::sharingApplication() -> Application
{
	return	[NSApplication sharedApplication];
}



auto
Application::delegate() const -> Delegate*
{
	auto	self	=	get_objc_object<NSApplication>();
	____Eonil_Cocoa_AppDelegate*		d1	=	[self delegate];
	Application::Delegate*				d2	=	d1->slots.cpp_delegate;
	
	return	d2;
}
auto
Application::setDelegate(Delegate *o) -> void
{
	__unsafe_unretained NSWindow*	self	=	operator __unsafe_unretained id();
	[self setDelegate:*o];
}
auto
Application::unsetDelegate() -> void
{
	__unsafe_unretained NSWindow*	self	=	operator __unsafe_unretained id();
	[self setDelegate:nil];
}


auto
Application::setMainMenu(Eonil::CocoaCPP::AppKit::Menu& o) -> void
{
	EONIL_COCOA_ASSERT_OBJC_TYPE(o, NSMenu);
	
	////
	
	auto	self	=	get_objc_object<NSApplication>();
	[self setMainMenu:o];
}






auto
Application::
run() -> void
{
	auto&	self	=	*this;
	[self run];
}
auto
Application::
stop() -> void
{
	auto&	self	=	*this;
	[self stop:nil];
}
auto
Application::
terminate() -> void
{
	auto	self	=	get_objc_object<NSApplication>();
	[self terminate:nil];
}







auto
Application::asResponder() const -> Responder const&
{
	return	*this;
}
auto
Application::asResponder() -> Responder&
{
	return	*this;
}















EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
