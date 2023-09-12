#include <stdio.h>
#include <conio.h>

int main(void)
{
	char c;

	while ((c = getchar()) != '.')
	{
		putchar(c);
	}

	while ((c = _getche()) != '.')
	{
		putchar(c);
	}

	return 0;
}