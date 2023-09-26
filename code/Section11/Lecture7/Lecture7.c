#include <stdio.h>

void Swap(int* x, int* y);
void PrintArray(int arr[], int size);
void SelectionSort(int arr[], int n);

int main(void)
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	SelectionSort(arr, n);

	PrintArray(arr, n);

	return 0;
}

void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void SelectionSort(int arr[], int n)
{
	int minIndex;

	for (int i = 0; i < n - 1; ++i)
	{
		minIndex = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		Swap(&arr[i], &arr[minIndex]);
	}
}