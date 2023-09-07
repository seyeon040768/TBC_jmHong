#include <stdio.h>

#define NUM_DAYS 365

int main(void)
{
	char my_chars[] = "Hello, World!";

	int daily_temperature[NUM_DAYS];
	double stock_prices_history[NUM_DAYS];

	printf("%zd\n", sizeof(stock_prices_history));
	printf("%zd\n", sizeof(double) * NUM_DAYS);
	printf("%zd\n", sizeof(stock_prices_history[0]));

	int my_numbers[5];

	my_numbers[0] = 1;
	my_numbers[1] = 3;
	my_numbers[2] = 4;
	my_numbers[3] = 2;
	my_numbers[4] = 1024;

	scanf("%d", &my_numbers[0]);
	//scanf("%d", my_numbers); // 배열 이름은 주소와 비슷, 위 scanf와 같은 결과

	printf("%d\n", my_numbers[0]);
	printf("%d\n", my_numbers[1]);
	printf("%d\n", my_numbers[2]);
	printf("%d\n", my_numbers[3]);
	printf("%d\n", my_numbers[4]);

	//my_numbers[5] = 123; // runtime error

	//my_numbers = 7; // compile error

	printf("%d\n", my_numbers[5]); // out of bounds

	return 0;
}