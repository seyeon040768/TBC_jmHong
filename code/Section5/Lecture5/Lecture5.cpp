#include <stdio.h>

int main(void)
{
	printf("Integer divisions\n");
	printf("%d\n", 14 / 7); // 2
	printf("%d\n", 7 / 2); // 3
	printf("%d\n", 7 / 3); // 2
	printf("%d\n", 7 / 4); // 1
	printf("%d\n", 8 / 4); // 2

	printf("Truncating toward zero (C99)\n");
	printf("%d\n", -7 / 2); // -3
	printf("%d\n", -7 / 3); // -2
	printf("%d\n", -7 / 4); // -1
	printf("%d\n", -8 / 4); // -2

	printf("\nFloating division\n");
	printf("%f\n", 9.0 / 4.0); // 2.250000
	printf("%f\n", 9.0 / 4); // 2.250000

	return 0;
}