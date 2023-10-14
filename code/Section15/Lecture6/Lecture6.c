#include <stdio.h>

void PrintBinary(const int num);

int main(void)
{
	printf("%hhd\n", 1 << 3); // 8 00000001 -> 00001000
	printf("%hhd\n", 8 >> 1); // 4 00001000 -> 00000100

	printf("%hhd\n", -119 >> 3); // -15 10001001 -> 11110001
	printf("%hhu\n", 137 >> 3); // 17 10001001 -> 00010001

	printf("%hhd\n", -119 << 4); // -112 10001001 -> 10010000
	printf("%hhu\n", 137 << 4); // 144 10001001 -> 10010000


	int a = 1;
	a <<= 3;
	a >>= 2;


	printf("Unsigned int %u\n", 0xffffffff); // Unsigned int 4294967295
	printf("Signed int %d\n", 0xffffffff); // Signed int -1
	PrintBinary(0xffffffff); // Decimal -1      == Binary 11111111111111111111111111111111
	printf("Right shift by 3\n"); // Right shift by 3
	PrintBinary((signed)0xffffffff >> 3); // Decimal -1      == Binary 11111111111111111111111111111111
	PrintBinary((unsigned)0xffffffff >> 3); // Decimal 536870911       == Binary 00011111111111111111111111111111

	printf("\nUnsigned int %u\n", 0x00ffffff); // Unsigned int 16777215
	printf("Signed int %d\n", 0x00ffffff); // Signed int 16777215
	PrintBinary(0x00ffffff); // Decimal 16777215        == Binary 00000000111111111111111111111111
	printf("Right shift by 3\n"); // Right shift by 3
	PrintBinary((signed)0x00ffffff >> 3); // Decimal 2097151 == Binary 00000000000111111111111111111111
	PrintBinary((unsigned)0x00ffffff >> 3); // Decimal 2097151 == Binary 00000000000111111111111111111111

	return 0;
}

void PrintBinary(const int num)
{
	size_t bits = sizeof(num) * 8;

	printf("Decimal\t%d\t== Binary ", num);

	for (size_t i = 0; i < bits; ++i)
	{
		const int bitmask = 1 << (bits - 1 - i);
		printf("%d", (num & bitmask) == bitmask);
	}
	printf("\n");
}