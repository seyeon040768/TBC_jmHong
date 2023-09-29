#include <stdio.h>

void Func(int k);

int main(void)
{
	auto int a; // auto: storage-class specifier
	a = 1024;

	int i = 1;
	int j = 2;

	printf("i %llu\n", (unsigned long long)&i); // i 761221085796

	{
		int i = 3; // name hiding
		printf("i %llu\n", (unsigned long long)&i); // i 761221085860

		printf("j = %d\n", j); // j = 2
	}

	printf("i %llu\n", (unsigned long long)&i); // i 761221085796

	
	for (int m = 1; m < 2; ++m)
	{
		printf("m %llu\n", (unsigned long long)&m); // m 761221085892
	}

	Func(5); // i 761221085476

	for (int m = 3; m < 4; ++m)
	{
		printf("m %llu\n", (unsigned long long)&m); // m 761221085924
	}

	return 0;
}

void Func(int k)
{
	int i = k * 2;
	printf("i %llu\n", (unsigned long long)&i);
}