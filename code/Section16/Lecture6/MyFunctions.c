#include "MyFunctions.h"

#include <stdio.h>

int status = 0;

int Add(int a, int b)
{
	return a + b;
}

void PrintStatus()
{
	printf("Address = %p, Value = %d\n", &status, status);
}

void PrintAddress()
{
	printf("PrintAddress()\n");
	printf("Static function address %p\n", Multiply);
	printf("Static variable address %p\n", &si);
}