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
@end

@implementation ____Eonil_Cocoa_TableView_Delegate
{
@public
	struct
	{
		TableView::Delegate*	cpp_delegate;
	}
	slots;
}
- (CGFloat)tableView:(NSTableView *)tableView heightOfRow:(NSInteger)row
{
	return	slots.cpp_delegate->heightOfRow(tableView, row);
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
	auto	self	=	get_objc_object<NSTableColumn>();
	return	[self width];
}
auto
TableColumn::setWidth(Float o) -> void
{
	auto	self	=	get_objc_object<NSTableColumn>();
	[self setWidth:o];
}

auto
TableColumn::
headerCell() const -> Cell
{
	auto	self	=	get_objc_object<NSTableColumn>();
	return	[self headerCell];
}
auto
TableColumn::
setHeaderCell(Cell const& o) -> void
{
	auto	self	=	get_objc_object<NSTableColumn>();
	[self setHeaderCell:o];
}


























TableView::Delegate::~Delegate()
{
}







auto
TableView::tableView() -> TableView
{
	return	[[NSTableView alloc] init];
}

auto
TableView::delegate() const -> Delegate*
{
	auto									self	=	get_objc_object<NSTableView>();
	____Eonil_Cocoa_TableView_Delegate*		d1		=	[self delegate];
	Delegate*								d2		=	d1->slots.cpp_delegate;
	return									d2;
}
auto
TableView::setDelegate(TableView::Delegate *o) -> void
{
	auto	self	=	get_objc_object<NSTableView>();
	[self setDelegate:*o];
}
auto
TableView::unsetDelegate() -> void
{
	auto	self	=	get_objc_object<NSTableView>();
	[self setDelegate:nil];
}

auto
TableView::
addTableColumn(TableColumn o) -> void
{
	EONIL_COCOA_ASSERT_OBJC_TYPE(o, NSTableColumn);
	
	auto	self	=	get_objc_object<NSTableView>();
	[self addTableColumn:o];
}
auto
TableView::
removeTableColumn(TableColumn o) -> void
{
	EONIL_COCOA_ASSERT_OBJC_TYPE(o, NSTableColumn);
	
	auto	self	=	get_objc_object<NSTableView>();
	[self removeTableColumn:o];
}

auto
TableView::
beginUpdates() -> void
{
	auto	self	=	get_objc_object<NSTableView>();
	[self beginUpdates];
}
auto
TableView::
endUpdates() -> void
{
	auto	self	=	get_objc_object<NSTableView>();
	[self endUpdates];
}







EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
