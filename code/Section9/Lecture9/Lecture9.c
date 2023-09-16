#include <stdio.h>

void LoopPrintBinary(unsigned long n);
void RecursivePrintBinary(unsigned long n);

int main(void)
{
	unsigned long num = 12312345;

	LoopPrintBinary(num);
	printf("\n");

	RecursivePrintBinary(num);
	printf("\n");

	return 0;
}

void LoopPrintBinary(unsigned long n)
{
	int binaryInt[33];
	int i = 0;

	while (n > 0)
	{
		binaryInt[i] = n % 2;
		n /= 2;
		++i;
	}

	while (i > 0)
	{
		--i;
		printf("%d", binaryInt[i]);
	}
}

void RecursivePrintBinary(unsigned long n)
{
	if (n <= 1)
	{
		printf("%d", n);
		return;
	}

	RecursivePrintBinary(n / 2);
	printf("%d", n % 2);

	return;
}