#include <stdio.h>

extern int gInt;

static void Tool(void)
{
	// do something
}

void FuncSecond(void)
{
	Tool();

	gInt += 1;
	printf("gInt in FuncSecond() %d %p\n", gInt, &gInt);
}