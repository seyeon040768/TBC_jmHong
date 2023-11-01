#include "SimpleList.h"

#include <stdlib.h>

void InitializeList(List* pList)
{
	pList->head = NULL;
}

bool IsEmpty(const List* pList)
{
	return pList->head == NULL;
}

unsigned int CountItems(const List* pList)
{
	Node* search;
	unsigned int count = 0;

	search = pList->head;

	while (search != NULL)
	{
		search = search->next;

		++count;
	}

	return count;
}

Node* FindNodeByIndex(const List* pList, const int index)
{
	Node* search;
	int i = 0;

	search = pList->head;

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

bool AddItem(Item item, List* pList, const int index)
{
	if (index < 0 || index > pList->size)
	{
		return false;
	}

	Node* node = (Node*)malloc(sizeof(Node*));
	if (node == NULL)
	{
		printf("malloc Error\n");
		exit(EXIT_FAILURE);
	}
	node->item = item;
	node->next = NULL;

	if (index == 0)
	{
		node->next = pList->head->next;

		pList->head = node;

		return true;
	}

	Node* prev = FindNodeByIndex(pList, index - 1);

	node->next = prev->next;
	prev->next = node;

	return true;
}

void RemoveByIndex(List* pList, int index);
bool Find(const List* pList, Item itemToFind, int* index, Item* itemFound, bool (*CompareFunc)(Item a, Item b));

unsigned int CountItems(const List* pList);
void PrintAllItems(const List* pList, void (*PrintAnItemFunc)(Item item));
void WriteAllItems(const List* pList, FILE* file, void (*WriteAnItemFunc)(FILE* file, Item item));

void Traverse(const List* pList, void (*pFunc)(Item item));
void ClearList(List* pList);

void RemoveFirstItem(List* pList);