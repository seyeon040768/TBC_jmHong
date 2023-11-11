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
	for (int i = 0; i < size; ++i)
	{
		printf("%d: %d\n", items[i].key, items[i].value);
	}
	printf("\n");
}

int CompareItems(const void* first, const void* second)
{
	return ((Item*)first)->key - ((Item*)second)->key;
}

const Item* SequentialSearch(const Item items[], const int size, const int key)
{
	for (int i = 0; i < size; ++i)
	{
		if (items[i].key == key)
		{
			return &items[i];
		}
	}

	return NULL;
}

const Item* BinarySearch(const Item items[], const int size, const int key)
{
	int first = 0;
	int last = size - 1;
	int pivot = (first + last) / 2;

	while (last - first >= 0)
	{
		pivot = (first + last) / 2;

		if (items[pivot].key == key)
		{
			return &items[pivot];
		}
		else if (items[pivot].key > key)
		{
			last = pivot - 1;
		}
		else
		{
			first = pivot + 1;
		}
	}

	return NULL;
}

int main(void)
{
	/* Assume that there is no duplicated items */

	Item items[] = {
		{1, 11},
		{6, 16},
		{4, 14},
		{8, 18},
		{2, 12},
		{9, 19},
		{0, 10},
		{5, 15},
		{3, 13},
		{7, 17},
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

		//const Item* found = SequentialSearch(items, n, key);
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