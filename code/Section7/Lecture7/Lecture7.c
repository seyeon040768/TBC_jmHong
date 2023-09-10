#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <iso646.h>

#define PERIOD '.'

int main()
{
	bool test1 = 3 > 2 || 5 > 6;
	bool test2 = 3 > 2 && 5 > 6;
	bool test3 = !(5 > 6);

	printf("%d %d %d\n", test1, test2, test3);

	// iso646.h
	test1 = 3 > 2 or 5 > 6;
	test2 = 3 > 2 and 5 > 6;
	test3 = not(5 > 6);

	printf("%d %d %d\n", test1, test2, test3);


	char ch;
	int count = 0;

	while ((ch = getchar()) != PERIOD)
	{
		if (ch != '\n' && ch != ' ')
		{
			++count;
		}
	}

	printf("%d\n", count);


	int a = 1, b = 2, c = 3, d = 4;

	a > b && b > c || b > d;
	((a > b) && (b > c)) || (b > d);


	// Short-circuit Evaluation
	// 논리 표현은 left to right
	int temp = (1 + 2) * (3 + 4);

	printf("Before: %d\n", temp); // 21

	if (temp == 0 && (++temp == 1024)) // 왼쪽이 false이므로 오른쪽 실행 X
	{

	};

	printf("After: %d\n", temp); // 21


	// &&, ||는 sequence point
	int x = 1, y = 2;
	if (x++ > 0 && x + y == 4)
	{
		printf("%d %d\n", x, y); // 2 2
	}


	for (int i = 0; i < 100; ++i)
	{
		if (i >= 10 && i <= 20)
		{
			printf("%d ", i); // 10 ~ 20
		}
	}

	printf("\n");

	for (int i = 0; i < 100; ++i)
	{
		if (10 <= i <= 20) // if((10 <= i) <= 20)
		{
			printf("%d ", i); // 0 ~ 99
		}
	}

	printf("\n");


	for (char c = 0; c < 127; ++c)
	{
		if (c >= 'a' && c <= 'z')
		{
			printf("%c ", c);
		}
	}

	printf("\n");

	for (char c = 0; c < 127; ++c)
	{
		if (islower(c))
		{
			printf("%c ", c);
		}
	}

	printf("\n");

	return 0;
}