#include <stdio.h>
#include <stdbool.h>

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

int main(void)
{
	itemsFlag.hasSword = 1;

	return 0;
}