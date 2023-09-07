#include <stdio.h>

int main(void)
{
	char c = 'A';
	char d = 65; // 65 = 'A'

	printf("%c %hhd\n", c, c); // A 65
	printf("%c %hhd\n", d, d); // A 65

	printf("%c \n", c + 1); // bell

	char a = '\a';
	printf("%c", a); // B

	printf("\07"); // bell
	printf("\x23"); // #

	return 0;
}