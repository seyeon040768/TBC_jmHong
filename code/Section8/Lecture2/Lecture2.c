#include <stdio.h>

int main(void)
{
	int c;

	while ((c = getchar()) != EOF)
	{
		putchar(c);
	}

	while (1)
	{
		c = getchar();
		printf("%d\n", c);
		if (c == EOF)
		{
			break;
		}
	}

	return 0;
}