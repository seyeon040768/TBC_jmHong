#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void PrintBinary(const char num);

int main(void)
{
	PrintBinary(127); // Decimal 127     == Binary 01111111
	PrintBinary(-127); // Decimal -127    == Binary 10000001
	PrintBinary(~127 + 1); // Decimal -127    == Binary 10000001

	PrintBinary(12); // Decimal 12      == Binary 00001100
	PrintBinary(-12); // Decimal -12     == Binary 11110100
	PrintBinary(~12 + 1); // Decimal -12     == Binary 11110100

	PrintBinary(-7); // Decimal -7      == Binary 11111001
	PrintBinary(7); // Decimal 7       == Binary 00000111
	PrintBinary(~- 7 + 1); // Decimal 7       == Binary 00000111

	return 0;
}

void PrintBinary(const char num)
{
	size_t bits = sizeof(num) * 8;

	printf("Decimal\t%d\t== Binary ", num);

	for (size_t i = 0; i < bits; ++i)
	{
		const char bitmask = (char)pow(2, bits - 1 - i);
		printf("%d", (num & bitmask) == bitmask);
	}
	printf("\n");
}