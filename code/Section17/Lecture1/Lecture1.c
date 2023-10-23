#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT ">>"

enum Menu
{
	PrintAllItmes = 1,
	PrintAnItem,
	EditAnItem,
	AddAnItem,
	InsertAnItem,
	DeleteAnItem,
	DeleteAllItems,
	SaveFile,
	SearchByName,
	Quit
};

int main(void)
{
	char filename[100] = { '\0',};
	FILE* fp;
	int moviesCount, selectedMenu, selectedIndex;
	char** movieNames, ** namesTemp;
	float* movieStars, * starsTemp;
	int isQuit = 0;

	printf("Please input filename to read and press Enter.\n");
	printf("%s ", PROMPT);
	scanf("%s", filename);

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("ERROR: Cannot open file.\n");
		exit(EXIT_FAILURE);
	}

	fscanf(fp, "%d%*c", &moviesCount);
	printf("%d items have been read from the file.\n", moviesCount);

	if ((movieNames = (char**)malloc(moviesCount * sizeof(char*))) == NULL)
	{
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < moviesCount; ++i)
	{
		if ((movieNames[i] = (char*)malloc(100 * sizeof(char))) == NULL)
		{
			exit(EXIT_FAILURE);
		}
	}
	if ((movieStars = (float*)malloc(moviesCount * sizeof(float))) == NULL)
	{
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < moviesCount; ++i)
	{
		fscanf(fp, "%[^\n]s%*c", movieNames[i]);

		fscanf(fp, "%f%*c", movieStars + i);
	}

	while (!isQuit)
	{
		printf("\nPlease select an option and press enter.\n");
		printf("1. Print all items\t2. Print an item\n");
		printf("3. Edit an item\t\t4. Add an item\n");
		printf("5. Insert an item\t6. Delete an item\n");
		printf("7. Delete all items\t8. Save file\n");
		printf("9. Search by name\t10. Quit\n");
		printf("%s ", PROMPT);
		scanf("%d%*c", &selectedMenu);

		switch (selectedMenu)
		{
		case PrintAllItmes:
			for (int i = 0; i < moviesCount; ++i)
			{
				printf("%d: \"%s\", %.1f\n", i, movieNames[i], movieStars[i]);
			}
			break;
		case PrintAnItem:
			printf("Input the index of item to print.\n");
			printf("%s ", PROMPT);
			scanf("%d", &selectedIndex);

			if (selectedIndex < 0 || selectedIndex >= moviesCount)
			{
				printf("Invalid item.\n");
				break;
			}

			printf("%d: \"%s\", %.1f\n",
				selectedIndex, movieNames[selectedIndex], movieStars[selectedIndex]);
			break;
		case EditAnItem:
			printf("Input the index of item to edit.\n");
			printf("%s ", PROMPT);
			scanf("%d%*c", &selectedIndex);

			if (selectedIndex < 0 || selectedIndex >= moviesCount)
			{
				printf("Invalid item.\n");
				break;
			}

			printf("%d: \"%s\", %.1f\n",
				selectedIndex, movieNames[selectedIndex], movieStars[selectedIndex]);

			printf("Input new title and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", movieNames[selectedIndex]);

			printf("Input new rating and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%f%*c", movieStars + selectedIndex);

			printf("%d: \"%s\", %.1f\n",
				selectedIndex, movieNames[selectedIndex], movieStars[selectedIndex]);
			break;
		case AddAnItem:
			++moviesCount;

			if ((namesTemp = (char**)malloc(moviesCount * sizeof(char*))) == NULL)
			{
				exit(EXIT_FAILURE);
			}
			if ((starsTemp = (float*)malloc(moviesCount * sizeof(float))) == NULL)
			{
				exit(EXIT_FAILURE);
			}
			for (int i = 0; i < moviesCount - 1; ++i)
			{
				namesTemp[i] = movieNames[i];
				starsTemp[i] = movieStars[i];
			}
			if ((namesTemp[moviesCount - 1] = (char*)malloc(100 * sizeof(char))) == NULL)
			{
				exit(EXIT_FAILURE);
			}

			free(movieNames);
			free(movieStars);

			printf("Input title and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", namesTemp[moviesCount - 1]);

			printf("Input rating and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%f%*c", starsTemp + moviesCount - 1);

			movieNames = namesTemp;
			movieStars = starsTemp;

			namesTemp = NULL;
			starsTemp = NULL;

			printf("%d: \"%s\", %.1f\n",
				moviesCount - 1, movieNames[moviesCount - 1], movieStars[moviesCount - 1]);
			break;
		case InsertAnItem:

			break;
		case DeleteAnItem:

			break;
		case DeleteAllItems:

			break;
		case SaveFile:

			break;
		case SearchByName:

			break;
		case Quit:
			isQuit = 1;
			break;
		}
	}

	return 0;
}