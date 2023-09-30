#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*int* ptr = NULL;

	ptr = (int*)malloc(sizeof(int) * 1);
	if (!ptr)
	{
		exit(EXIT_FAILURE);
	}

	*ptr = 1024 * 3;
	printf("%d\n", *ptr);

	free(ptr);
	ptr = NULL;*/


	/*int n = 3;
	int* ptr = (int*)malloc(sizeof(int) * n);
	if (!ptr)
	{
		exit(EXIT_FAILURE);
	}
	
	ptr[0] = 123;
	*(ptr + 1) = 456;
	*(ptr + 2) = 789;

	free(ptr);
	ptr = NULL;*/


	/*int row = 3, col = 2;
	int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);
	if (!ptr2d)
	{
		exit(EXIT_FAILURE);
	}

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			ptr2d[r][c] = c + col * r;
		}
	}

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			printf("%d ", ptr2d[r][c]);
		}
		printf("\n");
	}
	
	free(ptr2d);
	ptr2d = NULL;*/


	/*int row = 3, col = 2;
	int* ptr = (int*)malloc(row * col * sizeof(int));
	if (!ptr)
	{
		exit(EXIT_FAILURE);
	}

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			ptr[c + col * r] = c + col * r;
		}
	}

	for (int r = 0; r < row; ++r)
	{
		for (int c = 0; c < col; ++c)
		{
			printf("%d ", *(ptr + c + col * r));
		}
		printf("\n");
	}

	free(ptr);
	ptr = NULL;*/


	int row = 3, col = 2, depth = 2;
	int* ptr = (int*)malloc(depth* row * col * sizeof(int));
	if (!ptr)
	{
		exit(EXIT_FAILURE);
	}

	for (int d = 0; d < depth; ++d)
	{
		for (int r = 0; r < row; ++r)
		{
			for (int c = 0; c < col; ++c)
			{
				ptr[c + col * r + col * row * d] = c + col * r + col * row * d;
			}
		}
	}

	for (int d = 0; d < depth; ++d)
	{
		for (int r = 0; r < row; ++r)
		{
			for (int c = 0; c < col; ++c)
			{
				printf("%d ", *(ptr + c + col * r + col * row * d));
			}
			printf("\n");
		}
		printf("\n");
	}

	free(ptr);
	ptr = NULL;

	return 0;
}