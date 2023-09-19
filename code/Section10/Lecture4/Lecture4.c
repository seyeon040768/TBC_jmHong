#include <stdio.h>

int main(void)
{
	int arr[10];

	int num = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < num; ++i)
	{
		arr[i] = (i + 1) * 100;
	}

	int* ptr = arr;

	printf("%p %p %p\n", ptr, arr, &arr[0]); // 0000001E904FF4A8 0000001E904FF4A8 0000001E904FF4A8

	ptr += 2;

	printf("%p %p %p\n", ptr, arr + 2, &arr[2]); // 0000001E904FF4B0 0000001E904FF4B0 0000001E904FF4B0

	// arr += 2; // invalid

	printf("%d %d %d\n", *(ptr + 1), *(arr + 3), arr[3]); // 400 400 400

	// warning
	printf("%d %d %d\n", *ptr + 1, *arr + 3, arr[3]); // 301 103 400

	ptr = arr;
	for (int i = 0; i < num; ++i)
	{
		// printf("%d %d\n", *ptr++, arr[i]);
		// printf("%d %d\n", *(ptr + i), arr[i]);
		printf("%d %d\n", *ptr + i, arr[i]);
	}

	return 0;
}