#include <stdio.h>

int main(void)
{
	int a = 0;
	a++;
	printf("%d\n", a); // 1

	++a;
	printf("%d\n", a); // 2

	double b = 0;
	b++;
	printf("%f\n", b); // 1.000000

	++b;
	printf("%f\n", b); // 2.000000

	int count = 0;
	while (count < 10)
	{
		printf("%d ", count);
		count++;
	}

	printf("\n");

	int i = 1, j = 1;
	int i_post, pre_j;

	i_post = i++;
	pre_j = ++j;

	printf("%d %d\n", i, j); // 2 2
	printf("%d %d\n", i_post, pre_j); // 1 2

	int k = 3;
	int l = 2 * --k;
	printf("%d %d\n", k, l); // 2 4

	k = 1;
	l = 2 * k--;
	printf("%d %d\n", k, l); // 0 2

	int x, y, z;
	x = 3;
	y = 4;
	z = (x + y++) * 5;
	printf("%d %d %d", x, y, z); // 3 5 35

	x = 1;
	y = 1;
	z = x * y++;
	// z = (x * y)++; // error
	// z = 3++; // error

	// 안 좋은 예
	int n = 1;
	printf("%d %d", n, n * n++);
	x = n / 2 + 5 * (1 + n++);
	y = n++ + n++;

	return 0;
}