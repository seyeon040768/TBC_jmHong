#include <stdio.h>

int main(void)
{
	int x = 1, y = 2, z;

	x > y + 2;
	x > (y + 2);

	x = y > 2;
	x = (y + 2);

	z = x > y;
	z = (x > y);

	x != y == z;
	(x != y) == z;

	return 0;
}