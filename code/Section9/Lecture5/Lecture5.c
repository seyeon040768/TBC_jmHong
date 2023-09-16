#include <stdio.h>

int int_max(int i, int j)
{
	int m;
	m = (i > j) ? i : j;
	return m;
}

int main(void)
{
	int a; // 1

	a = int_max(1, 2); // 2
	// 3
	{
		int b; // 4
		b = int_max(4, 5); // 5
		// 6
		{
			int b = 123; // 7
		}
		// 8
		{
			int c = 456; // 9
		}
		// 10
	}
	// 11
	return 0;
}