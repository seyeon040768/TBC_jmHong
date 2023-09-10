#include <stdio.h>

int main(void)
{
	unsigned int num;
	int isPrime = 1;

	scanf("%u", &num);

	for (unsigned int div = 2; div * div <= num; ++div)
	{
		if (num % div == 0)
		{
			isPrime = 0;
			if (num == div * div)
			{
				printf("%u is divisible by %u.\n", num, div);
			}
			else
			{
				printf("%u is divisible by %u and %u.\n", num, div, num / div);
			}
		}
	}

	if (isPrime)
	{
		printf("%u is a prime number.\n", num);
	}
	else
	{
		printf("%u is not a prime number.\n", num);
	}

	return 0;
}