#include <stdio.h>
#include <math.h>

#define MASK_SWORD (1 << 0)
#define MASK_SHIELD (1 << 1)
#define MASK_POTION (1 << 2)
#define MASK_GUNTLET (1 << 3)
#define MASK_HAMMER (1 << 4)
#define MASK_KEY (1 << 5)
#define MASK_RING (1 << 6)
#define MASK_AMULET (1 << 7)

void CharBinary(const char num);
void IntBinary(const int num);

int main(void)
{
	/*
	bool hasSword = false;
	bool hasShield = false;
	bool hasPotion = false;
	bool hasGuntlet = false;
	bool hasHammer = false;
	bool hasKey = false;
	bool hasRing = false;
	bool hasAmulet = false;
	*/

	char flags = 0;
	CharBinary(flags); // 00000000


	printf("\nTurning Bits On (Setting Bits)\n");

	flags = flags | MASK_SWORD;
	CharBinary(flags); // 00000001

	flags |= MASK_AMULET;
	CharBinary(flags); // 10000001


	printf("\nTurning Bits Off (Clearning Bits)\n");

	flags |= MASK_POTION;
	CharBinary(flags); // 10000101

	flags = flags & ~MASK_POTION;
	CharBinary(flags); // 10000001


	printf("\nToggling Bits\n");

	flags = flags ^ MASK_HAMMER;
	CharBinary(flags); // 10010001

	flags = flags ^ MASK_HAMMER;
	CharBinary(flags); // 10000001

	flags = flags ^ MASK_HAMMER;
	CharBinary(flags); // 10010001


	printf("\nChecking the Value of a Bit\n");

	if ((flags & MASK_KEY) == MASK_KEY)
	{
		printf(">> You can enter.\n");
	}
	else
	{
		printf(">> You can not enter.\n"); // >> You can not enter.
	}

	flags |= MASK_KEY;

	if ((flags & MASK_KEY) == MASK_KEY)
	{
		printf(">> You can enter.\n"); // >> You can enter.
	}
	else
	{
		printf(">> You can not enter.\n");
	}


	printf("\nTrimming\n");

	int intFlag = 0xffffffff;
	IntBinary(intFlag); // 11111111111111111111111111111111

	intFlag &= 0xff;
	IntBinary(intFlag); // 00000000000000000000000011111111

	return 0;
}

void CharBinary(const char num)
{
	size_t bits = sizeof(num) * 8;

	printf("Decimal\t%d\t== Binary ", num);

	for (size_t i = 0; i < bits; ++i)
	{
		const char bitmask = 1 << (bits - 1 - i);
		printf("%d", (num & bitmask) == bitmask);
	}
	printf("\n");
}

void IntBinary(const int num)
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