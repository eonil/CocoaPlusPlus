//
//  FileManager.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "FileManager.h"
#include "../Foundation/String.h"
#include "../Foundation/Date.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN



using namespace	Foundation;















FileManager::Attributes::Attributes(id dict1) : Object(dict1)
{
}
auto
FileManager::Attributes::creationDate() const -> Date
{
	auto	self	=	get_objc_object<NSDictionary>();
	EONIL_COCOA_ASSERT_OBJC_TYPE(self[NSFileCreationDate], NSDate);
	return	self[NSFileCreationDate];
}
auto
FileManager::Attributes::modificationDate() const -> Date
{
	auto	self	=	get_objc_object<NSDictionary>();
	EONIL_COCOA_ASSERT_OBJC_TYPE(self[NSFileModificationDate], NSDate);
	return	self[NSFileModificationDate];
}
auto
FileManager::Attributes::size() const -> uint64_t
{
	auto	self	=	get_objc_object<NSDictionary>();
	EONIL_COCOA_ASSERT_OBJC_TYPE(self[NSFileSize], NSNumber);
	return	[self[NSFileSize] unsignedLongLongValue];
}














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










//auto
//FileManager::defaultManager() -> FileManager
//{
//	return	[NSFileManager defaultManager];
//}
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
FileManager::attributesOfItemAtPath(Foundation::String path) const -> Attributes
{
	auto	self	=	get_objc_object<NSFileManager>();
	
	////
	
	NSError*		err1	=	nil;
	NSDictionary*	att1	=	[self attributesOfItemAtPath:path error:&err1];
	
	return	att1;
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
