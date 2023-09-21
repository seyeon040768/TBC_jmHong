#include <stdio.h>

int main(void)
{
	const double PI = 3.14159;
	// PI = 2.14159;

	const int arr[5] = { 1, 2, 3, 4, 5 };
	// arr[1] = 123;

	const double arr2[3] = { 1.0, 2.0, 3.0 };
	// arr2[0] = 100.0;

	/*double* pd = arr2; // Warning C4090 'initializing': different 'const' qualifiers
	*pd = 3.0; // arr2[0] = 3.0과 유사
	pd[2] = 1024.0; // arr2[2] = 1024.0과 유사*/

	const double* pd = arr2;
	// *pd = 3.0;
	// pd[2] = 1024.0;

	printf("%f\n", pd[1]); // 2.0

	++pd; // allow when const double* pd = arr2;
	// const double* const pd = arr2; can prevent ++pd;

	printf("%f\n", pd[1]); // 3.0

	return 0;
}