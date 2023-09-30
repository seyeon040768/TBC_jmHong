#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float x;
	char str[] = "Dancing with a Star";

	int arr[100];


	double* ptr = NULL;
	ptr = (double*)malloc(30 * sizeof(double));

	if (ptr == NULL)
	{
		puts("Memory allocation failed.");

		exit(EXIT_FAILURE);
	}

	printf("Before free %p\n", ptr); // Before free 000001F7422BE920

	free(ptr);

	printf("After free %p\n", ptr); // After free 000001F7422BE920

	ptr = NULL;


	int n = 5;
	ptr = (double*)malloc(n * sizeof(double));

	if (ptr != NULL)
	{
		for (int i = 0; i < n; ++i)
		{
			printf("%f ", ptr[i]); // 쓰레기 값
		}
		printf("\n");

		for (int i = 0; i < n; ++i)
		{
			*(ptr + i) = (double)i;
		}

		for (int i = 0; i < n; ++i)
		{
			printf("%f ", ptr[i]); // 0.000000 1.000000 2.000000 3.000000 4.000000
		}
		printf("\n");
	}

	free(ptr);

	ptr = NULL;

	return 0;
}