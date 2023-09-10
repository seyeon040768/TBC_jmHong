#include <stdio.h>

int main(void)
{
	int number;
	scanf("%d", &number);

	// 최소 127층의 else if 지원
	if (number == 1)
	{
		printf("One");
	}
	else if (number == 2)
	{
		printf("Two");
	}
	else if (number == 3)
	{
		printf("Three");
	}

	/*if (number == 1)
	{
		printf("One");
	}
	else
	{
		if (number == 2)
		{
			printf("Two");
		}
		else
		{
			if (number == 3)
			{
				printf("Three");
			}
		}
	}*/

	if (number > 5)
	{
		if (number < 10)
		{
			printf("Larget than 5 smaller than 10\n");
		}
	}
	else
	{
		printf("Less than or equal to 5\n");
	}

	if (number > 5)
		if (number < 10)
			printf("Larget than 5 smaller than 10\n");
	else
		printf("Less than or equal to 5\n"); // number가 3일 때, 실행 안됨(두 번째 if문에 대응됨)

	return 0;
}