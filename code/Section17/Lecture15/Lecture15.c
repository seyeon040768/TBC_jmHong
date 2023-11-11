#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PROMPT ">>"

int InputInt()
{
	int num;

	while (scanf("%d", &num) != 1)
	{
		while (getchar() != '\n');
	}

	while (getchar() != '\n');

	return num;
}

typedef struct
{
	int key;
	int value;
} Item;

void PrintItems(Item items[], int size)
{

}

int CompareItmes(const void* first, const void* second)
{

}

const Item* SequentialSearch(const Item items[], const int size, const int key)
{

}

const Item* BinarySearch(const Item items[], const int size, const int key)
{

}

int main(void)
{
	/* Assume that there is no duplicated items */

	Item items[] = {
		{0, 10},
		{1, 11},
		{2, 12},
		{3, 13},
		{4, 14},
		{5, 15},
		{6, 16},
		{7, 17},
		{8, 18},
		{9, 19}
	};

	int n = sizeof(items) / sizeof(items[0]);

	PrintItems(items, n);

	qsort(items, n, sizeof(Item), CompareItmes);

	PrintItems(items, n);

	while (1)
	{
		int key = 0;
		printf("Input key\n");
		printf("%s ", PROMPT);
		key = InputInt();

		if (key == -1)
		{
			break;
		}

		const Item* found = BinarySearch(items, n, key);

		if (found)
		{
			printf("%d: %d\n\n", found->key, found->value);
		}
		else
		{
			printf("Not in the list.\n\n");
		}
	}

	return 0;
}