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
	int moviesCount, selectedMenu, selelctedIndex;
	char** movieNames;
	float* movieStars;

	printf("Please input filename to read and press Enter.\n");
	printf("%s ", PROMPT);
	scanf("%s", filename);

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("ERROR: Cannot open file.\n");
		exit(EXIT_FAILURE);
	}

	fscanf(fp, "%d%*c", &moviesCount);
	printf("%d items have been read from the file.\n\n", moviesCount);

	if ((movieNames = (char**)malloc(moviesCount * sizeof(char*))) == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if ((movieStars = (float*)malloc(moviesCount * sizeof(float))) == NULL)
	{
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < moviesCount; ++i)
	{
		char temp[100] = { '\0', };
		fscanf(fp, "%[^\n]s%*c", temp);

		movieNames[i] = (char*)malloc((strlen(temp) + 1) * sizeof(char));
		memcpy(movieNames[i], temp, strlen(temp) + 1);

		fscanf(fp, "%f%*c", movieStars + i);
	}

	printf("Please select an option and press enter.\n");
	printf("1. Print all items\t2. Print an item\n");
	printf("3. Edit an item\t\t4. Add an item\n");
	printf("5. Insert an item\t6. Delete an item\n");
	printf("7. Delete all items\t8. Save file\n");
	printf("9. Search by name\t10. Quit\n");
	printf("%s ", PROMPT);
	scanf("%d", &selectedMenu);

	switch (selectedMenu)
	{
	case PrintAllItmes:
		for (int i = 0; i < moviesCount; ++i)
		{
			printf("%d: \"%s\", %.1f\n", i, movieNames[i], movieStars[i]);
		}
		break;
	case PrintAnItem:

		break;
	case EditAnItem:

		break;
	case AddAnItem:

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

		break;
	}

	return 0;
}