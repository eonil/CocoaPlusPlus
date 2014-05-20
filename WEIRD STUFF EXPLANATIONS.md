WEIRD STUFF EXPLANATIONS
========================











Why do you pass some parameters as `&` or `const&`?
---------------------------------------------------
All classes are semantically a pointer.
Marking them `const` really doesn't make it const-covariant.
In this library, all the class instances will be passed by value-copy.

Sometimes, parameters may be passed as a reference to allow mutual class name reference.
For example, we cannot use this due to unknown names.

	class	
	AAA
	{
	public:
		auto	test1(BBB bbb);		//	Compile error.
	};
	class
	BBB
	{
	public:
		auto	test1(AAA aaa);
	};

Ths only solution is passing by reference.

	class	AAA;
	class	BBB;

	class	
	AAA
	{
	public:
		auto	test1(BBB& bbb);		//	Compile error.
	};
	class
	BBB
	{
	public:
		auto	test1(AAA& aaa);
	};

Anyway sometimes, they will be passed by const or non-const reference, and that's because
to allow inline object instantiation via C++'s const-reference lifetime extension feature.

For example, we cannot put inline string object here.

	auto	test1(String) -> void;

	test1(String("foo!"));		//	Compile error.

But if we pass them as `const&`, inline object will be allowed.

	auto	test1(String const&) -> void;

	test1(String("foo!"));		//	OK.

Because the classes are pointers, the `const` does nothing on const-covariance. This library
is follows Cocoa conventions, and there's no const-covariance support. You need to use explicit
mutable version classes.

Also, nice compilers will pass the pointer itself directly by eliding any unnecessary referencing.
Most methods are very short, and highly expected to be inlined.

























Why is there no direct method overriding?
----------------------------------------
First, the classes just a pointer wrapper, it's simple impossible to provide method overriding
at the pointer level. The `this` pointer doesn't point actual Objective-C object.

Method overriding is a real bad practice unless the method is pure virtual. (abstract/interface)
I removed all the method overriding intentionally, and converted them all into observer pattern.
Instead of method overriding, these stuffs will be provided.

-	Installable hooks. (instead of method overriding)
-	Event observer. (for delegate)
-	Callback lambda. (for target-action)

You supply hooking map when creating an object, and the hooks will be called when the method is being called.
I know this design has some limitation, but this provides far better robustness.











































