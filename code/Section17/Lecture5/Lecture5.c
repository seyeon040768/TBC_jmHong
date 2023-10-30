#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXT_SIZE 100

#define PROMPT ">>"

typedef struct Movie
{
	char title[TEXT_SIZE];
	float rating;
	struct Movie* next;
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

Movie* FindMovieByIndex(Movie* head, int index)
{
	Movie* search = head;
	int i = 0;

	while (search != NULL)
	{
		if (i == index)
		{
			return search;
		}
		search = search->next;

		++i;
	}

	return NULL;
}

Movie* AddMovie(Movie* head, Movie* node, int index)
{
	if (index == 0)
	{
		node->next = head;
		return node;
	}

	Movie* prev = FindMovieByIndex(head, index - 1);
	if (prev == NULL)
	{
		return NULL;
	}

	node->next = prev->next;
	prev->next = node;

	return head;
}

Movie* DeleteMovie(Movie* head, int index)
{
	if (index == 0)
	{
		Movie* temp = head->next;
		free(head);
		return temp;
	}

	Movie* prev = FindMovieByIndex(head, index - 1);
	if (prev == NULL)
	{
		return NULL;
	}

	Movie* temp = prev->next->next;

	free(prev->next);

	prev->next = temp;

	return head;
}

int main(void)
{
	char filename[TEXT_SIZE] = { '\0', };
	FILE* fp, * fSave;
	size_t movieCount;
	int selectedMenu, selectedIndex;
	Movie* head = NULL, * temp = NULL;
	char saveFilename[TEXT_SIZE] = { '\0', };
	char movieNameForSearch[TEXT_SIZE] = { '\0', };
	int foundMovieByName = 0;

	printf("Please input filename to read and press Enter.\n");
	printf("%s ", PROMPT);
	scanf("%s", filename);

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("ERROR: Cannot open file.\n");
		exit(EXIT_FAILURE);
	}

	if (fscanf(fp, "%zd%*c", &movieCount) != 1)
	{
		printf("ERROR: Wrong Format.\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < movieCount; ++i)
	{
		Movie* node = (Movie*)malloc(sizeof(Movie));
		if (node == NULL)
		{
			exit(EXIT_FAILURE);
		}

		if (fscanf(fp, "%[^\n]s%*c", node->title) != 1 || fscanf(fp, "%f%*c", &node->rating) != 1)
		{
			printf("ERROR: Wrong Format.\n");
			exit(EXIT_FAILURE);
		}
		node->next = NULL;

		if (i == 0)
		{
			head = node;
		}
		else
		{
			temp->next = node;
		}
		temp = node;
	}
	temp = NULL;

	printf("%zd items have been read from the file.\n", movieCount);

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
		scanf("%d%*c", &selectedMenu);

		switch (selectedMenu)
		{
		case PrintAllItmes:
			temp = head;
			for (int i = 0; i < movieCount; ++i)
			{
				printf("%d: \"%s\", %.1f\n", i, temp->title, temp->rating);
				temp = temp->next;
			}
			temp = NULL;
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

			temp = FindMovieByIndex(head, selectedIndex);
			if (temp == NULL)
			{
				break;
			}

			printf("%d: \"%s\", %.1f\n",
				selectedIndex, temp->title, temp->rating);

			temp = NULL;
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

			temp = FindMovieByIndex(head, selectedIndex);

			printf("%d: \"%s\", %.1f\n",
				selectedIndex, temp->title, temp->rating);

			printf("Input new title and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", temp->title);

			printf("Input new rating and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%f%*c", &temp->rating);

			printf("%d: \"%s\", %.1f\n",
				selectedIndex, temp->title, temp->rating);

			temp = NULL;
			break;
		case AddAnItem:
			temp = (Movie*)malloc(sizeof(Movie));

			printf("Input title and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", temp->title);

			printf("Input rating and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%f%*c", &temp->rating);

			head = AddMovie(head, temp, movieCount);
			++movieCount;

			printf("%zd: \"%s\", %.1f\n",
				movieCount - 1, temp->title, temp->rating);

			temp = NULL;
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

			temp = (Movie*)malloc(sizeof(Movie));

			printf("Input title and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", temp->title);

			printf("Input rating and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%f%*c", &temp->rating);

			head = AddMovie(head, temp, selectedIndex);
			++movieCount;

			printf("%zd: \"%s\", %.1f\n",
				movieCount - 1, temp->title, temp->rating);

			temp = NULL;
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

			head = DeleteMovie(head, selectedIndex);

			--movieCount;
			break;
		case DeleteAllItems:
			while (head == NULL)
			{
				head = DeleteMovie(head, 0);
			}

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

			fprintf(fSave, "%zd\n", movieCount);

			temp = head;
			while (temp != NULL)
			{
				fprintf(fSave, "%s\n%.1f\n", temp->title, temp->rating);
				temp = temp->next;
			}
			temp = NULL;

			fclose(fSave);

			printf("%zd items have been saved to the file.\n", movieCount);
			break;
		case SearchByName:
			printf("Input title to search and press enter.\n");
			printf("%s ", PROMPT);
			scanf("%[^\n]%*c", movieNameForSearch);

			temp = head;
			for (int i = 0; i < movieCount; ++i)
			{
				if (!strcmp(movieNameForSearch, temp->title))
				{
					printf("%d: \"%s\", %.1f\n",
						i, temp->title, temp->rating);
					break;
				}
				temp = temp->next;
			}

			if (temp == NULL)
			{
				printf("No movie found: %s\n", movieNameForSearch);
			}
			temp = NULL;

			foundMovieByName = 0;
			break;
		case Quit:
			while (head == NULL)
			{
				head = DeleteMovie(head, 0);
			}

			exit(0);
			break;
		}
	}

	return 0;
}