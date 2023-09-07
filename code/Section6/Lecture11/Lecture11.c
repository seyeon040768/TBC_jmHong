#include <stdio.h>

int main(void)
{
	for (int n = 1, nsqr = n * n; n < 10; n++, nsqr = n * n)
	{
		printf("%d %d\n", n, nsqr);
	}

	int i, j;
	i = 1;
	i++, j = i; // comma is a sequence point
	printf("%d %d\n", i, j); // 2 2

	int x, y, z;
	z = x = 1, y = 2;
	printf("x=%d, y=%d, z=%d \n", x, y, z); // 1 2 1
	z = (x = 1), (y = 2);
	printf("x=%d, y=%d, z=%d \n", x, y, z); // 1 2 1
	z = ((x = 1), (y = 2));
	printf("x=%d, y=%d, z=%d \n", x, y, z); // 1 2 2

	//int my_money = 123, 456; // error
	int my_money = (123, 456);
	printf("%d\n", my_money); // 456

	return 0;
}