//
//  Cursor.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Cursor.h"
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN







auto
Cursor::Utility::
hide() -> void
{
	[NSCursor hide];
}
auto
Cursor::Utility::
unhide() -> void
{
	[NSCursor unhide];
}
auto
Cursor::Utility::
setHideUntilMouseMove(const bool o) -> void
{
	[NSCursor setHiddenUntilMouseMoves:toOBJC(o)];
}



auto
Cursor::Utility::
current() -> Cursor
{
	return	[NSCursor currentCursor];
}
auto
Cursor::Utility::
currentSystem() -> Cursor
{
	return	[NSCursor currentSystemCursor];
}



auto
Cursor::Utility::
arrow() -> Cursor
{
	return	[NSCursor arrowCursor];
}
auto
Cursor::Utility::
IBeam() -> Cursor
{
	return	[NSCursor IBeamCursor];
}
auto
Cursor::Utility::
crossHair() -> Cursor
{
	return	[NSCursor crosshairCursor];
}
auto
Cursor::Utility::
IBeamForVerticalLayout() -> Cursor
{
	return	[NSCursor IBeamCursorForVerticalLayout];
}





EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
