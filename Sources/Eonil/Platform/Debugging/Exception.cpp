//
//  Exception.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Exception.h"
#include <iostream>
namespace
Eonil
{
	namespace
	Platform
	{
		namespace
		Debugging
		{
			
			
			
			
			static char const*	DOMAIN_NAME	=	"Eonil::Cococa";
			
			
			
			
			
			
			auto
			error_if(bool const condition, std::string const& message) -> void
			{
				if (condition)
				{
					Error	exc	=	Error(DOMAIN_NAME, message);
					std::cout << exc.what() << "\n";
					throw	exc;
				}
			}
			
			auto
			crash_if(bool const condition, std::string const& message) -> void
			{
				if (condition)
				{
					Crash	exc	=	Crash(DOMAIN_NAME, message);
					std::cout << exc.what() << "\n";
					throw	exc;
				}
			}

			
			
			

					
			Error::~Error()
			{
			}
					
			Crash::~Crash()
			{	
			}
			
			
			
			
			
			
			
			
			
			
			
			
		}
	}
}
