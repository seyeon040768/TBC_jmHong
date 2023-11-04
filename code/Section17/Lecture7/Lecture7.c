#include <stdio.h>
#include <string.h>

#include "SimpleList.h"

#define PROMPT ">>"

enum Menu
{
	EPrintAllItems = 1,
	EPrintAnItem,
	EditAnItem,
	AddAnItem,
	InsertAnItem,
	DeleteAnItem,
	DeleteAllItems,
	SaveFile,
	SearchByName,
	Quit
};

void PrintAnItemFunc(Item item, int i)
{
	printf("%d: \"%s\", %.1f\n", i, item.title, item.rating);
}

void WriteAnItemFunc(FILE* file, Item item)
{
	fprintf(file, "%s\n%.1f\n", item.title, item.rating);
}

bool CompareName(Item a, Item b)
{
	return strcmp(a.title, b.title) == 0;
}

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

int main(void)
{
	List movies;
	InitializeList(&movies);

	char filename[TEXT_SIZE] = { '\0', };
	FILE* fp = NULL, * fSave = NULL;
	unsigned int movieCount;
	int selectedMenu, selectedIndex;
	char saveFilename[TEXT_SIZE] = { '\0', };

	printf("Please input filename to read and press Enter.\n");
	printf("%s ", PROMPT);
	scanf("%s", filename);

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("ERROR: Cannot open file.\n");
		exit(EXIT_FAILURE);
	}

	if (fscanf(fp, "%u%*c", &movieCount) != 1)
	{
		printf("ERROR: Wrong Format.\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < (int)movieCount; ++i)
	{
		Item temp;
		if (fscanf(fp, "%[^\n]s%*c", temp.title) != 1 || fscanf(fp, "%f%*c", &temp.rating) != 1)
		{
			printf("ERROR: Wrong Format.\n");
			exit(EXIT_FAILURE);
		}

		if (!AddItem(temp, &movies, i))
		{
			printf("ERROR: Can't add an item.\n");
			exit(EXIT_FAILURE);
		}
	}

	printf("%u items have been read from the file.\n", movieCount);

	fclose(fp);

	while (1)
	{
		printf("\nPlease select an option and press enter.\n");
		printf("1. Print all items\t2. Print an item\n");
		printf("3. Edit an item\t\t4. Add an item\n");
		printf("5. Insert an item\t6. Delete an item\n");
		printf("7. Delete all items\t8. Save file\n");
		printf("9. Search by name\t10. Quit\n");
		printf("%s ", PROMPT);
		selectedMenu = InputInt();

		switch (selectedMenu)
		{
		case EPrintAllItems:
			PrintAllItems(&movies, PrintAnItemFunc);
			break;
		case EPrintAnItem:
			printf("Input the index of item to print.\n");
			printf("%s ", PROMPT);
			selectedIndex = InputInt();

			if (selectedIndex < 0 || selectedIndex >= (int)movies.size)
			{
				printf("Invalid index.\n");
				break;
			}

			PrintAnItem(&movies, selectedIndex, PrintAnItemFunc);

			break;
		case EditAnItem:
			printf("Input the index of item to edit.\n");
			printf("%s ", PROMPT);
			selectedIndex = InputInt();

			if (selectedIndex < 0 || selectedIndex >= (int)movies.size)
			{
				printf("Invalid index.\n");
				break;
			}

			PrintAnItem(&movies, selectedIndex, PrintAnItemFunc);

			{
				Node* temp = FindNodeByIndex(&movies, selectedIndex);

				if (temp == NULL)
				{
					exit(EXIT_FAILURE);
				}

				printf("Input new title and press enter.\n");
				printf("%s ", PROMPT);
				scanf("%[^\n]%*c", temp->item.title);

				printf("Input new rating and press enter.\n");
				printf("%s ", PROMPT);
				scanf("%f%*c", &temp->item.rating);
			}

			PrintAnItem(&movies, selectedIndex, PrintAnItemFunc);

			break;
		case AddAnItem:
		{
			Item temp;

			printf("Input title and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", temp.title);

			printf("Input rating and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%f%*c", &temp.rating);

			if (!AddItem(temp, &movies, movies.size))
			{
				printf("ERROR: Can't add an item.\n");
				break;
			}

			PrintAnItem(&movies, movies.size - 1, PrintAnItemFunc);

			break;
		}
		case InsertAnItem:
			printf("Input the index of item to insert.\n");
			printf("%s ", PROMPT);
			scanf("%d%*c", &selectedIndex);

			if (selectedIndex < 0 || selectedIndex >= (int)movies.size)
			{
				printf("Invalid index.\n");
				break;
			}

			{
				Item temp;

				printf("Input title and press enter.\n");
				printf("%s ", PROMPT);
				scanf("%[^\n]%*c", temp.title);

				printf("Input rating and press enter.\n");
				printf("%s ", PROMPT);
				scanf("%f%*c", &temp.rating);

				if (!AddItem(temp, &movies, selectedIndex))
				{
					printf("ERROR: Can't add an item.\n");
					break;
				}
			}

			PrintAnItem(&movies, selectedIndex, PrintAnItemFunc);

			break;
		case DeleteAnItem:
			printf("Input the index of item to delete.\n");
			printf("%s ", PROMPT);
			scanf("%d%*c", &selectedIndex);

			if (selectedIndex < 0 || selectedIndex >= (int)movies.size)
			{
				printf("Invalid index.\n");
				break;
			}

			if (!RemoveItem(&movies, selectedIndex))
			{
				printf("Error: Can't delete an item.\n");
			}

			break;
		case DeleteAllItems:
			while (movies.size > 0)
			{
				RemoveItem(&movies, 0);
			}

			break;
		case SaveFile:
			printf("Please input filename to write and press Enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", saveFilename);

			if ((fSave = fopen(saveFilename, "w")) == NULL)
			{
				printf("ERROR: Cannot open file.\n");
				exit(EXIT_FAILURE);
			}

			fprintf(fSave, "%u\n", movieCount);

			WriteAllItems(&movies, fSave, WriteAnItemFunc);

			fclose(fSave);

			printf("%u items have been saved to the file.\n", movieCount);
			break;
		case SearchByName:
		{
			Item temp;
			int index;

			printf("Input title to search and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", temp.title);

			if (!Find(&movies, temp, &index, &temp, CompareName))
			{
				printf("No movie found: %s\n", temp.title);

				break;
			}

			PrintAnItemFunc(temp, index);

			break;
		}
		case Quit:
			while (movies.size > 0)
			{
				RemoveItem(&movies, 0);
			}

			exit(0);
			break;
		}
	}

	return 0;
}