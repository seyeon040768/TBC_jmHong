#include <stdio.h>

int gInt = 123;

void Func(void)
{
	extern int gInt;

	gInt += 1;

	printf("gInt in Func() %d %p\n", gInt, &gInt);
}

void FuncSecond(void);
void Tool(void);

int main(void)
{
	Func();
	FuncSecond();

	// Tool(); // Error LNK2019

	return 0;
}