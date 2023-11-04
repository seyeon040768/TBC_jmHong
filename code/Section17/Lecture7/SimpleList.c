#include "SimpleList.h"

#include <stdlib.h>

void InitializeList(List* pList)
{
	pList->head = NULL;
	pList->size = 0;
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

	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL)
	{
		printf("malloc Error\n");
		exit(EXIT_FAILURE);
	}
	node->item = item;
	node->next = NULL;

	if (pList->size == 0)
	{
		pList->head = node;
		++(pList->size);

		return true;
	}

	if (index == 0)
	{
		node->next = pList->head->next;

		pList->head = node;

		++(pList->size);

		return true;
	}

	Node* prev = FindNodeByIndex(pList, index - 1);
	if (prev == NULL)
	{
		free(node);
		return false;
	}

	node->next = prev->next;
	prev->next = node;

	++(pList->size);

	return true;
}

bool RemoveItem(List* pList, int index)
{
	if (index < 0 || index > pList->size)
	{
		return false;
	}

	Node* temp = NULL;

	if (index == 0)
	{
		temp = pList->head;
		pList->head = pList->head->next;
		free(temp);

		--(pList->size);

		return true;
	}

	Node* prev = FindNodeByIndex(pList, index - 1);
	if (prev == NULL)
	{
		return false;
	}

	temp = prev->next;
	prev->next = prev->next->next;
	free(temp);

	--(pList->size);

	return true;
}

bool Find(const List* pList, Item itemToFind, int* index, Item* itemFound, bool (*CompareFunc)(Item a, Item b))
{
	Node* search;
	int i = 0;

	search = pList->head;

	while (search != NULL)
	{
		if ((*CompareFunc)(search->item, itemToFind))
		{
			*index = i;
			*itemFound = search->item;
			return true;
		}
		search = search->next;
		++i;
	}

	return false;
}

void PrintAllItems(const List* pList, void (*PrintAnItemFunc)(Item item, int i))
{
	Node* search = pList->head;
	int i = 0;

	while (search != NULL)
	{
		(*PrintAnItemFunc)(search->item, i);
		++i;

		search = search->next;
	}
}

void PrintAnItem(const List* pList, const int index, void (*PrintAnItemFunc)(Item item, int i))
{
	if (index < 0 || index > pList->size)
	{
		return;
	}

	Node* search = FindNodeByIndex(pList, index);

	if (search == NULL)
	{
		exit(EXIT_FAILURE);
	}

	(*PrintAnItemFunc)(search->item, index);
}

void WriteAllItems(const List* pList, FILE* file, void (*WriteAnItemFunc)(FILE* file, Item item))
{
	Node* search = pList->head;

	while (search != NULL)
	{
		(*WriteAnItemFunc)(file, search->item);

		search = search->next;
	}
}

void Traverse(const List* pList, void (*pFunc)(Item item))
{
	Node* search = pList->head;

	while (search != NULL)
	{
		(*pFunc)(search->item);

		search = search->next;
	}
}

void ClearList(List* pList)
{
	Node* search = pList->head;

	while (search != NULL)
	{
		Node* next = search->next;

		free(search);

		search = next;
	}

	pList->size = 0;
}