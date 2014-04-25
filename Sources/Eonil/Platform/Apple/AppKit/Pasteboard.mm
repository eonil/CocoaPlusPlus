//
//  Pasteboard.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Pasteboard.h"
#include "../Foundation/String.h"
#include "../Foundation/Array.h"
#include "../Foundation/Data.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN

using namespace	Foundation;












PasteboardItem::operator __unsafe_unretained id() const
{
	return	get_objc_object<NSPasteboardItem>();
}









auto
PasteboardItem::types() const -> SpecificTypeArray<String>
{
	auto	self	=	get_objc_object<NSPasteboardItem>();
	return	[self types];
}
auto
PasteboardItem::dataForType(const Foundation::String &type) const -> Data
{
	auto	self	=	get_objc_object<NSPasteboardItem>();
	return	[self dataForType:type];
}
auto
PasteboardItem::stringForType(const Foundation::String &type) const -> String
{
	auto	self	=	get_objc_object<NSPasteboardItem>();
	return	[self stringForType:type];
}









auto
Pasteboard::Type::string() -> String
{
	return	String{NSPasteboardTypeString};
}
auto
Pasteboard::Type::PDF() -> String
{
	return	String{NSPasteboardTypePDF};
}
auto
Pasteboard::Type::TIFF() -> String
{
	return	String{NSPasteboardTypeTIFF};
}
auto
Pasteboard::Type::PNG() -> String
{
	return	String{NSPasteboardTypePNG};
}
auto
Pasteboard::Type::RTF() -> String
{
	return	String{NSPasteboardTypeRTF};
}
auto
Pasteboard::Type::RTFD() -> String
{
	return	String{NSPasteboardTypeRTFD};
}
auto
Pasteboard::Type::HTML() -> String
{
	return	String{NSPasteboardTypeHTML};
}
auto
Pasteboard::Type::tabularText() -> String
{
	return	String{NSPasteboardTypeTabularText};
}
auto
Pasteboard::Type::font() -> String
{
	return	String{NSPasteboardTypeFont};
}
auto
Pasteboard::Type::ruler() -> String
{
	return	String{NSPasteboardTypeRuler};
}
auto
Pasteboard::Type::color() -> String
{
	return	String{NSPasteboardTypeColor};
}
auto
Pasteboard::Type::sound() -> String
{
	return	String{NSPasteboardTypeSound};
}
auto
Pasteboard::Type::multipleTextSelection() -> String
{
	return	String{NSPasteboardTypeMultipleTextSelection};
}
auto
Pasteboard::Type::findPanelSearchOptions() -> String
{
	return	String{NSPasteboardTypeFindPanelSearchOptions};
}






auto
Pasteboard::pasteboardItems() const -> SpecificTypeArray<PasteboardItem>
{
	auto	self	=	get_objc_object<NSPasteboard>();
	return	[self pasteboardItems];
}









EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
