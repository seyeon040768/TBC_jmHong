#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("Dummy Output\n");

	{
		int n = 100000000;
		int* ptr = (int*)malloc(n * sizeof(int));

		if (!ptr)
		{
			printf("malloc() failed\n");
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < n; ++i)
		{
			ptr[i] = i + 1;
		}

		free(ptr);
	}

	printf("Dummy Output\n");

	return 0;
}