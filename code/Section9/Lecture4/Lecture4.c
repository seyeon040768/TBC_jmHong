#include <stdio.h>

int int_max(int i, int j)
{
	int m;
	m = (i > j) ? i : j;
	return m;
}

int main(void)
{
	int a;

	a = int_max(1, 2);

	printf("%d\n", a); // 2
	printf("%p\n", &a); // 0000001BA6AFFBD4

	{
		int a;
		a = int_max(4, 5);

		printf("%d\n", a); // 5
		printf("%p\n", &a); // 0000001BA6AFFBF4

		int b = 123;
	}

	printf("%d\n", a); // 2
	printf("%p\n", &a); // 0000001BA6AFFBD4

	return 0;
}