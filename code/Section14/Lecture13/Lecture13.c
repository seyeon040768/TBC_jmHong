#include <stdio.h>
#include <stdlib.h>

#define SLEN 101

struct Book
{
	char name[SLEN];
	char author[SLEN];
};

void PrintBooks(const struct Book* book, int n);

int main(void)
{
	//struct Book myBooks[3];
	struct Book* myBooks = (struct Book*)malloc(sizeof(struct Book) * 3);

	if (!myBooks)
	{
		exit(EXIT_FAILURE);
	}
	myBooks[0] = (struct Book){ "The Great Gatsby", "F. Scott Fitzgerald" };
	myBooks[1] = (struct Book){ "Hamlet", "William Shakespeare" };
	myBooks[2] = (struct Book){ "The Odyssey", "Homer" };

	PrintBooks(myBooks, 3);

	return 0;
}

void PrintBooks(const struct Book* books, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("Book %d: \"%s\" written by \"%s\"\n", n + 1, books[i].name, books[i].author);
	}
}