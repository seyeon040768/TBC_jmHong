#include <stdio.h>
#include <ctype.h>

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		++str;
	}
}

void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		++str;
	}
}

void UpdateString(char* str, int(*pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		++str;
	}
}

int main(void)
{
	char str[] = "Hello, World!";

	void (*pf)(char*);

	pf = ToUpper;
	// pf = &ToUpper;
	// pf = ToUpper(str); // Not acceptible in C

	printf("String literal %llu\n", (unsigned long long)("Hello, World!")); // String literal 140698965486760
	printf("Function pointer %llu\n", (unsigned long long)ToUpper); // Function pointer 140698965447066
	printf("Variable %llu\n", (unsigned long long)str); // Variable 343218845144

	(*pf)(str); // ToUpper(str);
	// pf(str);

	printf("ToUpper %s\n", str); // ToUpper HELLO, WORLD!

	pf = ToLower;

	(*pf)(str);

	printf("ToLower %s\n", str); // ToLower hello, world!


	UpdateString(str, toupper);

	printf("ToUpper %s\n", str); // ToUpper HELLO, WORLD!

	UpdateString(str, tolower);

	printf("ToLower %s\n", str); // ToLower hello, world!

	return 0;
}