//
//  Test1.cpp
//  Cocoa++
//
//  Created by Hoon H. on 14/4/27.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "Test1.h"
#include "../Sources/Eonil/Platform/Apple/Cocoa.h"
//#include "../Sources/Eonil/Platform/Apple/Cocoa.h"
//#include "../Sources/Eonil/Platform/Apple/Cocoa.h"

using namespace	Eonil::CocoaCPP;
using namespace	Eonil::CocoaCPP::Foundation;
using namespace	Eonil::CocoaCPP::CoreAnimation;
using namespace	Eonil::CocoaCPP::AppKit;


struct
Test1::Core
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
		
//		w1.contentView().addSubview(v2);
//		
//		v2.setFrame({0,0,200,200});
//		v2.addSubview(tv3);
//		
////		Layer	l1	{Layer::layer()};
////		l1.setFrame({0,0,100,100});
////		l1.setBackgroundColor(Color::color({1,1,0,1}).CGColor());
////		v2.setWantsLayer(true);
////		v2.setLayer(l1);
//		
//		TableColumn	c1	{TableColumn::tableColume()};
//		c1.setWidth(100);
//		c1.setHeaderCell(TableHeaderCell());
//		tv3.addTableColumn(c1);
//		
//		tv3.setFrame({0,0,200,200});
		
		TextView	tv1	=	TextView::Utility::textView();
		tv1.setFrame({0,0,300,300});
		
		ScrollView::Parameters	sv1p	=	{};
		sv1p.document					=	tv1;
		sv1p.scrollers.vertical			=	true;
		
		ScrollView	sv1	=	ScrollView::scrollViewWithParameters(sv1p);
		sv1.setFrame({0,0,300,300});
		w1.contentView().addSubview(sv1);
		
		
	}
};



Test1::Test1() : _core(new Core())
{
}
Test1::~Test1()
{
}
