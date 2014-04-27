//
//  ImageDestination.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../CoreFoundation/Type.h"

EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN





/*
 DO NOT MAKE wrapper of `CGImageDestination`. The feature doesn't work as I expected,
 and it's too hard to figure out how to use it. Use PNG features in `Eonil::Aliens`.
 */


//class
//ImageDestination : CoreFoundation::Type
//{
//public:
//	using	Type::Type;
//	
//	ImageDestination(CGImageDestinationRef);
//	
//public:
//	operator CGImageDestinationRef() const;
//	
//public:
//	ImageDestination(CoreFoundation::MutableData buffer, CoreFoundation::String UTI, size_t count);
//
//	auto	addImage(Image) -> void;
//	auto	finalize() -> void;
//	
//public:
//	static auto	dataOfImage(Image image, CoreFoundation::String UTI) -> CoreFoundation::Data;
//	static auto	PNGDataOfImage(Image image) -> CoreFoundation::Data;
//};










EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END
