#include <stdio.h>

int main(void)
{
	int* ap[10];

	typedef int* pint;
	pint ap2[10];

	float* fp(float);

	typedef float* pfloat;
	pfloat fp2(float);

	void (*pf)(int);

	int* (*x[10])(void);

	
	// A function can't return an array
	// int f(int)[]; // Wrong
	
	// BUT it can return a pointer to a function
	int(*f(int))[];

	// A function can't return a function
	// int g(int)(int);

	// BUT it can return a pointer to a function
	int (*g(int))(int);

	// An array of functions aren't possible
	// int a[10](int);

	// But an array of function pointers are possible
	int (*x2[10])(int);


	typedef int FCN(int);
	typedef FCN* FCN_PTR;
	typedef FCN_PTR FCN_PTR_ARRAY[10];
	FCN_PTR_ARRAY x3;


	int board[6][4];
	int** ptr;

	int* risks[10];
	int(*rusk)[10];

	int* off[3][4];
	int(*uff)[3][4];
	int(*uof[3])[4];

	char* fump(int);
	char (*frump)(int);
	char (*flump[3])(int);

	typedef int Arr5[5];
	typedef Arr5* Parr5;
	typedef Parr5 Parr10[10];

	Arr5 togs;
	Parr5 p2;
	Parr10 arp;

	return 0;
}