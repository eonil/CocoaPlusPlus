DESIGN PRINCIPALS
=================








-	For convenience. Not for performance.

	This library is designed to provide better and earlier error check and organization.
	Not for performance. 
	
	Major reason of this library is avoiding mistakes. Objective-C is too much mistake-prone
	language, and overriding a method by mistake is too easy, and there's no warning.
	As a result, managing those feature overriding are very hard.






-	Treat object as an object.

	Though these objects are wrapping an Objective-C object pointer, they don't work like a pointer.
	They reflect underlying objective behaviors.

	If you copy the object, it will actually perform copying of the underlying object by calling `copy`
	method. If you perform equality comparison, then it will invoke `isEqual:` method.





-	All wrapper classes are just thin wrappers around pointers to Objective-C objects.
	Conceptually, a class is something like this;
	
		typedef		NSView*		View;
		
	or something like this;
	
		class
		View
		{
			NSView*			_raw_ptr{nullptr};
		};


	Then, copy is bare pointer copy, not a semantic deep copy. If you want to perform semantic copy then
	you have you call `copy` method just like an Objective-C object.

	Anyway, unlike Objective-C, copy method is not implemented by default. This is formal convention to name
	semantic copy method as `copy`, so you can call the method just if a class has it.





-	Classes wrapping `CFType` objects are also just a pointer wrapper.
	Conceptually, a `CFType` wrappers are something like this;

		typedef		CGColorRef		Color;


	Or;

		class
		Color
		{
			CGColorRef		_raw_ptr{nullptr};
		};







-	Type Check.
	`CFType` based classes are checked by imported CoreFoundation C symbols.
	Objective-C classes are not checked when creating yet, but will be checked
	when calling any method. This is mainly to avoid importing Objective-C symbols.
	Type-check can be added later using forward declaration trick.











Keep it simple by decomposing each features
-------------------------------------------



-	Base classes are not exposed directly by default.
	
	To keep simplicity, all base class functionalities will not be exposed directly.
	Instead, every classes will have `as~` series method to provide access to base class features.
	Where appropriate, some base class features may be exposed directly. This is fully case-by-case, but hiding is the default choice.



-	No direct overriding.

	If you want to override a method, you should subclass correspoding `Observer` class,
	and set it to the instance.
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
