#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	{
		FILE* fp = fopen("binary_file", "wb");

		double d = 1.0 / 3.0;
		int n = 123;
		int* parr = (int*)malloc(sizeof(int) * n);
		if (!parr)
		{
			exit(EXIT_FAILURE);
		}
		for (int n = 0; n < 123; ++n)
		{
			*(parr + n) = n * 2;
		}

		fwrite(&d, sizeof(d), 1, fp);
		fwrite(&n, sizeof(n), 1, fp);
		fwrite(parr, sizeof(int), n, fp);

		fclose(fp);
		free(parr);

		// Total size is 8 * 1 + 4 * 1 + 4 * 123 = 504 bytes
	}

	{
		FILE* fp = fopen("binary_file", "rb");
		double d;
		int n = 0;
		fread(&d, sizeof(d), 1, fp);
		fread(&n, sizeof(n), 1, fp);

		int* parr = (int*)malloc(sizeof(int) * n);
		if (!parr)
		{
			exit(EXIT_FAILURE);
		}

		fread(parr, sizeof(int), n, fp);

		printf("feof = %d\n", feof(fp));

		printf("%f\n", d);
		printf("%d\n", n);
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", *(parr + i));
		}
		printf("\n");

		printf("feof = %d\n", feof(fp));

		fread(&n, sizeof(n), 1, fp);

		printf("feof = %d\n", feof(fp));
		printf("ferror = %d\n", ferror(fp));

		fwrite(&n, sizeof(n), 1, fp);

		printf("ferror = %d\n", ferror(fp));

		fclose(fp);
		free(parr);
	}
	
	return 0;
}