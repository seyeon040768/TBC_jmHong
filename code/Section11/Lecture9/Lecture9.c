#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_LIMIT 1024

void ToUpper(char*);
int PunctCount(const char*);

int main(void)
{
	char line[NUM_LIMIT];
	char* newLine = NULL;

	fgets(line, NUM_LIMIT, stdin);

	newLine = strchr(line, '\n');
	if (newLine)
	{
		*newLine = '\0';
	}

	ToUpper(line);
	puts(line);
	printf("%d\n", PunctCount(line));
}

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		++str;
	}
}

int PunctCount(const char* str)
{
	int ct = 0;
	while (*str)
	{
		if (ispunct(*str))
		{
			++ct;
		}
		++str;
	}

	return ct;
}