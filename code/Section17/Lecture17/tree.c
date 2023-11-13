#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

static int(*CompareFunc)(const Item item1, const Item item2) = NULL;

void Initialize(Tree* pTree, int(Compare)(const Item item1, const Item item2))
{
	pTree->root = NULL;
	pTree->size = NULL;
	CompareFunc = Compare;
}

bool IsEmpty(const Tree* pTree)
{

}

bool IsFull(const Tree* pTree)
{

}

bool AddItem(const Item* pi, Tree* pTree)
{

}

bool InTree(const Item* pi, const Tree* pTree)
{

}

bool DeleteItem(const Item* pi, Tree* pTree)
{

}

void Traverse(const Tree* pTree, void (*pFunc)(Item item))
{

}

void DeleteAll(Tree* pTree)
{

}

Item* TreeSearch(Tree* pTree, const Item key)
{

}