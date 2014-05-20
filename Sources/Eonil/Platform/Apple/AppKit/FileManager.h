//
//  FileManager.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "../Foundation/Object.h"
#include "../Foundation/Date.h"
EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN






class
FileManager : public Foundation::Object
{
//public:
//	FileManager(FileManager const&) = delete;
//	FileManager(FileManager&&) = delete;
	
public:
//	static auto		defaultManager() -> FileManager;		//	Disabled because there's some unknown memory leak. I will enabled this again as soon as I fix the leak.
	static auto		fileManager() -> FileManager;
	
public:
	class
	DirectoryEnumerator : public Foundation::Object
	{
	public:
		using	Object::Object;
		
		auto	nextObject() -> Foundation::String;
		
		auto	level() const -> UInteger;
		auto	skipDescendants() -> void;
	};
	
	class
	Attributes : public Object
	{
		friend class	FileManager;
		Attributes(id infoDictionary);
		
	public:
		Attributes() = delete;
		
		auto	creationDate() const -> Foundation::Date;
		auto	modificationDate() const -> Foundation::Date;
		auto	size() const -> uint64_t;
	};
	
public:
	auto	fileExistsAtPath(Foundation::String) const -> bool;
	auto	fileExistsAtPathAsDirectory(Foundation::String) const -> bool;
	auto	attributesOfItemAtPath(Foundation::String path) const -> Attributes;
	
	auto	enumeratorAtPath(Foundation::String path) const -> DirectoryEnumerator;
	
private:
	using	Object::Object;
};











EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
