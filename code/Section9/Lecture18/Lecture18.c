#include <stdio.h>

void swap(int* a, int* b)
{
	printf("%p %p\n", a, b);

	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int a = 123;
	int b = 456;

	printf("%p %p\n", &a, &b);

	swap(&a, &b);

	printf("%d %d\n", a, b);

	return 0;
}