#include <stdio.h>

int main(void)
{
	int count = 0;

	while (1)
	{
		printf("Current count is %d. Continue? (y/n)\n", count);

		int c = getchar();

		if (c == 'n')
		{
			break;
		}
		else if (c == 'y')
		{
			++count;
		}
		else
		{
			printf("Please input y or n\n");
		}

		while (getchar() != '\n')
		{
			continue;
		}
	}

	return 0;
}