#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

void CharToBinary(unsigned char uc)
{
	const int bits = CHAR_BIT * sizeof(unsigned char);
	for (int i = bits - 1; i >= 0; --i)
	{
		printf("%d", (uc >> i) & 1);
	}
}

void PrintBinary(char* data, int bytes)
{
	for (int i = 0; i < bytes; ++i)
	{
		CharToBinary(data[bytes - 1 - i]);
	}
	printf("\n");
}

int main(void)
{
	struct
	{
		bool option1 : 1;
		//bool : 0; // 2 bytes
		bool option2 : 1;
		//unsigned long long option3 : 1; // 16 bytes
	} bbf;

	/*memset((char*)&bbf, 0xff, sizeof(bbf));
	PrintBinary((char*)&bbf, sizeof(bbf));
	bbf.option1 = 1;
	bbf.option2 = 1;
	bbf.option3 = 0;
	PrintBinary((char*)&bbf, sizeof(bbf));*/

	printf("%zu bytes\n", sizeof(bbf)); // 1 bytes

	struct
	{
		unsigned short option1 : 8;
		unsigned short option2 : 7;
		//unsigned short : 0; // 4 bytes
		unsigned short option3 : 1;
	} usbf;

	printf("%zu bytes\n", sizeof(usbf)); // 2 bytes

	struct
	{
		unsigned int option1 : 1;
		//unsigned int : 0; // 8 bytes
		unsigned int option2 : 1;
	} uibf;

	printf("%zu bytes\n", sizeof(uibf)); // 4 bytes

	return 0;
}