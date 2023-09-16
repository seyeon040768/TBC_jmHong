#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH 20
#define NAME "Seyeon Lee"
#define ADDRESS "Seoul, Korea"

void PrintMultipleChars(char c, int num, bool printNewline); // prototype

void PrintCenteredStr(char[]); // only type

int main(void)
{
	int nBlanks = 0;

	PrintMultipleChars('*', WIDTH, true);

	PrintCenteredStr(NAME);
	PrintCenteredStr(ADDRESS);

	PrintMultipleChars('*', WIDTH, true);

	return 0;
}

void PrintMultipleChars(char c, int num, bool printNewline)
{
	for (int i = 0; i < num; ++i)
	{
		printf("%c", c);
	}

	if (printNewline)
	{
		printf("\n");
	}
}

void PrintCenteredStr(char str[])
{
	int nBlanks;

	nBlanks = (WIDTH - strlen(str)) / 2;
	PrintMultipleChars(' ', nBlanks, false);

	printf("%s\n", str);
}