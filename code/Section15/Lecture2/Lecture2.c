﻿#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

unsigned char ToDecimal(const char bi[]);

int main(void)
{
	printf("Binary (string) to Decimal conversion\n");

	printf("%d\n", ToDecimal("00000110"));
	printf("%d\n", ToDecimal("00010110"));

	printf("%d\n", ToDecimal("10010100"));

	return 0;
}

unsigned char ToDecimal(const char bi[])
{
	unsigned char power = 1;
	unsigned char num = 0;

	const size_t bits = strlen(bi);

	for (size_t i = bits; i > 0; --i)
	{
		unsigned char temp = bi[i - 1] - '0';
		if (temp != 0 && temp != 1)
		{
			exit(EXIT_FAILURE);
		}

		//num += temp * power;
		//power *= 2;

		num += temp * (unsigned char)pow(2, bits - i);
	}

	return num;
}