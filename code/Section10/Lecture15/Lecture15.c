#include <stdio.h>

int main(void)
{
	/*int n = 5;
	double x;
	x = n;
	int* p1 = &n;
	double* pd = &x;
	// pd = p1; // warning

	int* pt;
	int(*pa)[3];
	int ar1[2][3] = { 3, };
	int ar2[3][2] = { 7, };
	int** p2;

	pt = &ar1[0][0];
	pt = ar1[0];
	// pt = ar1; // warning

	pa = ar1;
	// pa = ar2; // warning

	p2 = &pt;
	*p2 = ar2[0];
	p2 = ar2; // warning
	// p2: pointer to pointer to int
	// ar2 pointer to array-of-2-ints*/


	/*int x = 20;
	const int y = 23;
	int* p1 = &x;
	const int* p2 = &y;
	const int** pp2 = &p1;
	p1 = p2; // warning

	// *p2 = 123; // Error
	p2 = p1;

	int x2 = 30;
	int* p3 = &x2;
	*pp2 = p3;
	pp2 = &p1;*/


	/* not good
	const int** pp2;
	int* p1;
	const int n = 13;
	pp2 = &p1;
	*pp2 = &n; // p1 = &n;
	*p1 = 10;*/

	const int y;
	const int* p2 = &y;
	int* p1;
	p1 = p2; // warning (Error in c++)

	return 0;
}