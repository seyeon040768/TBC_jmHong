#include <stdio.h>
#include <stdbool.h>

#define STOP '.'

int main(void)
{
	char ch;
	int numCharacters = 0;
	int numWords = 0;
	int numLines = 0;
	bool bWord = false;
	bool bLine = false;

	printf("Enter text: ");

	while ((ch = getchar()) != STOP)
	{
		if (ch == ' ')
		{
			bWord = false;
		}
		else if (ch == '\n')
		{
			bWord = false;
			bLine = false;
		}
		else
		{
			++numCharacters;
			if (!bWord)
			{
				++numWords;
				bWord = true;
			}

			if (!bLine)
			{
				++numLines;
				bLine = true;
			}
		}
	}

	printf("Characters = %d, Words = %d, Lines = %d\n", numCharacters, numWords, numLines);

	return 0;
}