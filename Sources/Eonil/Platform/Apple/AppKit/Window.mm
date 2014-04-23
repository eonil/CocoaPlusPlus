//
//  Window.cpp
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Window.h"
#include "../CoreGraphics/Rect.h"
#include "View.h"




using namespace	Eonil::CocoaCPP;
using namespace	Eonil::CocoaCPP::AppKit;

@interface	____Eonil_Cocoa_WindowDelegate : NSObject <NSWindowDelegate>
{
@public
	struct
	{
		Window					cpp_window		{nullptr};
		Window::Delegate*		cpp_delegate	{nullptr};
	}
	slots;
}
@end
@implementation	____Eonil_Cocoa_WindowDelegate
- (BOOL)windowShouldClose:(id)sender
{
	return	slots.cpp_delegate->shouldClose();
}
@end








EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN

struct
Window::Extras
{
	____Eonil_Cocoa_WindowDelegate*	delegate	{};
};



Window::Window(id o1, sptr<Extras> o2) : Responder(o1), _extras(o2)
{
}

auto
Window::window() -> Window
{
	return	{[[NSWindow alloc] init]};
}





auto
Window::styleMask() const -> STYLE
{
	auto	self	=	get_objc_object<NSWindow>();
	
	return	STYLE([self styleMask]);
}
auto
Window::setStyleMask(Eonil::CocoaCPP::AppKit::Window::STYLE o) -> void
{
	EONIL_COCOA_DEBUG_ASSERT(UInteger(STYLE::BORDERLESS) == NSBorderlessWindowMask);
	EONIL_COCOA_DEBUG_ASSERT(UInteger(STYLE::TITLED) == NSTitledWindowMask);
	EONIL_COCOA_DEBUG_ASSERT(UInteger(STYLE::CLOSABLE) == NSClosableWindowMask);
	EONIL_COCOA_DEBUG_ASSERT(UInteger(STYLE::MINIATURIZABLE) == NSMiniaturizableWindowMask);
	EONIL_COCOA_DEBUG_ASSERT(UInteger(STYLE::RESIZABLE) == NSResizableWindowMask);
	EONIL_COCOA_DEBUG_ASSERT(UInteger(STYLE::TEXTURED_BACKGROUND) == NSTexturedBackgroundWindowMask);
	
	EONIL_COCOA_DEBUG_ASSERT(o == STYLE::BORDERLESS or (o & STYLE::TITLED) == STYLE::TITLED);
	
	////
	
	auto	self	=	get_objc_object<NSWindow>();
	
	[self setStyleMask:UInteger(o)];
}



auto
Window::delegate() const -> Delegate*
{
	return	_extras->delegate->slots.cpp_delegate;
}
auto
Window::setDelegate(Delegate *o) -> void
{
	_extras->delegate->slots.cpp_delegate	=	o;
	__unsafe_unretained NSWindow*	window	=	operator __unsafe_unretained id();
	[window setDelegate:_extras->delegate];
}
auto
Window::unsetDelegate() -> void
{
	__unsafe_unretained NSWindow*	window	=	operator __unsafe_unretained id();
	[window setDelegate:nil];
	_extras->delegate->slots.cpp_delegate	=	nullptr;
}

auto
Window::isVisible() const -> bool
{
	auto	w1	=	get_objc_object<NSWindow>();
	return	toCPP([w1 isVisible]);
}
auto
Window::orderFront() -> void
{
	auto	w1	=	get_objc_object<NSWindow>();
	[w1 orderFront:nil];
}
auto
Window::orderOut() -> void
{
	auto	w1	=	get_objc_object<NSWindow>();
	[w1 orderOut:nil];
}

auto
Window::isKeyWindow() const -> bool
{
	auto	w1	=	get_objc_object<NSWindow>();
	return	toCPP([w1 isKeyWindow]);
}
auto
Window::makeKey() -> void
{
	auto	w1	=	get_objc_object<NSWindow>();
	[w1 makeKeyWindow];
}

auto
Window::frame() const -> Rect
{
	auto	w1	=	get_objc_object<NSWindow>();
	return	[w1 frame];
}
auto
Window::setFrame(Rect f1, bool animated) -> void
{
	auto	w1	=	get_objc_object<NSWindow>();
	[w1 setFrame:f1 display:isVisible() animate:animated];
}

auto
Window::contentView() const -> View
{
	auto	w1	=	get_objc_object<NSWindow>();
	return	[w1 contentView];
}
auto
Window::setContentView(Eonil::CocoaCPP::AppKit::View o) -> void
{
	auto	w1	=	get_objc_object<NSWindow>();
	[w1 setContentView:o];
}





auto
Window::asResponder() const -> Responder const&
{
	return	*this;
}
auto
Window::asResponder() -> Responder&
{
	return	*this;
}















EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END

























//@interface	____OverridableWindow1 : NSWindow
//@end
//@implementation ____OverridableWindow1
//@end
//
//EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN
//
//
//
//auto
//OverridableWindow::Observer::didResize() -> void
//{
//}
//
//struct
//OverridableWindow::Extras
//{
//	OverridableWindow::Observer*	observer	{};
//};
//
//OverridableWindow::OverridableWindow() : _extras(new Extras())
//{
//}
//
//auto
//OverridableWindow::setObserver(Eonil::Cocoa::OverridableWindow::Observer *o) -> void
//{
//	_extras->observer	=	o;
//}
//
//
//
//EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
