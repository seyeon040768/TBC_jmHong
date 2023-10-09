#include <stdio.h>

int main(void)
{
	enum Spectrum { red, orange, yellow, green, blue, violet };
	//              0    1       2       3      4     5

	enum Spectrum color;
	color = blue;
	if (color == yellow)
	{
		printf("yellow\n");
	}

	for (color = red; color <= violet; ++color)
	{
		printf("%d\n", color); // 0 1 2 3 4 5
	}

	printf("red = %d, orange = %d\n", red, orange); // red = 0, orange = 1

	enum Kids { jackjack, dash, snoopy, nano, pitz };

	enum Kids myKid = nano;
	printf("nano %d %d\n", myKid, nano); // nano 3 3

	enum Levels { low = 100, medium = 500, high = 2000 };

	int score = 800;
	if (score > high)
	{
		printf("High score!\n");
	}
	else if (score > medium)
	{
		printf("Good job\n");
	}
	else if (score > low)
	{
		printf("Not bad\n");
	}
	else
	{
		printf("Do your best\n");
	}

	enum Pet { cat, dog = 10, lion, tiger };

	printf("cat %d\n", cat); // cat 0
	printf("lion %d\n", lion); // lion 11

	return 0;
}