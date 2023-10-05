/*#include <stdio.h>
#include <string.h>

#define NLEN 30

struct NameCount
{
	char first[NLEN];
	char last[NLEN];
	int num;
};

void ReceiveInput(struct NameCount*);
void CountCharacters(struct NameCount*);
void ShowResult(const struct NameCount*);
char* s_gets(char*, int);

int main(void)
{
	struct NameCount userName;

	ReceiveInput(&userName);
	CountCharacters(&userName);
	ShowResult(&userName);

	return 0;
}

void ReceiveInput(struct NameCount* userName)
{
	int flag;

	printf("Input your first name:\n");
	printf(">>");
	// s_gets(userName->first, NLEN);
	flag = scanf("%[^\n]%*c", userName->first);
	if (flag != 1)
	{
		printf("Wrong input\n");
	}

	printf("Input your last name:\n");
	printf(">>");
	// s_gets(userName->last, NLEN);
	flag = scanf("%[^\n]%*c", userName->last);
	if (flag != 1)
	{
		printf("Wrong input\n");
	}
}

void CountCharacters(struct NameCount* userName)
{
	userName->num = strlen(userName->first) + strlen(userName->last);
}

void ShowResult(const struct NameCount* userName)
{
	printf("Hi, %s %s. Your name has %d characters.", userName->first, userName->last, userName->num);
}

char* s_gets(char* st, int n)
{
	char* res;
	char* find;

	res = fgets(st, n, stdin);
	if (res)
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

	return res;
}*/


#include <stdio.h>
#include <string.h>

#define NLEN 30

struct NameCount
{
	char first[NLEN];
	char last[NLEN];
	int num;
};

struct NameCount ReceiveInput();
struct NameCount CountCharacters(struct NameCount);
void ShowResult(const struct NameCount);
char* s_gets(char*, int);

int main(void)
{
	struct NameCount userName;

	userName = ReceiveInput();
	userName = CountCharacters(userName);
	ShowResult(userName);

	return 0;
}

struct NameCount ReceiveInput()
{
	struct NameCount userName;
	int flag;

	printf("Input your first name:\n");
	printf(">>");
	// s_gets(userName->first, NLEN);
	flag = scanf("%[^\n]%*c", userName.first);
	if (flag != 1)
	{
		printf("Wrong input\n");
	}

	printf("Input your last name:\n");
	printf(">>");
	// s_gets(userName->last, NLEN);
	flag = scanf("%[^\n]%*c", userName.last);
	if (flag != 1)
	{
		printf("Wrong input\n");
	}

	userName.num = 0;

	return userName;
}

struct NameCount CountCharacters(struct NameCount userName)
{
	userName.num = strlen(userName.first) + strlen(userName.last);

	return userName;
}

void ShowResult(const struct NameCount userName)
{
	printf("Hi, %s %s. Your name has %d characters.", userName.first, userName.last, userName.num);
}

char* s_gets(char* st, int n)
{
	char* res;
	char* find;

	res = fgets(st, n, stdin);
	if (res)
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

	return res;
}