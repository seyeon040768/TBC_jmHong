#include <stdio.h>

static int gInt = 123;

void Func(void)
{
	extern int gInt;

	gInt += 1;

	printf("gInt in Func() %d %p\n", gInt, &gInt);
}

void FuncSecond(void);

int main(void)
{
	Func(); // gInt in Func() 124 00007FF78726C000
	FuncSecond(); // gInt in FuncSecond() 1 00007FF78726C8D8

	return 0;
}