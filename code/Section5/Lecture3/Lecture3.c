#include <stdio.h>

int main(void)
{
	printf("%d\n", 1 + 2);

	int income, salary, bonus;

	income = salary = bonus = 100; // triple assignment

	salary = 100;
	bonus = 30;

	income = salary + bonus; // L-value vs R-value

	int takehome, tax;
	tax = 20;
	takehome = income - tax;

	int a, b;
	a = -7;
	b = -a;
	b = +a;

	return 0;
}