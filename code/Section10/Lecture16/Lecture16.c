#include <stdio.h>

#define ROWS 3
#define COLS 4

int sum2d_1(int ar[ROWS][COLS]);
int sum2d_2(int ar[][COLS], int row);
// int sum2d_2(inti (*ar)[COLS], int row);
int sum2d_3(int* ar, int row, int col);

int main(void)
{
	int data[ROWS][COLS] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 0, 1, 2} 
	};

	printf("%d\n", data[2][3]); // 2

	int* ptr = &data[0][0];
	printf("%d\n", *(ptr + 3 + COLS * 2)); // 2

	printf("Sum of all elements = %d\n", sum2d_1(data)); // 48
	printf("Sum of all elements = %d\n", sum2d_2(data, ROWS)); // 48
	printf("Sum of all elements = %d\n", sum2d_3(&data[0][0], ROWS, COLS)); // 48

	return 0;
}

int sum2d_1(int ar[ROWS][COLS])
{
	int r, c, tot = 0;
	for (r = 0; r < ROWS; ++r)
	{
		for (c = 0; c < COLS; ++c)
		{
			tot += ar[r][c];
		}
	}

	return tot;
}

int sum2d_2(int ar[][COLS], int row)
{
	int r, c, tot = 0;
	for (r = 0; r < row; ++r)
	{
		for (c = 0; c < COLS; ++c)
		{
			tot += ar[r][c];
		}
	}

	return tot;
}

int sum2d_3(int* ar, int row, int col)
{
	int r, c, tot = 0;
	for (r = 0; r < row; ++r)
	{
		for (c = 0; c < col; ++c)
		{
			tot += *(ar + c + col * r);
		}
	}

	return tot;
}