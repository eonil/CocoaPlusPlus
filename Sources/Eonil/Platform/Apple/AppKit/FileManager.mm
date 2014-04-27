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
FileManager::DirectoryEnumerator::nextObject() -> Foundation::String
{
	@autoreleasepool
	{
		auto	self	=	get_objc_object<NSDirectoryEnumerator>();
		id		obj1	=	[self nextObject];
		
		return	obj1;
	}
}
auto
FileManager::DirectoryEnumerator::level() const -> UInteger
{
	auto	self	=	get_objc_object<NSDirectoryEnumerator>();
	return	[self level];
}
auto
FileManager::DirectoryEnumerator::skipDescendants() -> void
{
	auto	self	=	get_objc_object<NSDirectoryEnumerator>();
	[self skipDescendants];
}










auto
FileManager::defaultManager() -> FileManager
{
	return	[NSFileManager defaultManager];
}
auto
FileManager::fileManager() -> FileManager
{
	return	[[NSFileManager alloc] init];
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

auto
FileManager::enumeratorAtPath(Foundation::String path) const -> DirectoryEnumerator
{
	@autoreleasepool
	{
		auto	self	=	get_objc_object<NSFileManager>();
		auto	direnum	=	[self enumeratorAtPath:path];
		
		return	DirectoryEnumerator(direnum);
	}
}










EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
