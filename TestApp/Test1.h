//
//  Test1.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/27.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include <memory>

class
Test1
{
	struct	Core;
	std::unique_ptr<Core>	_core	{};
	
public:
	Test1();
	~Test1();
};


