#include <stdio.h>
#include <math.h>

int main(void)
{
	int n = 0;
	while (n++ < 5)
		printf("%d ", n);

	printf("\n");

	char c = 'A';
	while (c != 'Z')
		printf("%c ", c++);

	printf("\n");

	const double PI = 3.1415926535897932384626433832795;
	double guess = 0.0;

	printf("Input PI: ");
	scanf("%lf", &guess);
	//while (guess != PI)
	while (fabs(guess - PI) > 0.01) // Àý´ë°ª
	{
		printf("Fool! Try again.\n");
		scanf("%lf", &guess);
	}

	printf("Good!\n");

	return 0;
}