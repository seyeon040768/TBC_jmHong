#include <stdio.h>

void iAmFunction()
{
	;
}

int a = 123;

int main(void)
{
	{
		int myName = 345;
		//double myName = 3.14; // Error
	}

	struct rect { double x; double y; };

	struct rect rect = { 1.1, 2.2 }; // struct rect and rect are in different categories

	//typedef struct rect rect;
	//rect rect = { 1.1, 2.2 }; // Error

	//int iAmFunction = iAmFunction(); // Error

	//printf("%d\n", a); // other.c

	return 0;
}