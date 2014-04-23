//
//  View.cpp
//  Cocoa++
//
//  Created by Hoon H. on 4/20/14.
//  Copyright (c) 2014 Eonil. All rights reserved.
//

#include "View.h"
#include "../CoreGraphics/Rect.h"
#include "../CoreAnimation/Layer.h"


EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN

using namespace	CoreGraphics;





auto
View::view() -> View
{
	return	{[[NSView alloc] init]};
}

auto
View::frame() const -> Rect
{
	auto	self	=	get_objc_object<NSView>();
	return	[self frame];
}
auto
View::setFrame(Rect frame) -> void
{
	auto	self	=	get_objc_object<NSView>();
	[self setFrame:frame];
}

auto
View::addSubview(Eonil::CocoaCPP::AppKit::View o) -> void
{
	auto	self	=	get_objc_object<NSView>();
	[self addSubview:o];
}
auto
View::removeFromSuperview() -> void
{
	auto	self	=	get_objc_object<NSView>();
	[self removeFromSuperview];
}

auto
View::wantsLayer() const -> bool
{
	auto	self	=	get_objc_object<NSView>();
	return	[self wantsLayer];
}
auto
View::setWantsLayer(bool o) -> void
{
	auto	self	=	get_objc_object<NSView>();
	
	[self setWantsLayer:toOBJC(o)];
}

auto
View::layer() const -> CoreAnimation::Layer
{
	auto	self	=	get_objc_object<NSView>();
	return	[self layer];
}
auto
View::setLayer(CoreAnimation::Layer o) -> void
{
	EONIL_COCOA_DEBUG_ASSERT((o != nullptr and wantsLayer()) or o == nullptr);
	
	auto	self	=	get_objc_object<NSView>();
	
	[self setLayer:o];
}
//auto
//View::unsetLayer() -> void
//{
//	auto	self	=	get_objc_object<NSView>();
//	
//	[self setLayer:nil];
//}


EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END























using namespace	Eonil::CocoaCPP;
using namespace	Eonil::CocoaCPP::AppKit;

@interface	____CPP_Eonil_Cocoa_OverridableView1 : NSView
{
@public
	uptr<OverridableView::Behaviors>	overridings;
}
@end
@implementation ____CPP_Eonil_Cocoa_OverridableView1
- (void)viewDidMoveToSuperview
{
	[super viewDidMoveToSuperview];
	if (self->overridings != nullptr)
	{
		self->overridings->didMoveToSuperview();
	}
}
@end

EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_BEGIN

OverridableView::OverridableView(uptr<OverridableView::Behaviors>&&o) : View([[____CPP_Eonil_Cocoa_OverridableView1 alloc] init])
{
	__unsafe_unretained ____CPP_Eonil_Cocoa_OverridableView1*	v1	=	operator __unsafe_unretained id();
	EONIL_COCOA_ASSERT_OBJC_TYPE(v1, ____CPP_Eonil_Cocoa_OverridableView1);
	v1->overridings	=	std::move(o);
}

















EONIL_PLATFORM_APPLE_APPKIT_NAMESPACE_END
