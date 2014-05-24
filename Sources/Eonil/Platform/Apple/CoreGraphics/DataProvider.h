//
//  DataProvider.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/24.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../CoreFoundation/Type.h"

EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN











class
DataProvider final : protected CoreFoundation::Type
{
public:
	using	Type::Type;
	
	DataProvider(CGDataProviderRef);
	
	operator CGDataProviderRef() const;
	
public:
	DataProvider(CoreFoundation::Data);
	
public:
	auto	copyData() const -> CoreFoundation::Data;
};















EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END
