#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SLEN 81

struct Name
{
	char* fname;
	char* lname;
	int letters;
};

void GetInfo(struct Name*);
void MakeInfo(struct Name*);
void ShowInfo(const struct name*);
void CleanUp(struct Name*);

int main(void)
{
	/*// Dangerous usage
	struct Name p = { "Seyeon", "Lee" };
	printf("%s %s\n", p.fname, p.lname);

	int f1 = scanf("%[^\n]%*c", p.lname);
	printf("%s %s\n", p.lname, p.fname);


	// Recommended usage
	char buffer[SLEN] = { 0, };
	int f2 = scanf("%[^\n]%*c", buffer);
	p.fname = (char*)malloc(strlen(buffer) + 1);
	if (p.fname != NULL)
	{
		strcpy(p.fname, buffer);
	}
	printf("%s %s\n", p.fname, p.lname);*/


	struct Name person;

	GetInfo(&person);
	MakeInfo(&person);
	ShowInfo(&person);
	CleanUp(&person);

	return 0;
}

void GetInfo(struct Name* person)
{
	int flag;
	char* buffer[SLEN];

	printf("Input your first name:\n");
	flag = scanf("%[^\n]%*c", buffer);
	if (flag != 1)
	{
		printf("Wrong input\n");
	}
	else
	{
		person->fname = (char*)malloc(sizeof(buffer) + 1);
		if (person->fname != NULL)
		{
			strcpy(person->fname, buffer);
		}
	}

	printf("Input your last name:\n");
	flag = scanf("%[^\n]%*c", buffer);
	if (flag != 1)
	{
		printf("Wrong input\n");
	}
	else
	{
		person->lname = (char*)malloc(sizeof(buffer) + 1);
		if (person->lname != NULL)
		{
			strcpy(person->lname, buffer);
		}
	}
}

void MakeInfo(struct Name* person)
{
	person->letters = strlen(person->fname) + strlen(person->lname);
}

void ShowInfo(const struct Name* person)
{
	printf("Hi, %s %s. Your name has %d characters.", person->fname, person->lname, person->letters);
}
void CleanUp(struct Name* person)
{
	free(person->fname);
	free(person->lname);
	person->letters = 0;
}