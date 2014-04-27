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

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN






class
FileManager : public Foundation::Object
{
//public:
//	FileManager(FileManager const&) = delete;
//	FileManager(FileManager&&) = delete;
	
public:
	static auto		defaultManager() -> FileManager;
	
public:
	auto	fileExistsAtPath(Foundation::String) const -> bool;
	auto	fileExistsAtPathAsDirectory(Foundation::String) const -> bool;
	
private:
	using	Object::Object;
};











EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END