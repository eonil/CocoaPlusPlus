////
////  ImageDestination.cpp
////  Cocoa++
////
////  Created by Hoon H. on 14/4/25.
////  Copyright (c) 2014 Eonil. All rights reserved.
////
//
//#include "ImageDestination.h"
//#include "Image.h"
//#include "../CoreFoundation/String.h"
//#include "../CoreFoundation/Data.h"
//
//EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_BEGIN
//
//using namespace	CoreFoundation;
//
//
//
//ImageDestination::ImageDestination(CGImageDestinationRef o) : Type(o)
//{
//}
//ImageDestination::operator CGImageDestinationRef() const
//{
//	return	(CGImageDestinationRef)CFTypeRef();
//}
//
//
//
//namespace
//{
////	static auto
////	_make(
//}
//
//ImageDestination::ImageDestination(MutableData buffer, CoreFoundation::String UTI, size_t count) : Type(CGImageDestinationCreateWithData(buffer, UTI, count, NULL))
//{
//	EONIL_COCOA_DEBUG_ASSERT(count >= 1);
//	EONIL_COCOA_DEBUG_ASSERT(buffer != nullptr);
//	EONIL_COCOA_DEBUG_ASSERT(UTI != nullptr);
//}
//auto
//ImageDestination::addImage(Image o) -> void
//{
//	CGImageDestinationAddImage(*this, o, NULL);
//}
//auto
//ImageDestination::finalize() -> void
//{
//	CGImageDestinationFinalize(*this);
//}
//
//
//auto
//ImageDestination::dataOfImage(Eonil::CocoaCPP::CoreGraphics::Image image, CoreFoundation::String UTI) -> Data
//{
//	EONIL_COCOA_DEBUG_ASSERT(image != nullptr);
//	EONIL_COCOA_DEBUG_ASSERT(UTI != nullptr);
//	
//	MutableData			d1		{MutableData::mutableData()};
//	ImageDestination	dst1	{d1, UTI, 1};
//	dst1.addImage(image);
//	dst1.finalize();
//	
//	return	d1;
//}
//auto
//ImageDestination::PNGDataOfImage(Eonil::CocoaCPP::CoreGraphics::Image image) -> Data
//{
//	return	dataOfImage(image, String(kUTTypePNG));
//}
//
//
//
//
//
//
//EONIL_PLATFORM_APPLE_CORE_GRAPHICS_NAMESPACE_END
