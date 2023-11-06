#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stack.h"

#define WIDTH 7
#define HEIGHT 7

static int map[HEIGHT][WIDTH] = {
	0, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 1, 1, 0,
	0, 1, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 1, 0,
	0, 1, 0, 0, 0, 1, 0,
	0, 1, 1, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 0,
};

void PrintMap()
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

Element GetElement(const int i, const int j)
{
	Element newElement;
	newElement.i = i;
	newElement.j = j;
	return newElement;
}

void PrintStack(const Stack* stack)
{
	printf("Stack: ");
	if (IsEmpty(stack) == true)
	{
		printf("Empty\n");
		return;
	}

	for (int i = 0; i <= stack->top; ++i)
	{
		printf("(%d, %d) ", stack->items[i].i, stack->items[i].j);
	}
	printf("\n");
}

int main(void)
{
	PrintMap();

	Stack toVisit;
	Initialize(&toVisit);

	Push(&toVisit, GetElement(0, 0));
	//Push(&toVisit, GetElement(3, 3));

	while (!IsEmpty(&toVisit))
	{
		Element cell = Pop(&toVisit);

		if (map[cell.i][cell.j] != 0)
		{
			continue;
		}

		map[cell.i][cell.j] = 2;

		if (cell.i - 1 >= 0 && map[cell.i - 1][cell.j] == 0)
		{ 
			Push(&toVisit, (Element) { .i= cell.i - 1, .j = cell.j });
		}

		if (cell.i + 1 < HEIGHT && map[cell.i + 1][cell.j] == 0)
		{
			Push(&toVisit, (Element) { .i = cell.i + 1, .j = cell.j });
		}

		if (cell.j - 1 >= 0 && map[cell.i][cell.j - 1] == 0)
		{
			Push(&toVisit, (Element) { .i = cell.i, .j = cell.j - 1 });
		}

		if (cell.j + 1 < WIDTH && map[cell.i][cell.j + 1] == 0)
		{
			Push(&toVisit, (Element) { .i = cell.i, .j = cell.j + 1 });
		}

		// Debugging
		system("cls");
		PrintStack(&toVisit);
		printf("Cell: (%d, %d)\n", cell.i, cell.j);
		PrintMap();
		int dummy = _getch();
	}

	printf("Result:\n");
	PrintMap();

	return 0;
}