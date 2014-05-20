//
//  Exception.h
//  Cocoa++
//
//  Created by Hoon H. on 14/5/19.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include <Eonil/CommonRealtimeGameAlgorithms.h>

namespace
Eonil
{
	namespace
	Platform
	{
		namespace
		Debugging
		{
			class
			Error : public Eonil::CommonRealtimeGameAlgorithms::Error
			{
			public:
				using	Eonil::CommonRealtimeGameAlgorithms::Error::Error;
				
				Error(Error const&) = default;
				~Error();
			};
			
			class
			Crash : public Eonil::CommonRealtimeGameAlgorithms::Crash
			{
			public:
				using	Eonil::CommonRealtimeGameAlgorithms::Crash::Crash;
				
				Crash(Crash const&) = default;
				~Crash();
			};
			
			
			static bool const	USE_EXCEPTION_CHECKINGS				=	(EONIL_COMMON_REALTIME_GAME_ALGORITHMS_DEBUG_MODE == 1);		//	Performs only checkings with O(1) complexity.

			
			auto	error_if(bool const cond, std::string const& message = Eonil::CommonRealtimeGameAlgorithms::EXCEPTION_DEFAULT_MESSAGE) -> void;
			auto	crash_if(bool const cond, std::string const& message = Eonil::CommonRealtimeGameAlgorithms::EXCEPTION_DEFAULT_MESSAGE) -> void;
			
			
			
		}
	}
}

