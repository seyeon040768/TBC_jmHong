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

bool FindItemByIndex(const List* pList, const int index, Item* item)
{
	Node* search;
	int i = 0;

	search = pList->head;

	while (search != NULL)
	{
		if (i == index)
		{
			*item = search->item;

			return true;
		}
		search = search->next;
		++i;
	}

	return false;
}

bool AddItem(Item item, List* pList);
void InsertByIndex(Item item, List* pList, int index);
void RemoveByIndex(List* pList, int index);
bool Find(const List* pList, Item itemToFind, int* index, Item* itemFound, bool (*CompareFunc)(Item a, Item b));

unsigned int CountItems(const List* pList);
void PrintAllItems(const List* pList, void (*PrintAnItemFunc)(Item item));
void WriteAllItems(const List* pList, FILE* file, void (*WriteAnItemFunc)(FILE* file, Item item));

void Traverse(const List* pList, void (*pFunc)(Item item));
void ClearList(List* pList);

void RemoveFirstItem(List* pList);