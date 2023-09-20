#include <stdio.h>

#define MONTHS 12
#define YEARS 3

int main(void)
{
	// double year2016[MONTHS] = { 1.2, -6.0, -2.7, 15.3, 18.8, 23.3, 24.0, 28.4, 23.2, 21.1, 1.5, 4.1 };
	// double year2017[MONTHS] = { 2.7, -4.0, 5.0, 9.0, 20.1, 23.3, 25.3, 28.6, 23.3, 18.2, 14.4, -2.2 };
	// double year2018[MONTHS] = { -1.3, -4.0, -0.2, 15.6, 20.4, 23.8, 21.9, 33.6, 25.5, 15.4, 8.4, 5.5 };

	double temperature[YEARS][MONTHS] = {
		{ 1.2, -6.0, -2.7, 15.3, 18.8, 23.3, 24.0, 28.4, 23.2, 21.1, 1.5, 4.1 },
		{ 2.7, -4.0, 5.0, 9.0, 20.1, 23.3, 25.3, 28.6, 23.3, 18.2, 14.4, -2.2 },
		{ -1.3, -4.0, -0.2, 15.6, 20.4, 23.8, 21.9, 33.6, 25.5, 15.4, 8.4, 5.5 }
	};

	printf("[Temperature Data]\n");

	printf("Year index\t:");
	for (int i = 1; i <= MONTHS; ++i)
	{
		printf("\t%d", i);
	}
	printf("\n");

	for (int j = 0; j < YEARS; ++j)
	{
		printf("Year %d\t\t:", j + 1);
		for (int i = 0; i < MONTHS; ++i)
		{
			printf("\t%.1lf", temperature[j][i]);
		}
		printf("\n");
	}
	printf("\n");


	printf("[Yearly average temperatures of %d years]\n", YEARS);
	for (int j = 0; j < YEARS; ++j)
	{
		printf("Year %d: ", j + 1);

		double sum = 0;
		for (int i = 0; i < MONTHS; ++i)
		{
			sum += temperature[j][i];
		}
		printf("average temperature = %.1lf\n", sum / MONTHS);
	}
	printf("\n");


	printf("[Monthly average temperatures of %d years]\n", YEARS);

	printf("Year index\t:");
	for (int i = 1; i <= MONTHS; ++i)
	{
		printf("\t%d", i);
	}
	printf("\n");

	printf("Avg temps\t:");
	for (int i = 0; i < MONTHS; ++i)
	{
		double sum = 0;
		for (int j = 0; j < YEARS; ++j)
		{
			sum += temperature[j][i];
		}
		printf("\t%.1lf", sum / YEARS);
	}
	printf("\n");

	return 0;
}