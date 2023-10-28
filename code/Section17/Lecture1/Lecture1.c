#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXT_SIZE 100

#define PROMPT ">>"

typedef struct Movie
{
	char title[TEXT_SIZE];
	float rating;
} Movie;

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

enum ChangeLengthMode
{
	Init,
	Add,
	Delete
};

Movie* ChangeLength(int mode, Movie* MovieArray, int movieCount, int pivot)
{
	Movie* movieTemp;
	if ((movieTemp = (Movie*)malloc(movieCount * sizeof(Movie))) == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (mode == Init)
	{
		return movieTemp;
	}

	for (int i = 0; i < pivot; ++i)
	{
		movieTemp[i] = MovieArray[i];
	}

	if (mode == Add)
	{
		for (int i = pivot + 1; i < movieCount; ++i)
		{
			movieTemp[i] = MovieArray[i - 1];
		}
	}
	else if (mode == Delete)
	{
		for (int i = pivot; i < movieCount; ++i)
		{
			movieTemp[i] = MovieArray[i + 1];
		}
	}

	free(MovieArray);

	return movieTemp;
}

int main(void)
{
	char filename[TEXT_SIZE] = { '\0',};
	FILE* fp, *fSave;
	int movieCount, selectedMenu, selectedIndex;
	Movie* movieArray;
	char saveFilename[TEXT_SIZE] = { '\0', };
	char movieNameForSearch[TEXT_SIZE] = { '\0', };
	int quit = 0, foundMovieByName = 0;

	printf("Please input filename to read and press Enter.\n");
	printf("%s ", PROMPT);
	scanf("%s", filename);

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("ERROR: Cannot open file.\n");
		exit(EXIT_FAILURE);
	}

	fscanf(fp, "%d%*c", &movieCount);
	printf("%d items have been read from the file.\n", movieCount);

	movieArray = ChangeLength(Init, NULL, movieCount, -1);

	for (int i = 0; i < movieCount; ++i)
	{
		fscanf(fp, "%[^\n]s%*c", movieArray[i].title);

		fscanf(fp, "%f%*c", &movieArray[i].rating);
	}

	while (!quit)
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
			for (int i = 0; i < movieCount; ++i)
			{
				printf("%d: \"%s\", %.1f\n", i, movieArray[i].title, movieArray[i].rating);
			}
			break;
		case PrintAnItem:
			printf("Input the index of item to print.\n");
			printf("%s ", PROMPT);
			scanf("%d", &selectedIndex);

			if (selectedIndex < 0 || selectedIndex >= movieCount)
			{
				printf("Invalid item.\n");
				break;
			}

			printf("%d: \"%s\", %.1f\n",
				selectedIndex, movieArray[selectedIndex].title, movieArray[selectedIndex].rating);
			break;
		case EditAnItem:
			printf("Input the index of item to edit.\n");
			printf("%s ", PROMPT);
			scanf("%d%*c", &selectedIndex);

			if (selectedIndex < 0 || selectedIndex >= movieCount)
			{
				printf("Invalid item.\n");
				break;
			}

			printf("%d: \"%s\", %.1f\n",
				selectedIndex, movieArray[selectedIndex].title, movieArray[selectedIndex].rating);

			printf("Input new title and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", movieArray[selectedIndex].title);

			printf("Input new rating and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%f%*c", &movieArray[selectedIndex].rating);

			printf("%d: \"%s\", %.1f\n",
				selectedIndex, movieArray[selectedIndex].title, movieArray[selectedIndex].rating);
			break;
		case AddAnItem:
			++movieCount;

			movieArray = ChangeLength(Add, movieArray, movieCount, movieCount - 1);

			printf("Input title and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", movieArray[movieCount - 1].title);

			printf("Input rating and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%f%*c", &movieArray[movieCount - 1].rating);

			printf("%d: \"%s\", %.1f\n",
				movieCount - 1, movieArray[movieCount - 1].title, movieArray[movieCount - 1].rating);
			break;
		case InsertAnItem:
			printf("Input the index of item to insert.\n");
			printf("%s ", PROMPT);
			scanf("%d%*c", &selectedIndex);

			if (selectedIndex < 0 || selectedIndex >= movieCount)
			{
				printf("Invalid index.\n");
				break;
			}

			++movieCount;

			movieArray = ChangeLength(Add, movieArray, movieCount, selectedIndex);

			printf("Input title and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", movieArray[selectedIndex].title);

			printf("Input rating and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%f%*c", &movieArray[selectedIndex].rating);

			printf("%d: \"%s\", %.1f\n",
				selectedIndex, movieArray[selectedIndex].title, movieArray[selectedIndex].rating);
			break;
		case DeleteAnItem:
			printf("Input the index of item to delete.\n");
			printf("%s ", PROMPT);
			scanf("%d%*c", &selectedIndex);

			if (selectedIndex < 0 || selectedIndex >= movieCount)
			{
				printf("Invalid index.\n");
				break;
			}

			--movieCount;

			movieArray = ChangeLength(Delete, movieArray, movieCount, selectedIndex);

			break;
		case DeleteAllItems:
			free(movieArray);

			movieArray = NULL;

			movieCount = 0;

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

			fprintf(fSave, "%d\n", movieCount);

			for (int i = 0; i < movieCount; ++i)
			{
				fprintf(fSave, "%s\n%.1f\n", movieArray[i].title, movieArray[i].rating);
			}

			fclose(fSave);

			printf("%d items have been saved to the file.\n", movieCount);
			break;
		case SearchByName:
			printf("Input title to search and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", movieNameForSearch);

			for (int i = 0; i < movieCount; ++i)
			{
				if (!strcmp(movieNameForSearch, movieArray[i].title))
				{
					printf("%d: \"%s\", %.1f\n",
						i, movieArray[i].title, movieArray[i].rating);
					
					foundMovieByName = 1;
					break;
				}
			}

			if (!foundMovieByName)
			{
				printf("No movie found: %s\n", movieNameForSearch);
			}

			foundMovieByName = 0;
			break;
		case Quit:
			quit = 1;
			break;
		}
	}

	fclose(fp);

	free(movieArray);

	return 0;
}