#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node* next;
};

void PrintAll(struct Node* head)
{
	printf("--------------------\n");
	printf("Head address = %zd\n", (unsigned long long)head);
	struct Node* search = head;
	while (search != NULL)
	{
		printf("%zd %d %zd\n", (unsigned long long)search, search->value, (unsigned long long)search->next);
		search = search->next;
	}
}

int main(void)
{
	struct Node* head = NULL;

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		printf("ERROR: malloc failed.\n");
		exit(EXIT_FAILURE);
	}
	
	newNode->value = 1;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
	}

	PrintAll(head);


	newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		printf("ERROR: malloc failed.\n");
		exit(EXIT_FAILURE);
	}

	newNode->value = 2;
	newNode->next = NULL;

	return 0;
}