#include <stdio.h>

int main(void)
{
	char str[255];
	int i, i2;
	double d;

	scanf("%s %d %lf", str, &i, &d); // hello 123 3.14
	printf("%s %d %f\n", str, i, d); // hello 123 3.140000

	scanf("%s %d %d", str, &i, &i2); // hello 123 3.14
	printf("%s %d %d\n", str, i, i2); // hello 123 3

	char c;
	while ((c = getchar()) != '\n')
	{
		putchar(c); // .14
	}
	printf("\n");

	return 0;
}