// can't run on visual studio
// please use another c compiler
#include <stdio.h>

#define ROWS 3
#define COLS 4

int sum2d(int row, int col, int ar[row][col]);

int main(void)
{
	int n;

	printf("Input array length: ");
	scanf("%d", &n);

	float myArr[n];

	for (int i = 0; i < n; ++i)
	{
		myArr[i] = (float)i;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%f\n", myArr[i]);
	}


	int data[ROWS][COLS] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 0, 1, 2}
	};

	printf("%d\n", sum2d(ROWS, COLS, data));

	return 0;
}

int sum2d(int row, int col, int ar[row][col])
{
	int r, c, tot = 0;
	for (r = 0; r < row; ++r)
	{
		for (c = 0; c < col; ++c)
		{
			tot += ar[r][c];
		}
	}

	return tot;
}