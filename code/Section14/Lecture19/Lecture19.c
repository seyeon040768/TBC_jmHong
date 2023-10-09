#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN 30

enum Spectrum { red, orange, yellow, green, blue };
const char* colors[] = { "red", "orange", "yellow", "green", "blue" };

int main(void)
{
	char choice[LEN] = { 0, };
	enum Spectrum color;
	bool isColorFounded = false;

	while (true)
	{
		bool isColorFounded = false;

		printf("Input a color name (empty line to quit):\n");

		if (scanf("%[^\n]%*c", choice) != 1)
		{
			break;
		}

		/*fgets(choice, LEN, stdin);

		char* find = strchr(choice, '\n');
		if (find)
		{
			*find = '\0';
		}

		if (choice[0] == '\0')
		{
			break;
		}*/

		for (color = red; color <= blue; ++color)
		{
			if (strcmp(choice, colors[color]) == 0)
			{
				isColorFounded = true;
				break;
			}
		}

		if (isColorFounded)
		{
			switch (color)
			{
			case red:
				printf("Red roses\n");
				break;
			case orange:
				printf("Oranges are delicious\n");
				break;
			case yellow:
				printf("Yellow sunflowers\n");
				break;
			case green:
				printf("Green apples\n");
				break;
			case blue:
				printf("Blue ocean\n");
				break;
			}
		}
		else
		{
			printf("Please try different color %s.\n", choice);
		}
	}

	printf("Good bye!\n");

	return 0;
}