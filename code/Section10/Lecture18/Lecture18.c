#include <stdio.h>

#define COLS 4

int sum1d(int arr[], int n);
int sum2d(int arr[][COLS], int rows);

int main(void)
{
	int a = 1;
	3; // Literals are constants that aren't symbolic(기호가 없는 리터럴 상수)
	3.14f;
	int b[2] = { 3, 4 };
	(int[2]) { 3, 4 };

	// int c[2] = (int[2]){ 3, 4 }; // Error

	int arr1[2] = { 1, 2 };
	int arr2[2][COLS] = { {1, 2, 3, 4}, {5, 6, 7, 8} };

	printf("%d\n", sum1d(arr1, 2)); // 3
	printf("%d\n", sum2d(arr2, 2)); // 36
	printf("\n");

	printf("%d\n", sum1d((int[2]) { 1, 2 }, 2)); // 3
	printf("%d\n", sum2d((int[2][COLS]) { {1, 2, 3, 4}, {5, 6, 7, 8} }, 2)); // 36
	printf("\n");

	int* ptr1;
	int(*ptr2)[COLS];

	ptr1 = (int[2]) { 1, 2 };
	ptr2 = (int[2][COLS]){ {1, 2, 3, 4}, {5, 6, 7, 8} };

	printf("%d\n", sum1d(ptr1, 2)); // 3
	printf("%d\n", sum2d(ptr2, 2)); // 36
	printf("\n");

	return 0;
}

int sum1d(int arr[], int n)
{
	int total = 0;
	for (int i = 0; i < n; ++i)
	{
		total += arr[i];
	}

	return total;
}

int sum2d(int arr[][COLS], int rows)
{
	int total = 0;
	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < COLS; ++c)
		{
			total += arr[r][c];
		}
	}

	return total;
}