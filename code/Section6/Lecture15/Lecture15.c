#include <stdio.h>

int main(void)
{
	int repeat_num = 5;
	char start_char = 'A';
	char end_char = 'K';

	for (int i = 0; i < repeat_num; i++)
	{
		for (char c = start_char; c <= end_char; c++)
		{
			printf("%c ", c);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < repeat_num; i++)
	{
		for (char c = start_char; c <= start_char + i; c++)
		{
			printf("%c ", c);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < repeat_num; i++)
	{
		for (char c = start_char + i; c < start_char + repeat_num; c++)
		{
			printf("%c ", c);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}