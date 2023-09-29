#include <stdio.h>

// extern int gInt; // linking error LNK2001
int gInt;

void FuncSecond(void)
{
	gInt += 1;
	printf("gInt in FuncSecond() %d %p\n", gInt, &gInt);
}