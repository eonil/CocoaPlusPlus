//
//  AppDelegate.m
//  TestApp
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#import "AppDelegate.h"

//#include "Test1.h"
//
//@implementation AppDelegate
//{
//	std::unique_ptr<Test1>		_test1;
//}
//- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
//{
//	_test1	=	std::unique_ptr<Test1>(new Test1());
//}
//- (void)applicationWillTerminate:(NSNotification *)notification
//{
//	_test1	=	nullptr;
//}
//
//@end

















#include "Rect.h"
#include "Window.h"
#include "TableView.h"
#include "Layer.h"
#include "../Sources/Eonil/Platform/Apple/Cocoa.h"
#include "../Sources/Eonil/Platform/Apple/AppKit/Color.h"
#include "../Sources/Eonil/Platform/Apple/CoreGraphics/Color.h"

using namespace	Eonil::CocoaCPP;
using namespace	Eonil::CocoaCPP::CoreAnimation;
using namespace	Eonil::CocoaCPP::AppKit;


struct
Core
{
	using	Rect	=	Eonil::CocoaCPP::AppKit::Rect;
	
	Window		w1		{Window::window()};
	View		v2		{View::view()};
	TableView	tv3		{TableView::tableView()};
	
	Core()
	{
		w1.setStyleMask(Window::STYLE::RESIZABLE | Window::STYLE::CLOSABLE | Window::STYLE::TITLED);
		w1.orderFront();
		w1.makeKey();
		w1.setFrame(Rect{0,0,300,300}, YES);
		w1.contentView().addSubview(v2);
		
		v2.setFrame({0,0,200,200});
		v2.addSubview(tv3);
		
//		Layer	l1	{Layer::layer()};
//		l1.setFrame({0,0,100,100});
//		l1.setBackgroundColor(Color::color({1,1,0,1}).CGColor());
//		v2.setWantsLayer(true);
//		v2.setLayer(l1);
		
		TableColumn	c1	{TableColumn::tableColume()};
		tv3.addTableColumn(c1);
		
		tv3.setFrame({0,0,200,200});
	}
};







#include "Test1.h"

@implementation AppDelegate
{
	std::unique_ptr<Core>		_test1;
}
- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
	_test1	=	std::unique_ptr<Core>(new Core());
	
	char const*	s0	=	"AAA";
	{
		for (UInteger i=0; i<1024*1024; i++)
		{
//			Foundation::Object			o1		=	Foundation::Object::object();
//			Foundation::String			s1		=	Foundation::String::stringWithUTF8String(s0);
			Foundation::AnytypeArray	a1		=	Foundation::AnytypeArray::anytypeArray();
		}
	}
}
- (void)applicationWillTerminate:(NSNotification *)notification
{
	_test1	=	nullptr;
}

@end
