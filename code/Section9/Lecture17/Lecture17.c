#include <stdio.h>

int main(void)
{
	char a;
	float b;
	double c;

	char* aPtr = &a;
	float* bPtr = &b;
	double* cPtr = &c;

	// x64 ±‚¡ÿ
	printf("%zd %zd %zd\n", sizeof(a), sizeof(b), sizeof(c)); // 1 4 8
	printf("%zd %zd %zd\n", sizeof(aPtr), sizeof(bPtr), sizeof(cPtr)); // 8 8 8
	printf("%zd %zd %zd\n", sizeof(&a), sizeof(&b), sizeof(&c)); // 8 8 8
	printf("%zd %zd %zd\n", sizeof(char*), sizeof(float*), sizeof(double*)); // 8 8 8

	return 0;
}