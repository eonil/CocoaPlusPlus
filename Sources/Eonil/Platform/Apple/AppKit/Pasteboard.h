//
//  Pasteboard.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../Foundation/Object.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN







class
PasteboardItem : protected Foundation::Object
{
public:
	using	Object::Object;
	
	operator __unsafe_unretained id() const;
	
public:
	auto	types() const -> Foundation::SpecificTypeArray<Foundation::String>;			//!	Returns UTI strings.
	auto	dataForType(Foundation::String const& type) const -> Foundation::Data;
	auto	stringForType(Foundation::String const& type) const -> Foundation::String;
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
		static auto	string() -> Foundation::String;
		static auto	PDF() -> Foundation::String;
		static auto	TIFF() -> Foundation::String;
		static auto	PNG() -> Foundation::String;
		static auto	RTF() -> Foundation::String;
		static auto	RTFD() -> Foundation::String;
		static auto	HTML() -> Foundation::String;
		static auto	tabularText() -> Foundation::String;
		static auto	font() -> Foundation::String;
		static auto	ruler() -> Foundation::String;
		static auto	color() -> Foundation::String;
		static auto	sound() -> Foundation::String;
		static auto	multipleTextSelection() -> Foundation::String;
		static auto	findPanelSearchOptions() -> Foundation::String;
	};
	
public:
	auto	pasteboardItems() const -> Foundation::SpecificTypeArray<PasteboardItem>;
};










EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
