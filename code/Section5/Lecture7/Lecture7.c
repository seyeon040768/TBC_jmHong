#include <stdio.h>

int main(void)
{
	int seconds = 0, minutes = 0, hours = 0;

	printf("Input seconds: ");
	scanf("%d", &seconds);

	while (seconds >= 0)
	{
		hours = seconds / 3600;
		seconds %= 3600;

		minutes = seconds / 60;
		seconds %= 60;

		printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

		printf("Input seconds: ");
		scanf("%d", &seconds);
	}

	printf("Good bye\n");

	int div, mod;

	div = 11 / 5;
	mod = 11 % 5;
	printf("div = %d, mod = %d\n", div, mod); // div = 2, mod = 1

	div = 11 / -5;
	mod = 11 % -5;
	printf("div = %d, mod = %d\n", div, mod); // div = -2, mod = 1

	div = -11 / 5;
	mod = -11 % -5;
	printf("div = %d, mod = %d\n", div, mod); // div = -2, mod = -1
	div = -11 / 5;
	mod = -11 % 5;
	printf("div = %d, mod = %d\n", div, mod); // div = -2, mod = -1

	return 0;
}