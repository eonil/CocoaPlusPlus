//
//  Responder.h
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "Common.h"
#include "Object.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN





/*!
 Wraps `NSResponder`.
 Take care that you have to order to show the window.
 */
class
Responder : public Object
{
public:
	using	Object::Object;
};










EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END