//
//  TableView.cpp
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "TableView.h"












using namespace	Eonil::CocoaCPP;
using namespace	Eonil::CocoaCPP::AppKit;

@interface	____Eonil_Cocoa_TableView_Delegate : NSObject <NSTableViewDelegate>
{
@public
	struct
	{
		TableView				cpp_tv{nullptr};
		TableView::Delegate*	cpp_delegate;
	}
	slots;
}
@end

@implementation ____Eonil_Cocoa_TableView_Delegate
- (CGFloat)tableView:(NSTableView *)tableView heightOfRow:(NSInteger)row
{
	return	slots.cpp_delegate->heightOfRow(slots.cpp_tv, row);
}
@end
















EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN

auto
TableColumn::tableColume() -> TableColumn
{
	return	{[[NSTableColumn alloc] init]};
}

auto
TableColumn::width() const -> Float
{
	auto	tc1		=	get_objc_object<NSTableColumn>();
	return	[tc1 width];
}
auto
TableColumn::setWidth(Float o) -> void
{
	auto	tc1		=	get_objc_object<NSTableColumn>();
	[tc1 setWidth:o];
}




















struct
TableView::Extras
{
	__strong ____Eonil_Cocoa_TableView_Delegate*		objc_delegate	{[[____Eonil_Cocoa_TableView_Delegate alloc] init]};
};

auto
TableView::tableView() -> TableView
{
	TableView		tv		=	{[[NSTableView alloc] init]};
	sptr<Extras>	extras	=	sptr<Extras>(new Extras());
	
	extras->objc_delegate->slots.cpp_tv		=	tv;
	
	return			tv;
}
TableView::TableView(id o, sptr<Extras> extras) : Control(o), _extras(extras)
{
}

auto
TableView::delegate() const -> Delegate*
{
	return	_extras->objc_delegate->slots.cpp_delegate;
}
auto
TableView::setDelegate(TableView::Delegate *o) -> void
{
	_extras->objc_delegate->slots.cpp_delegate	=	o;
	
	auto	tv1		=	get_objc_object<NSTableView>();
	[tv1 setDelegate:_extras->objc_delegate];
}
auto
TableView::unsetDelegate() -> void
{
	auto	tv1		=	get_objc_object<NSTableView>();
	[tv1 setDelegate:nil];
	
	_extras->objc_delegate->slots.cpp_delegate	=	nullptr;
}

auto
TableView::
addTableColumn(TableColumn o) -> void
{
	EONIL_COCOA_ASSERT_OBJC_TYPE(o, NSTableColumn);
	
	auto	tv1		=	get_objc_object<NSTableView>();
	[tv1 addTableColumn:o];
}
auto
TableView::
removeTableColumn(TableColumn o) -> void
{
	EONIL_COCOA_ASSERT_OBJC_TYPE(o, NSTableColumn);
	
	auto	tv1		=	get_objc_object<NSTableView>();
	[tv1 removeTableColumn:o];
}

auto
TableView::
beginUpdates() -> void
{
	auto	tv1		=	get_objc_object<NSTableView>();
	[tv1 beginUpdates];
}
auto
TableView::
endUpdates() -> void
{
	auto	tv1		=	get_objc_object<NSTableView>();
	[tv1 endUpdates];
}







EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
