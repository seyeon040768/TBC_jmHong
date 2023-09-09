#include<stdio.h>

int main(void)
{
	/*
	* 1. Introduce getchar(), putchar()
	* 2. Use while loop to process character sequences
	* 3. Filter a specific character
	* 4. Convert numbers to asterisks
	* 5. Lower characters to Upper characters
	*/

	char ch;

	while ((ch = getchar()) != '\n')
	{
		/*if (ch == 'f' || ch == 'F')
		{
			ch = ' ';
		}*/

		/*if (ch >= '0' && ch <= '9')
		{
			ch = '*';
		}*/

		/*if (ch >= 'a' && ch <= 'z')
		{
			ch -= 'a' - 'A';
		}*/

		putchar(ch);
	}

	return 0;
}