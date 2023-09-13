#include <stdio.h>

void display(char ch, int lines, int width);

int main(void)
{
	char c;
	int rows, cols;

	/*while (1)
	{
		scanf("%c %d %d", &c, &rows, &cols);

		while (getchar() != '\n')
		{
			continue;
		}

		display(c, rows, cols);

		if (c == '\n')
		{
			break;
		}
	}*/

	while ((c = getchar()) != '\n')
	{
		scanf("%d %d", &rows, &cols);

		while (getchar() != '\n')
		{
			continue;
		}

		display(c, rows, cols);
	}

	return 0;
}

void display(char ch, int height, int width)
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			printf("%c", ch);
		}
		printf("\n");
	}

	return 0;
}