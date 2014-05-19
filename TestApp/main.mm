//
//  main.m
//  TestApp
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#include "../Sources/Eonil/Platform/Apple/Cocoa.h"
#include "Test1.h"


using namespace Eonil::CocoaCPP::Foundation;
using namespace Eonil::CocoaCPP::AppKit;

struct
AppDelegate1 : Application::Delegate
{
	std::unique_ptr<Test1>	test1	=	nullptr;
	
	AppDelegate1()
	{
	}
	
	virtual inline auto
	applicationWillFinishLaunching() -> void
	{
		Menu		m1	=	Menu::menu();
		Menu		m2	=	Menu::menu();
		MenuItem	mi1	=	MenuItem::menuItem();
		MenuItem	mi2	=	MenuItem::menuItem();
		
		m1.addItem(mi1);
		mi1.setSubmenu(m2);
		m2.addItem(mi2);
		
		mi2.setTitle("Quit");
		mi2.setKeyEquivalent("q");
		mi2.setAction([]()
		{
			Application::sharingApplication().terminate();
		});

		Application::sharingApplication().setMainMenu(m1);
	}
	virtual inline auto
	applicationDidFinishLaunching() -> void
	{
		test1	=	std::unique_ptr<Test1>(new Test1());
	}
};



int main(int argc, const char * argv[])
{
//	return NSApplicationMain(argc, argv);
	
	AppDelegate1	del1	=	{};
	Application		app1	=	Application::sharingApplication();
	app1.setDelegate(&del1);
	app1.run();
}
