WEIRD STUFF EXPLANATIONS
========================










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











































