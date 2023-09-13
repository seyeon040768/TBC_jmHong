#include <stdio.h>

long GetLong(void);

int main(void)
{
	printf("Please input an integer between 1 and 100.\n");

	long number;

	while (1)
	{
		number = GetLong();

		if (number > 1 && number < 100)
		{
			printf("OK. Thank you.\n");
			break;
		}
		
		printf("Wrong input.\n");
	}

	return 0;
}

long GetLong(void)
{
	printf("Please input an integer and press enter.\n");

	long input;
	char c;

	while (scanf("%ld", &input) != 1)
	{
		printf("Your input - ");

		while ((c = getchar()) != '\n')
		{
			putchar(c);
		}

		printf(" - is not an integer. Thank you.\n");
	}

	printf("Your input %ld is an integer. Thank you.\n", input);

	return input;
}