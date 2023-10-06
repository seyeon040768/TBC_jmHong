#include <stdio.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTL 31

struct Book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float price;
};

struct Rectangle
{
	double width;
	double height;
};

double RectArea(struct Rectangle r)
{
	return r.width * r.height;
}

double RectAreaPtr(struct Rectangle* r)
{
	return r->width * r->height;
}

int main(void)
{
	struct Book bookToRead = { "Crime and Punishment", "Fyodor Dostoyevsky", 11.25f };

	//bookToRead = { "Alice in Wonderland", "Lewis Carrol", 20.3f }; // Error

	strcpy(bookToRead.title, "Alice in Wonderland");
	strcpy(bookToRead.author, "Lewis Carrol");
	bookToRead.price = 20.3f;


	struct Book book2 = { "Alice in Wonderland", "Lewis Carrol", 20.3f };
	bookToRead = book2;

	bookToRead = (struct Book){ "Alice in Wonderland", "Lewis Carrol", 20.3f };

	printf("%s %s\n", bookToRead.title, bookToRead.author);


	struct Rectangle rec1 = { 1.0, 2.0 };
	double area = RectArea(rec1);
	area = RectArea((struct Rectangle){ 1.0, 2.0 });

	area = RectAreaPtr(&(struct Rectangle) { .height = 1.0, .width = 2.0 });

	printf("%f\n", area);

	return 0;
}