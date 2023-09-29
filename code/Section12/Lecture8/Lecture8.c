#include <stdio.h>

int gInt = 0;
double gArr[1000] = { 0.0, };

int x = 5; // constant expression
int y = 1 + 2; // constant expression
size_t z = sizeof(int); // constant expression
// int x2 = 2 * x; // not ok

void Func(void)
{
	printf("gInt in Func() %d %p\n", gInt, &gInt);
	gInt += 10;
}

void FuncSecond(void); // defined in Source.c

int main(void)
{
	extern int gInt; // Optional
	// extern int gInt = 1024; // Error in block scope

	// int gInt = 123; // Error redefinition when 'extern int gInt;'

	extern double gArr[]; // Optional

	printf("gInt in main() %d %p\n", gInt, &gInt); // gInt in main() 0 00007FF7E7D4C190
	gInt += 1;

	Func(); // gInt in Func() 1 00007FF7E7D4C190
	FuncSecond(); // gInt in FuncSecond() 18 00007FF7E7D4C190

	return 0;
}