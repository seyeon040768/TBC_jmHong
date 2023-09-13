#include <stdio.h>

char GetChoice(void);

int main(void)
{
	char menu;
	int num;

	while ((menu = GetChoice()) != 'q')
	{

		while (getchar() != '\n')
		{
			continue;
		}

		switch (menu)
		{
		case 'a':
			printf("Hello!\n");
			break;
		case 'b':
			printf("\a");
			break;
		case 'c':
			printf("Enter an integers:\n");
			scanf("%d", &num);

			for (int i = 1; i <= num; ++i)
			{
				printf("%d\n", i);
			}

			while (getchar() != '\n')
			{
				continue;
			}
			break;
		default:
			printf("Please enter one of a, b, c, and q.\n");
			break;
		}
	}

	return 0;
}

char GetChoice(void)
{
	printf("Enter the letter of your choice:\n");
	printf("a. hello\tb. beep\n");
	printf("c. count\tq.quit\n");

	return getchar();
}