//
//  Common.h
//  Cocoa++
//
//  Created by Hoon H. on 14/5/24.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../Foundation/Object.h"
#include "../Foundation/Data.h"
#include "../Foundation/String.h"
#include "../Foundation/Array.h"
EONIL_PLATFORM_APPLE_UIKIT_NAMESPACE_BEGIN





using	Object	=	Foundation::Object;
using	Data	=	Foundation::Data;
using	String	=	Foundation::String;
using	Array	=	Foundation::AnytypeArray;

struct
NonInstantiatable
{
	NonInstantiatable() = delete;
};

class	Responder;
class	View;
class	TextView;
class	ScrollView;
class	Window;
class	Application;

class
DelegateBase : public Any
{
public:
	using	Any::Any;
	virtual ~DelegateBase();
};





EONIL_PLATFORM_APPLE_UIKIT_NAMESPACE_END
