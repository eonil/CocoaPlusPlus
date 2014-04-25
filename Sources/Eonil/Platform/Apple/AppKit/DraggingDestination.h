//
//  DraggingDestination.h
//  Cocoa++
//
//  Created by Hoon H. on 14/4/25.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once

#include "../Common.h"
#include "../ObjectiveC/Any.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN







enum class
DRAG_OPERATION : UInteger
{
	NONE		=	0,
	COPY		=	1,
	LINK		=	2,
	GENERIC		=	4,
	PRIVATE		=	8,
	MOVE		=	16,
	DELETE		=	32,
	EVERY		=	UIntegerMax,
};


class
DraggingInfo : protected Any
{
public:
	using	Any::Any;

public:
	
public:
	auto	draggingPasteboard() const -> Pasteboard;
//	auto	draggingSequenceNumber() const -> Integer;
	auto	draggingSource() const -> Any;
};




/*!
 Wraps `NSDraggingDestination` protocol.
 */
struct
DraggingDestination
{
	virtual auto	draggingEntered(DraggingInfo info) -> DRAG_OPERATION	{	return	DRAG_OPERATION::NONE;	};
	virtual auto	draggingUpdated(DraggingInfo info) -> DRAG_OPERATION	{	return	DRAG_OPERATION::NONE;	};
	virtual auto	draggingEnded(DraggingInfo info) -> void				{};
	virtual auto	draggingExited(DraggingInfo info) -> void				{};
	
	virtual auto	prepareForDragOperation(DraggingInfo info) -> bool		{	return	false;	};
	virtual auto	performDragOperation(DraggingInfo info) -> bool			{	return	false;	};
	virtual auto	concludeDragOperation(DraggingInfo info) -> void		{};
	
	virtual auto	updateDraggingItemsForDrag(DraggingInfo info) -> void	{};
};









EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END