#include <stdio.h>

struct Name
{
	char first[20];
	char last[20];
};

struct Person
{
	int id;
	struct Name name;
};

struct Person2
{
	int id;
	struct { char first[20]; char last[20]; }; // anonymous structure
};

int main(void)
{
	struct Person ted = { 123, {"Bill", "Gates"} };
	struct Person ted3 = { 125, "Robert", "Hand" };

	puts(ted.name.first);
	puts(ted3.name.first);

	struct Person2 ted2 = { 124, {"Steve", "Wozniak"} };
	puts(ted2.first);

	return 0;
}