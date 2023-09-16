#include <stdio.h>

void MyFunc(int);

int main(void)
{
	MyFunc(1);

	return 0;
}

void MyFunc(int n)
{
	printf("Level %d, address of variable n = %d\n", n, &n);

	if (n < 4)
	{
		MyFunc(n + 1);
	}

	printf("Level %d, address of variable n = %d\n", n, &n);
}