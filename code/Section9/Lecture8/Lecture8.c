#include <stdio.h>

long LoopFactorial(int n);
long RecursiveFactorial(int n);

int main(void)
{
	int num = 5;

	printf("%d\n", LoopFactorial(num));
	printf("%d\n", RecursiveFactorial(num));

	return 0;
}

long LoopFactorial(int n)
{
	long ret = 1;

	while (n > 1)
	{
		ret *= n;
		--n;
	}

	return ret;
}

long RecursiveFactorial(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	return n * RecursiveFactorial(n - 1);
}