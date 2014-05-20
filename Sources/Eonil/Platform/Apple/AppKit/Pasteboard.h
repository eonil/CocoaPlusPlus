//
//  Pasteboard.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "Common.h"
#include "../Foundation/Object.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN







class
PasteboardItem : protected Foundation::Object
{
public:
	using	Object::Object;
	
	operator __unsafe_unretained id() const;
	
public:
	auto	types() const -> Foundation::SpecificTypeArray<String>;			//!	Returns UTI strings.
	auto	dataForType(String const& type) const -> Foundation::Data;
	auto	stringForType(String const& type) const -> String;
};




/*!
 Wraps `NSPasteboard`.
 */
class
Pasteboard : protected Foundation::Object
{
public:
	using	Object::Object;
	
public:
	struct
	Type
	{
		static auto	string() -> String;
		static auto	PDF() -> String;
		static auto	TIFF() -> String;
		static auto	PNG() -> String;
		static auto	RTF() -> String;
		static auto	RTFD() -> String;
		static auto	HTML() -> String;
		static auto	tabularText() -> String;
		static auto	font() -> String;
		static auto	ruler() -> String;
		static auto	color() -> String;
		static auto	sound() -> String;
		static auto	multipleTextSelection() -> String;
		static auto	findPanelSearchOptions() -> String;
	};
	
public:
	auto	pasteboardItems() const -> Foundation::SpecificTypeArray<PasteboardItem>;
};










EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
