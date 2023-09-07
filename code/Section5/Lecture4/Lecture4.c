#include <stdio.h>

int main(void)
{
	float seed_money, target_money, annual_interest;

	printf("Input seed money: ");
	scanf("%f", &seed_money);

	printf("Input target money: ");
	scanf("%f", &target_money);

	printf("Input annual interest (%%): ");
	scanf("%f", &annual_interest);

	float fund = seed_money;
	int year_count = 0;

	while (fund < target_money)
	{
		fund = fund + fund * annual_interest / 100.0;
		printf("%f\n", fund);

		year_count = year_count + 1;
	}

	printf("It takes %d years\n", year_count);

	return 0;
}