#include <stdio.h>

#define STRLEN 81

char* CustomStringInput(char* st, int n);

int main(void)
{
	/*// char* name = ""; // Error at run-time when using scanf
	char name[128];
	int result = scanf("%s", name);*/


	/*char words[STRLEN] = "";
	// gets(words); // no idea when string ends.
	gets_s(words, sizeof(words)); // C11
	printf("START\n");
	printf("%s", words);
	puts(words);
	puts("END.");*/


	/*char words[STRLEN] = "";
	fgets(words, STRLEN, stdin);

	int i = 0;
	while (words[i] != '\0')
	{
		if (words[i] == '\n')
		{
			words[i] = '\0';
		}
		++i;
	}

	fputs(words, stdout);
	fputs("END", stdout);*/


	/*char smallArray[5];
	puts("Enter long strings:");
	//fgets(smallArray, 5, stdin);
	printf("%p\n", smallArray);
	printf("%p\n", fgets(smallArray, 5, stdin)); // 정상적 문자열: smallArray 주소, EOF: 0000000000000000
	fputs(smallArray, stdout);*/


	/*char smallArray[5];
	puts("Enter long strings:");
	while (fgets(smallArray, 5, stdin) != NULL && smallArray[0] != '\n')
	{
		fputs(smallArray, stdout);
		// puts(smallArray);
	}*/


	/*char str1[6], str2[6];
	int count = scanf("%5s %5s", str1, str2);
	// int count = scanf("%6s %6s", str1, str2); // run-time error
	// int count = scanf_s("%5s %5s", str1, 6, str2, 6);
	printf("%s|%s\n", str1, str2);*/

	char word[11];
	puts(CustomStringInput(word, 11));

	return 0;
}

char* CustomStringInput(char* st, int n)
{
	char* retPtr;
	int i = 0;

	retPtr = fgets(st, n, stdin);
	if (retPtr)
	{
		while (st[i] != '\n' && st[i] != '\0')
		{
			++i;
		}
		if (st[i] == '\n')
		{
			st[i] = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}

	return retPtr;
}