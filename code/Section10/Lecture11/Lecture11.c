#include <stdio.h>

void PrintArray(const int arr[], const int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void AddValue(int arr[], const int n, const int val)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		arr[i] += val;
	}
}

int Sum(const int arr[], const int n)
{
	int i;
	int total = 0;

	for (i = 0; i < n; ++i)
	{
		total += arr[i];
		// ++arr[i]; // wrong implementation
	}

	return total;
}

int main(void)
{
	int arr[] = { 1, 2, 3, 4, 5 };
	// const int arr[] = { 1, 2, 3, 4, 5 }; // warning at AddValue function
	const int n = sizeof(arr) / sizeof(arr[0]);

	PrintArray(arr, n); // 1 2 3 4 5
	AddValue(arr, n, 100);
	PrintArray(arr, n); // 101 102 103 104 105

	int sum = Sum(arr, n);

	printf("sum is %d\n", sum); // sum is 515
	PrintArray(arr, n); // 101 102 103 104 105

	return 0;
}