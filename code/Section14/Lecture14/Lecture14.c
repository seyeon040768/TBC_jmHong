#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SLEN 101

struct Book
{
	char name[SLEN];
	char author[SLEN];
};

void PrintBooks(const struct Book* book, int n);
void WriteBooks(const char* filename, const struct Book* books, int n);
struct Book* ReadBooks(const char* filename, int* n);
void ReadBooks2(const char* filename, struct Book** booksDptr, int* n);
void WriteBooksBinary(const char* filename, const struct Book* books, int n);
struct Book* ReadBooksBinary(const char* filename, int* n);

int main(void)
{
	int temp;
	int n = 3;

	struct Book* myBooks = (struct Book*)malloc(sizeof(struct Book) * 3);

	if (!myBooks)
	{
		exit(EXIT_FAILURE);
	}

	myBooks[0] = (struct Book){ "The Great Gatsby", "F. Scott Fitzgerald" };
	myBooks[1] = (struct Book){ "Hamlet", "William Shakespeare" };
	myBooks[2] = (struct Book){ "The Odyssey", "Homer" };

	PrintBooks(myBooks, n);

	printf("\nWriting to a file.\n");
	//WriteBooks("books.txt", myBooks, n);
	WriteBooksBinary("books.dat", myBooks, n);
	free(myBooks);
	n = 0;
	printf("Done.\n");

	printf("\nPress any key to read data from a file.\n\n");
	temp = _getch();

	//myBooks = ReadBooks("books.txt", &n);
	//ReadBooks2("books.txt", &myBooks, &n);
	myBooks = ReadBooksBinary("books.dat", &n);
	PrintBooks(myBooks, n);
	free(myBooks);
	n = 0;

	return 0;
}

void PrintBooks(const struct Book* books, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("Book %d: \"%s\" written by \"%s\"\n", i + 1, books[i].name, books[i].author);
	}
}

void WriteBooks(const char* filename, const struct Book* books, int n)
{
	FILE* booksFile = fopen(filename, "w");
	if (!booksFile)
	{
		exit(EXIT_FAILURE);
	}

	fprintf(booksFile, "%d\n", n);

	for (int i = 0; i < n; ++i)
	{
		fprintf(booksFile, "%s\n%s\n", books[i].name, books[i].author);
	}

	fclose(booksFile);
}

struct Book* ReadBooks(const char* filename, int* n)
{
	FILE* booksFile = fopen(filename, "r");
	if (!booksFile)
	{
		exit(EXIT_FAILURE);
	}

	fscanf(booksFile, "%d\n", n);

	struct Book* books = (struct Book*)calloc(sizeof(struct Book), *n);
	if (!books)
	{
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < *n; ++i)
	{
		fscanf(booksFile, "%[^\n]%*c", books[i].name);
		fscanf(booksFile, "%[^\n]%*c", books[i].author);
	}

	fclose(booksFile);

	return books;
}

void ReadBooks2(const char* filename, struct Book** booksDptr, int* n)
{
	FILE* booksFile = fopen(filename, "r");
	if (!booksFile)
	{
		exit(EXIT_FAILURE);
	}

	fscanf(booksFile, "%d\n", n);

	struct Book* books = (struct Book*)malloc(sizeof(struct Book) * (*n));
	if (!books)
	{
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < *n; ++i)
	{
		fscanf(booksFile, "%[^\n]%*c", books[i].name);
		fscanf(booksFile, "%[^\n]%*c", books[i].author);
	}

	fclose(booksFile);

	*booksDptr = books;
}

void WriteBooksBinary(const char* filename, const struct Book* books, int n)
{
	FILE* booksFile = fopen(filename, "wb");
	if (!booksFile)
	{
		exit(EXIT_FAILURE);
	}

	fwrite(&n, sizeof(n), 1, booksFile);

	fwrite(books, sizeof(struct Book), n, booksFile);

	fclose(booksFile);
}

struct Book* ReadBooksBinary(const char* filename, int* n)
{
	FILE* booksFile = fopen(filename, "rb");
	if (!booksFile)
	{
		exit(EXIT_FAILURE);
	}

	fread(n, sizeof(*n), 1, booksFile);

	struct Book* books = (struct Book*)malloc(sizeof(struct Book) * (*n));
	if (!books)
	{
		exit(EXIT_FAILURE);
	}

	fread(books, sizeof(struct Book), *n, booksFile);

	fclose(booksFile);

	return books;
}