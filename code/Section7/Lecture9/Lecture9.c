#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int temp;
	temp = true ? 1024 : 7;
	printf("%d\n", temp); // 1024

	temp = false ? 1024 : 7;
	printf("%d\n", temp); // 7


	int a = 1, b = 2;
	int max = (a > b) ? a : b; // 2


	int number;
	scanf("%d", &number);

	printf(number % 2 == 0 ? "Even\n" : "Odd\n");

	return 0;
}