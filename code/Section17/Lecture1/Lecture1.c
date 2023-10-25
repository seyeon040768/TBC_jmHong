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

enum ChangeLengthMode
{
	Init,
	Add,
	Delete
};

char** ChangeLengthMovieNames(char** movieNames, int moviesCount, int pivot, int mode)
{
	/*
	* mode
	* 0: init
	* 1: add
	* 2: delete
	*/

	char** namesTemp;
	if ((namesTemp = (char**)malloc(moviesCount * sizeof(char*))) == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (mode == Init)
	{
		for (int i = 0; i < moviesCount; ++i)
		{
			if ((namesTemp[i] = (char*)malloc(100 * sizeof(char))) == NULL)
			{
				exit(EXIT_FAILURE);
			}
		}

		return namesTemp;
	}

	for (int i = 0; i < pivot; ++i)
	{
		namesTemp[i] = movieNames[i];
	}
	if (mode == Add)
	{
		for (int i = pivot + 1; i < moviesCount; ++i)
		{
			namesTemp[i] = movieNames[i - 1];
		}

		if ((namesTemp[pivot] = (char*)malloc(100 * sizeof(char))) == NULL)
		{
			exit(EXIT_FAILURE);
		}
	}
	else if (mode == Delete)
	{
		for (int i = pivot; i < moviesCount; ++i)
		{
			namesTemp[i] = movieNames[i + 1];
		}
		free(movieNames[pivot]);
	}

	free(movieNames);

	return namesTemp;
}

float* ChangeLengthMovieStars(float* movieStars, int moviesCount, int pivot, int mode)
{
	/*
	* mode
	* 0: init
	* 1: add
	* 2: delete
	*/

	float* starsTemp;
	if ((starsTemp = (float*)malloc(moviesCount * sizeof(float))) == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (mode == Init)
	{
		return starsTemp;
	}

	for (int i = 0; i < pivot; ++i)
	{
		starsTemp[i] = movieStars[i];
	}
	if (mode == Add)
	{
		for (int i = pivot + 1; i < moviesCount; ++i)
		{
			starsTemp[i] = movieStars[i - 1];
		}
	}
	else if (mode == Delete)
	{
		for (int i = pivot; i < moviesCount; ++i)
		{
			starsTemp[i] = movieStars[i + 1];
		}
	}

	free(movieStars);

	return starsTemp;
}

int main(void)
{
	char filename[100] = { '\0',};
	FILE* fp, *fSave;
	int moviesCount, selectedMenu, selectedIndex;
	char** movieNames;
	float* movieStars;
	char saveFilename[100] = { '\0', };
	char movieNameForSearch[100] = { '\0', };
	int quit = 0, foundMovieByName = 0;

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

	movieNames = ChangeLengthMovieNames(NULL, moviesCount, -1, Init);
	movieStars = ChangeLengthMovieStars(NULL, moviesCount, -1, Init);

	for (int i = 0; i < moviesCount; ++i)
	{
		fscanf(fp, "%[^\n]s%*c", movieNames[i]);

		fscanf(fp, "%f%*c", movieStars + i);
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

			movieNames = ChangeLengthMovieNames(movieNames, moviesCount, moviesCount - 1, Add);
			movieStars = ChangeLengthMovieStars(movieStars, moviesCount, moviesCount - 1, Add);

			printf("Input title and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", movieNames[moviesCount - 1]);

			printf("Input rating and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%f%*c", movieStars + moviesCount - 1);

			printf("%d: \"%s\", %.1f\n",
				moviesCount - 1, movieNames[moviesCount - 1], movieStars[moviesCount - 1]);
			break;
		case InsertAnItem:
			printf("Input the index of item to insert.\n");
			printf("%s ", PROMPT);
			scanf("%d%*c", &selectedIndex);

			if (selectedIndex < 0 || selectedIndex >= moviesCount)
			{
				printf("Invalid index.\n");
				break;
			}

			++moviesCount;

			movieNames = ChangeLengthMovieNames(movieNames, moviesCount, selectedIndex, Add);
			movieStars = ChangeLengthMovieStars(movieStars, moviesCount, selectedIndex, Add);

			printf("Input title and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", movieNames[selectedIndex]);

			printf("Input rating and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%f%*c", movieStars + selectedIndex);

			printf("%d: \"%s\", %.1f\n",
				selectedIndex, movieNames[selectedIndex], movieStars[selectedIndex]);
			break;
		case DeleteAnItem:
			printf("Input the index of item to delete.\n");
			printf("%s ", PROMPT);
			scanf("%d%*c", &selectedIndex);

			if (selectedIndex < 0 || selectedIndex >= moviesCount)
			{
				printf("Invalid index.\n");
				break;
			}

			--moviesCount;

			movieNames = ChangeLengthMovieNames(movieNames, moviesCount, selectedIndex, Delete);
			movieStars = ChangeLengthMovieStars(movieStars, moviesCount, selectedIndex, Delete);

			break;
		case DeleteAllItems:
			for (int i = 0; i < moviesCount; ++i)
			{
				free(movieNames[i]);
			}
			free(movieNames);
			free(movieStars);

			movieNames = NULL;
			movieStars = NULL;

			moviesCount = 0;

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

			fprintf(fSave, "%d\n", moviesCount);

			for (int i = 0; i < moviesCount; ++i)
			{
				fprintf(fSave, "%s\n%.1f\n", movieNames[i], movieStars[i]);
			}

			fclose(fSave);

			printf("%d items have been saved to the file.\n", moviesCount);
			break;
		case SearchByName:
			printf("Input title to search and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", movieNameForSearch);

			for (int i = 0; i < moviesCount; ++i)
			{
				if (!strcmp(movieNameForSearch, movieNames[i]))
				{
					printf("%d: \"%s\", %.1f\n",
						i, movieNames[i], movieStars[i]);
					
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

	for (int i = 0; i < moviesCount; ++i)
	{
		free(movieNames[i]);
	}
	free(movieNames);
	free(movieStars);

	return 0;
}