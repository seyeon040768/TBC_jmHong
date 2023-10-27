#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXT_SIZE 100

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

char** ChangeLengthMovieTitles(char** movieTitles, int moviesCount, int pivot, int mode)
{
	/*
	* mode
	* 0: init
	* 1: add
	* 2: delete
	*/

	char** titlesTemp;
	if ((titlesTemp = (char**)malloc(moviesCount * sizeof(char*))) == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (mode == Init)
	{
		for (int i = 0; i < moviesCount; ++i)
		{
			if ((titlesTemp[i] = (char*)malloc(TEXT_SIZE * sizeof(char))) == NULL)
			{
				exit(EXIT_FAILURE);
			}
		}

		return titlesTemp;
	}

	for (int i = 0; i < pivot; ++i)
	{
		titlesTemp[i] = movieTitles[i];
	}
	if (mode == Add)
	{
		for (int i = pivot + 1; i < moviesCount; ++i)
		{
			titlesTemp[i] = movieTitles[i - 1];
		}

		if ((titlesTemp[pivot] = (char*)malloc(TEXT_SIZE * sizeof(char))) == NULL)
		{
			exit(EXIT_FAILURE);
		}
	}
	else if (mode == Delete)
	{
		for (int i = pivot; i < moviesCount; ++i)
		{
			titlesTemp[i] = movieTitles[i + 1];
		}
		free(movieTitles[pivot]);
	}

	free(movieTitles);

	return titlesTemp;
}

float* ChangeLengthMovieRatings(float* movieRatings, int moviesCount, int pivot, int mode)
{
	/*
	* mode
	* 0: init
	* 1: add
	* 2: delete
	*/

	float* ratingsTemp;
	if ((ratingsTemp = (float*)malloc(moviesCount * sizeof(float))) == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (mode == Init)
	{
		return ratingsTemp;
	}

	for (int i = 0; i < pivot; ++i)
	{
		ratingsTemp[i] = movieRatings[i];
	}
	if (mode == Add)
	{
		for (int i = pivot + 1; i < moviesCount; ++i)
		{
			ratingsTemp[i] = movieRatings[i - 1];
		}
	}
	else if (mode == Delete)
	{
		for (int i = pivot; i < moviesCount; ++i)
		{
			ratingsTemp[i] = movieRatings[i + 1];
		}
	}

	free(movieRatings);

	return ratingsTemp;
}

int main(void)
{
	char filename[TEXT_SIZE] = { '\0',};
	FILE* fp, *fSave;
	int movieCount, selectedMenu, selectedIndex;
	char** movieTitles;
	float* movieRatings;
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

	movieTitles = ChangeLengthMovieTitles(NULL, movieCount, -1, Init);
	movieRatings = ChangeLengthMovieRatings(NULL, movieCount, -1, Init);

	for (int i = 0; i < movieCount; ++i)
	{
		fscanf(fp, "%[^\n]s%*c", movieTitles[i]);

		fscanf(fp, "%f%*c", movieRatings + i);
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
				printf("%d: \"%s\", %.1f\n", i, movieTitles[i], movieRatings[i]);
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
				selectedIndex, movieTitles[selectedIndex], movieRatings[selectedIndex]);
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
				selectedIndex, movieTitles[selectedIndex], movieRatings[selectedIndex]);

			printf("Input new title and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", movieTitles[selectedIndex]);

			printf("Input new rating and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%f%*c", movieRatings + selectedIndex);

			printf("%d: \"%s\", %.1f\n",
				selectedIndex, movieTitles[selectedIndex], movieRatings[selectedIndex]);
			break;
		case AddAnItem:
			++movieCount;

			movieTitles = ChangeLengthMovieTitles(movieTitles, movieCount, movieCount - 1, Add);
			movieRatings = ChangeLengthMovieRatings(movieRatings, movieCount, movieCount - 1, Add);

			printf("Input title and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", movieTitles[movieCount - 1]);

			printf("Input rating and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%f%*c", movieRatings + movieCount - 1);

			printf("%d: \"%s\", %.1f\n",
				movieCount - 1, movieTitles[movieCount - 1], movieRatings[movieCount - 1]);
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

			movieTitles = ChangeLengthMovieTitles(movieTitles, movieCount, selectedIndex, Add);
			movieRatings = ChangeLengthMovieRatings(movieRatings, movieCount, selectedIndex, Add);

			printf("Input title and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", movieTitles[selectedIndex]);

			printf("Input rating and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%f%*c", movieRatings + selectedIndex);

			printf("%d: \"%s\", %.1f\n",
				selectedIndex, movieTitles[selectedIndex], movieRatings[selectedIndex]);
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

			movieTitles = ChangeLengthMovieTitles(movieTitles, movieCount, selectedIndex, Delete);
			movieRatings = ChangeLengthMovieRatings(movieRatings, movieCount, selectedIndex, Delete);

			break;
		case DeleteAllItems:
			for (int i = 0; i < movieCount; ++i)
			{
				free(movieTitles[i]);
			}
			free(movieTitles);
			free(movieRatings);

			movieTitles = NULL;
			movieRatings = NULL;

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
				fprintf(fSave, "%s\n%.1f\n", movieTitles[i], movieRatings[i]);
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
				if (!strcmp(movieNameForSearch, movieTitles[i]))
				{
					printf("%d: \"%s\", %.1f\n",
						i, movieTitles[i], movieRatings[i]);
					
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

	for (int i = 0; i < movieCount; ++i)
	{
		free(movieTitles[i]);
	}
	free(movieTitles);
	free(movieRatings);

	return 0;
}