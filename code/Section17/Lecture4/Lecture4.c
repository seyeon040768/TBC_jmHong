﻿#include <stdio.h>
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

	/* Add front */
	struct Node* temp = head;
	head = newNode;
	newNode->next = temp;

	PrintAll(head);


	newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		printf("ERROR: malloc failed.\n");
		exit(EXIT_FAILURE);
	}

	newNode->value = 3;
	newNode->next = NULL;

	/* Add back */
	struct Node* search = head;
	while (search->next != NULL)
	{
		search = search->next;
	}
	search->next = newNode;

	PrintAll(head);


	/* Find add delete an item */
	search = head;
	struct Node* prev = NULL;

	int count = 0;
	while (search != NULL)
	{
		if (search->value == 1)
		{
			break;
		}

		prev = search;
		search = search->next;
		++count;
	}

	if (search == NULL)
	{
		printf("Wrong value.\n");
		return;
	}
	else if (prev == NULL)
	{
		head = search->next;
	}
	else
	{
		prev->next = search->next;
	}
	free(search);

	PrintAll(head);

	return 0;
}