#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 10; ++i)
	{
		if (i == 5)
		{
			continue;
		}

		printf("%d ", i); // 0 1 2 3 4 6 7 8 9
	}

	/*for (int i = 0; i < 10; ++i)
	{
		if (i != 5)
		{
			printf("%d ", i); // 0 1 2 3 4 6 7 8 9
		}
	}*/

	printf("\n");

	for (int i = 0; i < 10; ++i)
	{
		if (i == 5)
		{
			break;
		}

		printf("%d ", i); // 0 1 2 3 4
	}

	printf("\n");

	int count = 0;
	while (count < 5)
	{
		int c = getchar();

		if (c == 'a')
		{
			continue;
		}

		putchar(c);

		++count;
	}

	printf("\n");

	for (int i = 0; i < 10; ++i)
	{
		int c = getchar();

		if (c == 'a')
		{
			continue;
		}

		putchar(c);
	}

	// continue as placeholder
	while (getchar() != '\n')
	{
		continue;
	}

	char c;
	while ((c = getchar()) != '\n')
	{
		if (c == 'a')
		{
			continue;
		}

		putchar(c);
	}

	while (1)
	{
		char ch = getchar();

		if (ch == '.')
		{
			break;
		}

		putchar(ch);
	}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (j == 5)
			{
				break;
			}

			printf("(%d %d)", i, j);
		}

		printf("\n");
	}

	return 0;
}