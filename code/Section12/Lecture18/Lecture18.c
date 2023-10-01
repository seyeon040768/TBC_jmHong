﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	const const const int n = 6; // const int n = 6;

	typedef const int zip;
	const zip q = 8; // const const int zip

	//const int i; // NOT initialized!
	//i = 12; // Error
	//printf("%d\n", i); // Error

	const int j = 123;
	const int arr[] = { 1, 2, 3 };

	
	float f1 = 3.14f, f2 = 1.2f;

	const float* pf1 = &f1;
	//*pf1 = 5.0f; // Error
	pf1 = &f2;

	float* const pf2 = &f1;
	*pf2 = 6.0f;
	//pf2 = &f2; // Error

	const float* const pf3 = &f1;
	//*pf3 = 7.0f; // Error
	//pf3 = &pf2; // Error


	volatile int vi = 1;
	volatile int* pvi = &vi;

	int i1 = vi;

	// ...

	int i2 = vi;


	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* par = ar;

	int* __restrict restar = (int*)malloc(10 * sizeof(int));
	if (!restar)
	{
		exit(EXIT_FAILURE);
	}

	ar[0] += 3;
	par[0] += 5;
	// par[0] += 8;

	restar[0] += 3;
	restar[0] += 5;
	// restar[0] += 8; // Equalivalent

	return 0;
}