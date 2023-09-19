#include <stdio.h>

#define MONTHS 12

int main(void)
{
	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	for (int i = 0; i < MONTHS; ++i)
	{
		printf("%d ", high[i]);
	}
	printf("\n");

	float avg = 0.0;

	for (int i = 0; i < MONTHS; ++i)
	{
		avg += high[i];
	}
	printf("Average = %f\n", avg / MONTHS);

	high[0] = 1;
	high[1] = 2;
	// high = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }; // Not working

	printf("%p %p\n", high, &high[0]);

	for (int i = 0; i < MONTHS; ++i)
	{
		printf("%lld\n", (long long)&high[i]);
	}

	// high[12] = 4; // Error
	// high[-1] = 123; // Error


	const int temp = 0;
	// temp = 4; // Error
	const int low[12] = { -7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5 };
	// low[0] = 123; // Error


	int notInit[4];
	// static int notInit[4]; // storage class
	
	for (int i = 0; i < 4; ++i)
	{
		printf("%d\n", notInit[i]);
	}


	int insuff[4] = { 2, 4 }; // partially initialized

	for (int i = 0; i < 4; ++i)
	{
		printf("%d\n", insuff[i]); // 2 4 0 0
	}


	// int over[2] = { 2, 4, 8, 16 }; // Error, overlly initialized


	const int powerOfTwos[] = { 1, 2, 4, 8, 16, 32, 64 };
	printf("%d\n", sizeof(powerOfTwos));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(powerOfTwos[0]));

	for (int i = 0; i < sizeof powerOfTwos / sizeof powerOfTwos[0]; ++i)
	{
		printf("%d ", powerOfTwos[i]);
	}


	int days[MONTHS] = { 31, 28,[4] = 31, 30, 31,[1] = 29 }; // designated initializers
	for (int i = 0; i < MONTHS; ++i)
	{
		printf("%d ", days[i]);
	}


	int arr1[MONTHS];
	double arr2[123];
	float arr3[3 * 4 + 1];
	float arr4[sizeof(int) + 1];
	// float arr5[-10]; // No
	// float arr6[0]; // No
	// float arr7[1.5]; // No
	float arr8[(int)1.5];

	// int n = 8;
	// float arr9[n]; // variable-length array is optional from C11

	return 0;
}