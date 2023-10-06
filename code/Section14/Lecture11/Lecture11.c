#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	struct Flex
	{
		size_t count;
		double average;
		double values[];
	};

	const size_t n = 3;

	struct Flex* pf = (struct Flex*)malloc(sizeof(struct Flex) + n * sizeof(double));
	if (pf == NULL)
	{
		exit(EXIT_FAILURE);
	}

	printf("Flexible array member\n");
	printf("Sizeof struct Flex %zd\n", sizeof(struct Flex)); // 16
	printf("Sizeof *pf %zd\n", sizeof(*pf)); // 16
	printf("Sizeof malloc %zd\n", sizeof(struct Flex) + n * sizeof(double)); // 40

	printf("%llu\n", (unsigned long long)pf); // 2243065340608
	printf("%llu\n", (unsigned long long)& pf->count); // 2243065340608
	printf("%zd\n", sizeof(pf->count)); // 8
	printf("%llu\n", (unsigned long long)& pf->average); // 2243065340616
	printf("Address of pf->values %llu\n", (unsigned long long)& pf->values); // 2243065340624
	printf("Value of pf->values %lld\n", (unsigned long long)pf->values); // 2243065340624
	printf("Sizeof pf->values = %zd\n", sizeof(pf->values)); // 0

	pf->count = n;
	pf->values[0] = 1.1;
	pf->values[1] = 2.1;
	pf->values[2] = 3.1;

	pf->average = 0.0;
	for (unsigned i = 0; i < pf->count; ++i)
	{
		pf->average += pf->values[i];
	}
	pf->average /= (double)pf->count;

	printf("Average = %f\n", pf->average); // 2.100000


	struct Flex* pf2 = (struct Flex*)malloc(sizeof(struct Flex) + n * sizeof(double));
	if (pf2 == NULL)
	{
		exit(EXIT_FAILURE);
	}

	*pf2 = *pf; // Don't copy flexible members. Use memcpy() instead


	/*struct NonFlex
	{
		size_t count;
		double average;
		double* values;
	};

	struct NonFlex* nf;
	nf->values = (double*)malloc(n * sizeof(double));*/

	free(pf);
	free(pf2);
	// free(nf);

	return 0;
}