//
//  Window.cpp
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Window.h"
#include "../CoreGraphics/Rect.h"
#include "../Foundation/String.h"
#include "View.h"

using namespace	Eonil::Platform::Debugging;
using namespace	Eonil::CocoaCPP;
using namespace	Eonil::CocoaCPP::Foundation;
using namespace	Eonil::CocoaCPP::AppKit;

@interface	____Eonil_Cocoa_WindowDelegate : NSObject <NSWindowDelegate>
{
@public
	struct
	{
		Window::Delegate*		cpp_delegate	{nullptr};
	}
	slots;
}
@end
@implementation	____Eonil_Cocoa_WindowDelegate
- (BOOL)windowShouldClose:(id)sender
{
	return	toOBJC(slots.cpp_delegate->windowShouldClose(sender));
}

- (NSDragOperation)draggingEntered:(id<NSDraggingInfo>)sender
{
	EONIL_COCOA_DEBUG_ASSERT(self->slots.cpp_delegate != nullptr);
	return	NSDragOperation(self->slots.cpp_delegate->draggingEntered(sender));
}
- (NSDragOperation)draggingUpdated:(id<NSDraggingInfo>)sender
{
	EONIL_COCOA_DEBUG_ASSERT(self->slots.cpp_delegate != nullptr);
	return	NSDragOperation(self->slots.cpp_delegate->draggingUpdated(sender));
}
- (void)draggingEnded:(id<NSDraggingInfo>)sender
{
	EONIL_COCOA_DEBUG_ASSERT(self->slots.cpp_delegate != nullptr);
	self->slots.cpp_delegate->draggingEnded(sender);
}
- (void)draggingExited:(id<NSDraggingInfo>)sender
{
	EONIL_COCOA_DEBUG_ASSERT(self->slots.cpp_delegate != nullptr);
	self->slots.cpp_delegate->draggingExited(sender);
}
- (BOOL)prepareForDragOperation:(id<NSDraggingInfo>)sender
{
	EONIL_COCOA_DEBUG_ASSERT(self->slots.cpp_delegate != nullptr);
	return	toOBJC(self->slots.cpp_delegate->prepareForDragOperation(sender));
}
- (BOOL)performDragOperation:(id<NSDraggingInfo>)sender
{
	EONIL_COCOA_DEBUG_ASSERT(self->slots.cpp_delegate != nullptr);
	return	toOBJC(self->slots.cpp_delegate->performDragOperation(sender));
}
- (void)concludeDragOperation:(id<NSDraggingInfo>)sender
{
	EONIL_COCOA_DEBUG_ASSERT(self->slots.cpp_delegate != nullptr);
	self->slots.cpp_delegate->concludeDragOperation(sender);
}
- (void)updateDraggingItemsForDrag:(id<NSDraggingInfo>)sender
{
	EONIL_COCOA_DEBUG_ASSERT(self->slots.cpp_delegate != nullptr);
	self->slots.cpp_delegate->updateDraggingItemsForDrag(sender);
}
@end








EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN



Window::Delegate::Delegate() : Any([[____Eonil_Cocoa_WindowDelegate alloc] init])
{
	auto	self	=	get_objc_object<____Eonil_Cocoa_WindowDelegate>();
	self->slots.cpp_delegate	=	this;
}




auto
Window::window() -> Window
{
	if (USE_EXCEPTION_CHECKINGS)
	{
		crash_if(NSApp == nil, "You must create `Application` object first before creating any `Window` object.");
	}
	
	////

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
	auto	self	=	get_objc_object<NSWindow>();
	____Eonil_Cocoa_WindowDelegate*		d1	=	[self delegate];
	Window::Delegate*					d2	=	d1->slots.cpp_delegate;
	
	return	d2;
}
auto
Window::setDelegate(Delegate *o) -> void
{
	__unsafe_unretained NSWindow*	self	=	operator __unsafe_unretained id();
	[self setDelegate:*o];
}
auto
Window::unsetDelegate() -> void
{
	__unsafe_unretained NSWindow*	self	=	operator __unsafe_unretained id();
	[self setDelegate:nil];
}

auto
Window::isVisible() const -> bool
{
	auto	self	=	get_objc_object<NSWindow>();
	return	toCPP([self isVisible]);
}
auto
Window::orderFront() -> void
{
	auto	self	=	get_objc_object<NSWindow>();
	[self orderFront:nil];
}
auto
Window::orderOut() -> void
{
	auto	self	=	get_objc_object<NSWindow>();
	[self orderOut:nil];
}

auto
Window::isKeyWindow() const -> bool
{
	auto	self	=	get_objc_object<NSWindow>();
	return	toCPP([self isKeyWindow]);
}
auto
Window::makeKey() -> void
{
	auto	self	=	get_objc_object<NSWindow>();
	[self makeKeyWindow];
}

auto
Window::frame() const -> Rect
{
	auto	self	=	get_objc_object<NSWindow>();
	return	[self frame];
}
auto
Window::setFrame(Rect f1, bool animated) -> void
{
	auto	self	=	get_objc_object<NSWindow>();
	[self setFrame:f1 display:isVisible() animate:animated];
}

auto
Window::setContentSize(Size o) -> void
{
	auto	self	=	get_objc_object<NSWindow>();
	[self setContentSize:o];
}

auto
Window::contentView() const -> View
{
	auto	self	=	get_objc_object<NSWindow>();
	return	[self contentView];
}
auto
Window::setContentView(Eonil::CocoaCPP::AppKit::View o) -> void
{
	auto	self	=	get_objc_object<NSWindow>();
	[self setContentView:o];
}

auto
Window::title() const -> String
{
	auto	self	=	get_objc_object<NSWindow>();
	return	[self title];
}
auto
Window::setTitle(Foundation::String o) -> void
{
	auto	self	=	get_objc_object<NSWindow>();
	[self setTitle:o];
}
auto
Window::setTitleWithRepresentativeFilename(Foundation::String filename) -> void
{
	auto	self	=	get_objc_object<NSWindow>();
	[self setTitleWithRepresentedFilename:filename];
}

auto
Window::registerForDraggedTypes(const vec<Foundation::String> &UTIs) -> void
{
	NSMutableArray*	a1	=	[[NSMutableArray alloc] init];
	for (Foundation::String const& s1: UTIs)
	{
		[a1 addObject:s1];
	}
	
	////
	
	auto	self	=	get_objc_object<NSWindow>();
	[self registerForDraggedTypes:a1];
}
auto
Window::unregisterDraggedTypes() -> void
{
	auto	self	=	get_objc_object<NSWindow>();
	[self unregisterDraggedTypes];
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
