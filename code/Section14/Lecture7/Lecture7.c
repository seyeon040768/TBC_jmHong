#include <stdio.h>
#include <string.h>

#define FUNDLEN 50

struct Fortune
{
	char bankName[FUNDLEN];
	double bankSaving;
	char fundName[FUNDLEN];
	double fundInvest;
};

double Sum(const struct Fortune* myFortune);

int main(void)
{
	struct Fortune myFortune = {
		"Wells-Fargo",
		4032.27,
		"JPMorgan Chase",
		8543.94
	};

	printf("Total : $%.2f.\n",
		Sum(&myFortune));

	return 0;
}

double Sum(const struct Fortune *myFortune)
{
	return myFortune->bankSaving + myFortune->fundInvest;
}