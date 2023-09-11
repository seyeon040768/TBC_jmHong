#include <stdio.h>

int main(void)
{
	int size = 15;
	int cost;

	if (size < 10)
	{
		goto a;
	}
	goto b;

a: cost = 50 * size;
b: cost = 100 * size;

	if (size < 10)
	{
		cost = 50 * size;
	}
	else
	{
		cost = 100 * size;
	}


	char c;

read: c = getchar();
	putchar(c);
	if (c == '.')
	{
		goto quit;
	}
	goto read;
quit:

	while (1)
	{
		c = getchar();
		putchar(c);
		if (c == '.')
		{
			break;
		}
	}

	return 0;
}