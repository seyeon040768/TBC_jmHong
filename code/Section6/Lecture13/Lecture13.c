#include <stdio.h>

int main(void)
{
	const int secret_code = 337;
	int guess = 0;

	/*printf("Enter secret code: ");
	scanf("%d", &guess);

	while (guess != secret_code)
	{
		printf("Enter secret code: ");
		scanf("%d", &guess);
	}*/

	do
	{
		printf("Enter secret code: ");
		scanf("%d", &guess);
	} while (guess != secret_code);

	printf("Good!");

	return 0;
}