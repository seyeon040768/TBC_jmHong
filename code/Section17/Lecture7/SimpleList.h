#pragma once

#include <stdio.h>
#include <stdbool.h>

#define TEXT_SIZE 100

struct Movie
{
	char title[TEXT_SIZE];
	float rating;
};

typedef struct Movie Item;

typedef struct Node
{
	Item item;
	struct Node* next;
} Node;

typedef struct List
{
	Node* head;
	int size;
} List;

void InitializeList(List* pList);
bool IsEmpty(const List* pList);
unsigned int CountItems(const List* pList);
Node* FindNodeByIndex(const List* pList, const int index);
bool AddItem(Item item, List* pList, const int index);
bool RemoveItem(List* pList, int index);
bool Find(const List* pList, Item itemToFind, int* index, Item* itemFound, bool (*CompareFunc)(Item a, Item b));

void PrintAllItems(const List* pList, void (*PrintAnItemFunc)(Item item));
void WriteAllItems(const List* pList, FILE* file, void (*WriteAnItemFunc)(FILE* file, Item item));

void Traverse(const List* pList, void (*pFunc)(Item item));
void ClearList(List* pList);