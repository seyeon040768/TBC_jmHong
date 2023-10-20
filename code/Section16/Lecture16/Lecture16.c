#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memcpy(), memmove()

#define LEN 6

void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void)
{
	int arr1[LEN] = { 1, 3, 5, 7, 9, 11 };
	int* arr2 = (int*)malloc(LEN * sizeof(int));
	if (arr2 == NULL)
	{
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < LEN; ++i)
	{
		arr2[i] = arr1[i];
	}

	memcpy(arr2, arr1, sizeof(int) * LEN);
	PrintArray(arr2, LEN);


	/*
	{ 1, 3, 5, 7, 9, 11 }
	{ 5, 7, 9, 11, 9, 11 }
	arr[2], arr[3] overlapped
	*/
	//memcpy(arr1, &arr1[2], sizeof(int) * 4); // undefined behavior
	memmove(arr1, &arr1[2], sizeof(int) * 4);
	PrintArray(arr1, LEN);
}