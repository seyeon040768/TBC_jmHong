#include <stdio.h>

void Temp(register int r)
{
	// do something
}

int main(void)
{
	register int r;
	r = 123;

	int* ptr = &r; // Error C2103 '&' on register variable

	return 0;
}