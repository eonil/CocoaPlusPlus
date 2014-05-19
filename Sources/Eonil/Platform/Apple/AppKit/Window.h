//
//  Window.h
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#pragma once
#include "../Common.h"
#include "Responder.h"
#include "DraggingDestination.h"

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN




/*!
 Wraps `NSWindow`.
 Take care that you have to order to show the window.
 */
class
Window : Responder
{
public:
	enum class
	STYLE : UInteger
	{
		BORDERLESS				=	0,
		TITLED					=	1 << 0,
		CLOSABLE				=	1 << 1,
		MINIATURIZABLE			=	1 << 2,
		RESIZABLE				=	1 << 3,
		TEXTURED_BACKGROUND		=	1 << 8,
	};
	
	struct
	Delegate : Any, virtual DraggingDestination
	{
		Delegate();
		Delegate(Delegate const&) = delete;
		Delegate(Delegate&&) = delete;
		
		virtual inline auto		windowShouldClose(Window) -> bool		{ return NO; }
	};

public:
	using	Responder::Responder;
	
	static auto	window() -> Window;
	
public:
	auto	delegate() const -> Delegate*;
	auto	setDelegate(Delegate*) -> void;
	auto	unsetDelegate() -> void;
	
	auto	styleMask() const -> STYLE;
	auto	setStyleMask(STYLE) -> void;
	
	auto	isVisible() const -> bool;
	auto	orderOut() -> void;					//!	Hide the window.
	auto	orderFront() -> void;				//!	Show the window.
	
	auto	isKeyWindow() const -> bool;
	auto	makeKey() -> void;					//!	Become focused window.
	
	auto	frame() const -> Rect;
	auto	setFrame(Rect, bool animated) -> void;
	auto	setContentSize(Size) -> void;			//!	Resize by content size.
	
	auto	title() const -> Foundation::String;
	auto	setTitle(Foundation::String) -> void;
	auto	setTitleWithRepresentativeFilename(Foundation::String filename) -> void;
	
	auto	contentView() const -> View;
	auto	setContentView(View) -> void;
	
	/*!
	 See `Pasteboard::Type` for generic UTIs.
	 */
	auto	registerForDraggedTypes(vec<Foundation::String> const& UTIs) -> void;
	auto	unregisterDraggedTypes() -> void;
	
public:
	auto	asResponder() const -> Responder const&;
	auto	asResponder()  -> Responder&;
};

template <typename T>
inline auto
operator|(T const a, T const b) ->  T
{
	using	UT1	=	typename std::underlying_type<decltype(a)>::type;
	using	UT2	=	typename std::underlying_type<decltype(b)>::type;
    return static_cast<T>(static_cast<UT1>(a) | static_cast<UT2>(b));
}
template <typename T>
inline auto
operator&(T const a, T const b) ->  T
{
	using	UT1	=	typename std::underlying_type<decltype(a)>::type;
	using	UT2	=	typename std::underlying_type<decltype(b)>::type;
    return static_cast<T>(static_cast<UT1>(a) & static_cast<UT2>(b));
}

//inline auto
//operator|(Window::STYLE a, Window::STYLE b) ->  Window::STYLE
//{
//	using	UT1	=	typename std::underlying_type<decltype(a)>::type;
//	using	UT2	=	typename std::underlying_type<decltype(b)>::type;
//    return static_cast<Window::STYLE>(static_cast<UT1>(a) | static_cast<UT2>(b));
//}




///*!
// If you want to override some methods of a window, you should use this class.
// */
//class
//OverridableWindow : public Window
//{
//public:
//	struct
//	Observer
//	{
//		virtual auto	didResize() -> void;
//	};
//	
//public:
//	OverridableWindow();
//	
//	auto	setObserver(Observer*) -> void;
//
//private:
//	struct			Extras;
//	sptr<Extras>	_extras	{};
//};









EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
