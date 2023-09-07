#include <stdio.h>

#define SIZE 5

int main(void)
{
	/*int i1 = 0;
	int i2 = 1;
	int i3 = 2;
	// ...

	printf("%d\n", i1);
	printf("%d\n", i2);
	printf("%d\n", i3);
	// ...

	int my_arr[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		my_arr[i] = i;
	}

	for (int i = 0; i < SIZE; i++a)
	{
		printf("%d ", my_arr[i]);
	}*/

	int numbers[SIZE];
	int sum = 0;

	printf("Enter %d numbers: ", SIZE);

	// for문은 분할하는 것이 성능에 더 좋다고 함(https://stackoverflow.com/questions/8547778/why-are-elementwise-additions-much-faster-in-separate-loops-than-in-a-combined-l)
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &numbers[i]);
	}

	for (int i = 0; i < SIZE; i++)
	{
		sum += numbers[i];
	}

	printf("Sum = %d\n", sum);

	return 0;
}