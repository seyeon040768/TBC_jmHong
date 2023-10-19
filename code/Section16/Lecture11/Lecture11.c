#include <stdio.h>
#include "MyHeader.h"

/*
	Function call has overhead
	- set up the call, pass arguments, jump to the function code, and return.
	
	inline function specifier
	- Suggests inline replacements.
	
	Inline functions should be short.
	A function with internal linkage can be made inline. (GCC, clang)
	You can't take its address.
*/

inline int Foo()
{
	return 5;
}

int main(void)
{
	int ret;

	ret = Foo();

	printf("Output is: %d\n", ret);

	printf("%d\n", Func());
	
	return 0;
}