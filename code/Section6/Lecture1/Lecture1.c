#include <stdio.h>

int main(void)
{
	int n, sum = 0;

	printf("Enter an integer (q to quit): ");

	while (scanf("%d", &n) == 1)
	{
		sum += n;

		printf("Enter next integer (q to quit): ");
	}

	printf("Sum = %d\n", sum);

	return 0;
}