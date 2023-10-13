#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void PrintBinary(const unsigned char num);

int main(void)
{
	unsigned char a = 6;
	unsigned char b = 5;

	printf("%hhu\n", a); // 6
	PrintBinary(a); // Decimal 6       == Binary 00000110

	printf("%hhu\n", b); // 5
	PrintBinary(b); // Decimal 5       == Binary 00000101

	printf("%hhu\n", a & b); // 4
	PrintBinary(a & b); // Decimal 4       == Binary 00000100

	printf("%hhu\n", a | b); // 3
	PrintBinary(a | b); // Decimal 7       == Binary 00000111

	printf("%hhu\n", a ^ b); // 2
	PrintBinary(a ^ b); // Decimal 3       == Binary 00000011

	printf("%hhu\n", ~a); // 1
	PrintBinary(~a); // Decimal 249     == Binary 11111001

	return 0;
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