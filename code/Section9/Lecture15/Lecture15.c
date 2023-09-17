#include <stdio.h>

int main(void)
{
	/*int a = 1234;
	printf("%p\n", &a);
	printf("%d\n", a);*/
	
	// runtime error
	/*int* ptr = 1234;
	printf("%p\n", ptr);
	printf("%d\n", *ptr);*/

	int* saferPtr = NULL;

	int a = 123;

	// saferPtr = &a;

	if (a % 2 == 0)
	{
		saferPtr = &a;
	}

	if (saferPtr != NULL)
	{
		printf("%p\n", saferPtr);
	}

	if (saferPtr != NULL)
	{
		printf("%d\n", *saferPtr);
	}

	return 0;
}