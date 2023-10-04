#include <stdio.h>
#include <string.h>

#define MAX_TITLE 40
#define MAX_AUTHOR 40
#define MAX_BOOKS 3

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}

	return ret_val;
}

struct Book
{
	char title[MAX_TITLE];
	char author[MAX_AUTHOR];
	float price;
};

int main(void)
{
	struct Book library[MAX_BOOKS];

	int count = 0;

	while (1)
	{
		printf("Input a book title or press [Enter] to stop\n");
		printf(">>");
		if (*s_gets(library[count].title, MAX_TITLE) == '\0')
		{
			break;
		}

		printf("Input the author.\n");
		printf(">>");
		s_gets(library[count].author, MAX_AUTHOR);


		printf("Input the price.\n");
		printf(">>");
		scanf("%f%*c", &library[count].price); // remove '\n'

		++count;

		if (count == MAX_BOOKS)
		{
			printf("No more books.\n");
			break;
		}
	}

	if (count > 0)
	{
		printf("\nThe list of books:\n");
		for (int i = 0; i < count; ++i)
		{
			printf("\"%s\" written by %s: $%.1f\n",
				library[i].title, library[i].author, library[i].price);
		}
	}
	else
	{
		printf("No books to show.\n");
	}

	return 0;
}