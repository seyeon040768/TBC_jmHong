#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void UpdateString(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);

int main(void)
{
	char input[100];
	char option;
	char options[] = { 'u', 'l', 't'};
	int n = sizeof(options) / sizeof(char);

	typedef void (*FUNC_TYPE)(char*);
	FUNC_TYPE operations[] = { ToUpper, ToLower, Transpose };

	printf("Enter a string\n");
	printf(">>");


	while (scanf("%[^\n]*c", input) != 1)
	{
		printf("Please try again.\n");
		printf(">>");

		while (getchar() != '\n')
		{
			continue;
		}
	}

	while (true)
	{
		bool isFound = false;

		printf("Choose an option:\n");
		printf("%c) to upper\n", options[0]);
		printf("%c) to lower\n", options[1]);
		printf("%c) to transpose\n", options[2]);

		while (scanf("%c%*[^\n]%*c", &option) != 1)
		{
			printf("Please try again.\n");
		}

		for (int i = 0; i < n; ++i)
		{
			if (option == options[i])
			{
				(*operations[i])(input);
				isFound = true;
				break;
			}
		}

		if (isFound)
		{
			break;
		}
		else
		{
			printf("Wrong input. Try again\n");
		}
	}

	printf("%s\n", input);

	return 0;
}

void UpdateString(char* str, int(*pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		++str;
	}
}

void ToUpper(char* str)
{
	UpdateString(str, toupper);
}

void ToLower(char* str)
{
	UpdateString(str, tolower);
}

void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
		{
			*str = toupper(*str);
		}
		else if (isupper(*str))
		{
			*str = tolower(*str);
		}
		++str;
	}
}