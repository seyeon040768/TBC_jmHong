#include <stdio.h>

int Fibonacci(int number);

int main(void)
{
	for (int count = 1; count < 13; ++count)
	{
		printf("%d ", Fibonacci(count));
	}

	return 0;
}

int Fibonacci(int number)
{
	if (number <= 2)
	{
		return 1;
	}

	return Fibonacci(number - 1) + Fibonacci(number - 2);
}