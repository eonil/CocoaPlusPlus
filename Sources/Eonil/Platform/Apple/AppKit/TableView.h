//
//  TableView.h
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "Control.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN




class
TableColumn : public Foundation::Object
{
public:
	static auto	tableColume() -> TableColumn;
	
public:
	using	Object::Object;
	
public:
	auto	width() const -> Float;
	auto	setWidth(Float) -> void;
};







class
TableView : public Control
{
public:
	using	Control::Control;
	
public:
	static auto	tableView() -> TableView;
	
public:
	struct
	Delegate : Any
	{
		virtual auto	heightOfRow(TableView, Integer row) -> Float		{ return 0; }
	};
	
	auto	delegate() const -> Delegate*;
	auto	setDelegate(Delegate*) -> void;
	auto	unsetDelegate() -> void;
	
	auto	addTableColumn(TableColumn) -> void;
	auto	removeTableColumn(TableColumn) -> void;
//	auto	createTableColumn() -> TableColumn*;
//	auto	createTableColumn(TableColumn&&) -> TableColumn*;
//	auto	deleteTableColumn(TableColumn*) -> void;
	
	auto	beginUpdates() -> void;
	auto	endUpdates() -> void;
};








EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
