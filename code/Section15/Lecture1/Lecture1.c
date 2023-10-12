#include <stdio.h>

int main(void)
{
	unsigned char a = 6; // 00000110
	unsigned char b = 5; // 00000101

	printf("%hhu\n", a & b); // 4 (a & b = 00000100)
	printf("%hhu\n", a | b); // 7 (a | b = 00000111)
	printf("%hhu\n", a ^ b); // 3 (a ^ b = 00000011)
	printf("%hhu\n", ~a); // 249 (~a = 11111011)

	return 0;
}