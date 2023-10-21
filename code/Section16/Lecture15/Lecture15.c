#include <stdio.h>
#include <assert.h> // assert, static_assert

int Divide(int a, int b);

int main(void)
{
	int a, b;
	int f = scanf("%d %d", &a, &b);

	printf("a / b = %d\n", Divide(a, b));

	return 0;
}

int Divide(int a, int b)
{
	assert(b != 0);
	//static_assert(1 == 0);

	return a / b;
}