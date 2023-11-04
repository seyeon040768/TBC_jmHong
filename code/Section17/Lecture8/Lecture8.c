#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "SimpleList.h"

void PrintAnItemFunc(Item item, int i)
{
	printf("%d: \"%s\" joined in %d\n", i, item.name, item.registeredYear);
}

void NameStartsWith(Item item)
{
	char startsWith[] = "Black";
	int i = 0;

	while (startsWith[i] != '\0')
	{
		if (item.name[i] != startsWith[i])
		{
			return;
		}
		++i;
	}

	printf("\"%s\" joined in %d\n", item.name, item.registeredYear);
}

bool RegisteredIn(Item item)
{
	int registeredYear = 1965;
	
	if (item.registeredYear == registeredYear)
	{
		printf("\"%s\" joined in %d\n", item.name, item.registeredYear);
	}
}


int main(void)
{
	List heroes;
	InitializeList(&heroes);

	FILE* fp;
	unsigned int heroCount;

	fp = fopen("heroes.txt", "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}

	fscanf(fp, "%u%*c", &heroCount);

	printf("%u heroes joined.\n", heroCount);

	for (int i = 0; i < (int)heroCount; ++i)
	{
		Item temp;
		fscanf(fp, "%[^\n]s%*c", temp.name);
		fscanf(fp, "%d%*c", &temp.registeredYear);

		AddItem(temp, &heroes, i);
	}

	printf("\n");

	printf("Print all members:\n");
	PrintAllItems(&heroes, PrintAnItemFunc);

	printf("\n");

	printf("Print all members whose names start with \"Black\":\n");
	Traverse(&heroes, NameStartsWith);

	printf("\n");

	printf("Print all members who joined in 1965:\n");
	Traverse(&heroes, RegisteredIn);

	return 0;
}