#include <stdio.h>

/* 입력 배열의 크기가 다르다면?
double average(double arr[5])
{
	printf("Size = %zd in function average\n", sizeof(arr)); // x86: 4, x64: 8

	double avg = 0.0;
	for (int i = 0; i < 5; ++i)
	{
		avg += arr[i];
	}
	avg /= 5.0;

	return avg;
}*/

/*
* double average(double* arr, int n);
* double average(double*, int n);
* double average(double arr[], int n);
* double average(double [], int n);
*/

double average(double*, int n);


double average(double* arr, int n)
{
	double avg = 0.0;
	for (int i = 0; i < n; ++i)
	{
		avg += arr[i];
	}
	avg /= n;

	return avg;
}

int main(void)
{
	double arr1[5] = { 10, 13, 12, 7, 8 };
	//double arr2[5] = { 1.8, -0.2, 6.3, 12.9, 20.5 };
	double arr2[3] = { 1.8, -0.2, 6.3 };

	printf("Address = %p\n", arr1);
	printf("Size = %zd\n", sizeof(arr1));

	/*double avg = 0.0;
	for (int i = 0; i < 5; ++i)
	{
		avg += arr1[i];
	}
	avg /= 5.0;

	printf("Avg = %f\n", avg);*/

	printf("Avg = %f\n", average(arr1, 5));
	printf("Avg = %f\n", average(arr2, 3));


	return 0;
}