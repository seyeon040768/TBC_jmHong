#include <stdio.h>
#include <string.h>

void Swap(char** x, char** y);
void SelectionSort(char* arr[], int n);
void PrintStringArray(char* arr[], int size);

int main(void)
{
	char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
	int n = sizeof(arr) / sizeof(arr[0]);

	PrintStringArray(arr, n);

	SelectionSort(arr, n);

	PrintStringArray(arr, n);

	return 0;
}

void Swap(char** x, char** y)
{
	char* temp = *x;
	*x = *y;
	*y = temp;
}

void SelectionSort(char* arr[], int n)
{
	int minIndex;

	for (int i = 0; i < n - 1; ++i)
	{
		minIndex = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (strcmp(arr[j], arr[minIndex]) == -1)
			{
				minIndex = j;
			}
		}
		Swap(&arr[i], &arr[minIndex]);
	}
}

void PrintStringArray(char* arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%s\n", arr[i]);
	}
}