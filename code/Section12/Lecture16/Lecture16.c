#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 10;
	int* ptr = NULL;

	ptr = (int*)calloc(n, sizeof(int)); // contiguous allocation
	if (!ptr)
	{
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", ptr[i]);
	}
	printf("\n");


	for (int i = 0; i < n; ++i)
	{
		ptr[i] = i + 1;
	}

	n = 20;

	int* ptr2 = NULL;
	ptr2 = (int*)realloc(ptr, n * sizeof(int)); // re allocation

	if (!ptr2)
	{
		exit(EXIT_FAILURE);
	}

	printf("%p %p\n", ptr, ptr2);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", ptr2[i]);
	}
	printf("\n");

	free(ptr2);

	return 0;
}