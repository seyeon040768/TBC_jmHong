#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;

	while ((ch = getchar()) != '\n')
	{
		if (isdigit(ch))
		{
			ch = '*';
		}

		if (islower(ch))
		{
			ch = toupper(ch);
		}
		else if (isupper(ch))
		{
			ch = tolower(ch);
		}

		putchar(ch);
	}

	return 0;
}