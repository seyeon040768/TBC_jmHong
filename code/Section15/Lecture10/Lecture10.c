#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

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
	struct Items
	{
		bool hasSword : 1;
		bool hasShield : 1;
		bool hasPotion : 1;
		bool hasGuntlet : 1;
		bool hasHammer : 1;
		bool hasKey : 1;
		bool hasRing : 1;
		bool hasAmulet : 1;
	} itemsFlag;

	itemsFlag.hasSword = true;
	itemsFlag.hasShield = 1;
	itemsFlag.hasPotion = 0;
	itemsFlag.hasGuntlet = 1;
	itemsFlag.hasHammer = 0;
	itemsFlag.hasKey = 0;
	itemsFlag.hasRing = 1;
	itemsFlag.hasAmulet = 0;

	printf("Size = %zd\n", sizeof(itemsFlag)); // Size = 1

	PrintBinary((char*)&itemsFlag, sizeof(itemsFlag)); // 01001011

	if (itemsFlag.hasKey == 1)
	{
		printf(">> You can enter.\n");
	}

	union
	{
		struct Items bf;
		unsigned char uc;
	} uniFlag;

	uniFlag.uc = 0;
	uniFlag.bf.hasAmulet = true;
	uniFlag.uc |= (1 << 5);
	PrintBinary((char*)&uniFlag, sizeof(uniFlag)); // 10100000

	uniFlag.bf.hasKey = false;
	PrintBinary((char*)&uniFlag, sizeof(uniFlag)); // 10000000


	// DOS example
	struct FileTime
	{
		unsigned int seconds : 5; // 2^5 = 32, (0 ~ 29) 30*2 seconds
		unsigned int minutes : 6; // 2^6 = 64, (0 ~ 59) 60 minutes
		unsigned int hours : 5; // 2^5 = 32, (0 ~ 23) 24 hours
	};

	struct FileDate
	{
		unsigned int day : 5; // 2^5 = 32, 1 ~ 31
		unsigned int month : 4; // 2^4 = 16, 1 ~ 12
		unsigned int year : 7; // 2^7 = 128, 1980 ~
	} fd;

	fd.day = 32;
	fd.month = 12;
	fd.year = 8;

	printf("Day %u, Month %u, Year %u\n", fd.day, fd.month, fd.year); // Day 0, Month 12, Year 8
	// scanf("%d", &fd.day); // Error

	return 0;
}