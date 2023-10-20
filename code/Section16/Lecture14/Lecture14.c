#include <stdio.h>
#include <stdlib.h>

void Goodbye(void)
{
	printf("Goodbye\n");
}


void Thankyou(void)
{
	printf("Thankyou\n");
}

int main(void)
{
	printf("Purchased?\n");
	if (getchar() == 'y')
	{
		atexit(Thankyou);
	}

	while (getchar() != '\n') {};

	printf("Goodbye message?\n");
	if (getchar() == 'y')
	{
		atexit(Goodbye);
	}

	//exit(0);

	//qsort();

	return 0;
}