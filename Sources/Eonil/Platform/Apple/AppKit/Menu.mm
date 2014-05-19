//
//  Menu.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Menu.h"
#include "../Foundation/String.h"
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN






auto
Menu::addItem(MenuItem& o) -> void
{
	EONIL_COCOA_ASSERT_OBJC_TYPE(o, NSMenuItem);
	
	////
	
	auto	self	=	get_objc_object<NSMenu>();
	[self addItem:o];
}

auto
Menu::menu() -> Menu
{
	return	[[NSMenu alloc] init];
}






EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END





























@interface	____Eonil_Cocoa_MenuItem_2 : NSMenuItem
{
@public
	std::function<void(void)>	action;
}
- (void)____on_action:(id)sender;
@end
@implementation ____Eonil_Cocoa_MenuItem_2
- (void)____on_action:(id)sender
{
	using namespace	Eonil::Platform::Debugging;
	
	if (USE_EXCEPTION_CHECKINGS)
	{
		error_if(action == nullptr, "Menu has no action closure. It is not harmful, but very likely to be a bug.");
	}
	
	////
	
	if (action != nullptr)
	{
		action();
	}
}
@end
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN
using	MENU_ITEM	=	____Eonil_Cocoa_MenuItem_2;

auto
MenuItem::setTitle(const Foundation::String& o) -> void
{
	EONIL_COCOA_ASSERT_OBJC_TYPE(o, NSString);
	
	////
	
	auto	self	=	get_objc_object<MENU_ITEM>();
	[self setTitle:o];
}
auto
MenuItem::setKeyEquivalent(const Foundation::String &o) -> void
{
	EONIL_COCOA_ASSERT_OBJC_TYPE(o, NSString);
	
	////
	
	auto	self	=	get_objc_object<MENU_ITEM>();
	[self setKeyEquivalent:o];
}
auto
MenuItem::setSubmenu(Eonil::CocoaCPP::AppKit::Menu &o) -> void
{
	EONIL_COCOA_ASSERT_OBJC_TYPE(o, NSMenu);
	
	////
	
	auto	self	=	get_objc_object<MENU_ITEM>();
	[self setSubmenu:o];
}
auto
MenuItem::setAction(ACTION const& o) -> void
{
	auto	self	=	get_objc_object<MENU_ITEM>();
	self->action	=	o;
}

auto
MenuItem::menuItem() -> MenuItem
{
	MENU_ITEM*	item1	=	[[MENU_ITEM alloc] init];
	[item1 setTarget:item1];
	[item1 setAction:@selector(____on_action:)];
	return	item1;
}
auto
MenuItem::menuItem(const Foundation::String &title, const ACTION &action, const Foundation::String &keyEquivalent) -> MenuItem
{
	MENU_ITEM*	item1	=	menuItem();
	item1->action		=	action;
	[item1 setTitle:title];
	[item1 setKeyEquivalent:keyEquivalent];
	return	item1;
}







EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END