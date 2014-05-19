//
//  Menu.h
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../Foundation/Object.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN




class	Menu;
class	MenuItem;










/*!
 Wraps `NSMenu`.
 */
class
Menu : public Foundation::Object
{
public:
	using	Foundation::Object::Object;
	
	auto	addItem(MenuItem&) -> void;
	
public:
	static auto	menu() -> Menu;
};






/*!
 Wraps `NSMenuItem`.
 
 @warning
 You cannot use this class to examine existing Objective-C object instances.
 This class can be used only for objects craeted by this class.
 */
class
MenuItem : public Foundation::Object
{
	using	ACTION	=	std::function<void(void)>;
	
public:
	using	Foundation::Object::Object;
	
	auto	setTitle(Foundation::String const&) -> void;
	auto	setKeyEquivalent(Foundation::String const&) -> void;
	auto	setSubmenu(Menu&) -> void;
	auto	setAction(ACTION const&) -> void;		//	Action will be copied.
	
public:
	static auto		menuItem() -> MenuItem;
//	static auto		menuItem(Foundation::String& title, ACTION& action, Foundation::String& keyEquivalent) -> MenuItem;
};







EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END