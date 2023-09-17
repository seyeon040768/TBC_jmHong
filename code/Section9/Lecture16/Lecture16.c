#include <stdio.h>

int main(void)
{
	int a = 3, b = 5, c = 7, d = 9;
	int* aPtr = &a, * bPtr = &b, * cPtr = &c, dPtr = &d;

	printf("%p %p %p %p\n", &a, &b, &c, &d);

	return 0;
}