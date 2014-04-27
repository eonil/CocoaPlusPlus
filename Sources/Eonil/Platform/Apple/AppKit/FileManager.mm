//
//  FileManager.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "FileManager.h"
#include "../Foundation/String.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN



using namespace	Foundation;





auto
FileManager::defaultManager() -> FileManager
{
	return	[NSFileManager defaultManager];
}



auto
FileManager::fileExistsAtPath(Foundation::String o) const -> bool
{
	auto	self	=	get_objc_object<NSFileManager>();
	return	toCPP([self fileExistsAtPath:o]);
}
auto
FileManager::fileExistsAtPathAsDirectory(Foundation::String o) const -> bool
{
	auto	self	=	get_objc_object<NSFileManager>();
	BOOL	isdir	=	NO;
	BOOL	res1	=	[self fileExistsAtPath:o isDirectory:&isdir];
	return	toCPP(res1 && isdir);
}











EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END