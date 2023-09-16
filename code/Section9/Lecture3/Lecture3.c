#include <stdio.h>

int int_min(int, int);

int main(void)
{
	int i1, i2;

	while (1)
	{
		printf("Input two integers: ");

		if (scanf("%d %d", &i1, &i2) != 2)
		{
			break;
		}

		int lesser = int_min(i1, i2);

		printf("The lesser of %d and %d is %d\n", i1, i2, lesser);
	}

	return 0;
}

int int_min(int i, int j)
{
	int min;

	if (i < j)
	{
		min = i;
	}
	else
	{
		min = j;
	}

	return min;

	// return (i < j) ? i : j;

	/*if (i < j)
	{
		return i;
	}

	return j;*/
}