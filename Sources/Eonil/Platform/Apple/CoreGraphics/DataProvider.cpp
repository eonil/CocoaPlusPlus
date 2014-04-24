//
//  DataProvider.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/24.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "DataProvider.h"
#include "../CoreFoundation/Data.h"

EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN








DataProvider::DataProvider(CGDataProviderRef o) : Type(o)
{
}

DataProvider::operator CGDataProviderRef() const
{
	return	(CGDataProviderRef)operator CFTypeRef();
}
















DataProvider::DataProvider(CoreFoundation::Data& o) : Type(CGDataProviderCreateWithCFData(o))
{
}


auto
DataProvider::copyData() const -> CoreFoundation::Data
{
	return	CGDataProviderCopyData(*this);
}





EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END
