#include <stdio.h>

int main(void)
{
	char fruit_name[40]; // fruit_name 자체가 주소

	printf("What is your favorite fruit?\n");

	scanf("%s", fruit_name);

	printf("You like %s!\n", fruit_name);

	return 0;
}