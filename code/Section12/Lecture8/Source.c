#include <stdio.h>

extern int gInt;

void FuncSecond(void)
{
	gInt += 7;
	printf("gInt in FuncSecond() %d %p\n", gInt, &gInt);
}