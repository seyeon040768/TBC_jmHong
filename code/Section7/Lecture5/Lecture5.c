#include <stdio.h>

int main(void)
{
	int number;
	scanf("%d", &number);

	// �ּ� 127���� else if ����
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
		printf("Less than or equal to 5\n"); // number�� 3�� ��, ���� �ȵ�(�� ��° if���� ������)

	return 0;
}