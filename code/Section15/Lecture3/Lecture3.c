#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned char ToDecimal(const char bi[]);
void PrintBinary(const unsigned char num);

int main(void)
{
	unsigned char i = ToDecimal("01000110");
	unsigned char mask = ToDecimal("00000101");

	PrintBinary(i);
	PrintBinary(mask);
	PrintBinary(i & mask);

	return 0;
}

unsigned char ToDecimal(const char bi[])
{
	unsigned char power = 1;
	unsigned char num = 0;

	for (size_t i = strlen(bi); i > 0; --i)
	{
		unsigned char temp = bi[i - 1] - '0';
		if (temp != 0 && temp != 1)
		{
			exit(EXIT_FAILURE);
		}

		num += (bi[i - 1] - '0') * power;
		power *= 2;
	}

	return num;
}

void PrintBinary(const unsigned char num)
{
	size_t bits = sizeof(num) * 8;
	unsigned char bitmask = (unsigned char)pow(2, bits - 1);

	printf("Decimal\t%d\t== Binary ", num);

	for (size_t i = 0; i < bits; ++i)
	{
		printf("%d", (num & bitmask) == bitmask);
		bitmask /= 2;
	}
	printf("\n");
}