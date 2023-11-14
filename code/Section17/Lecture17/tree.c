#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

static int(*CompareFunc)(const Item item1, const Item item2) = NULL;

Node* MakeNode(Item item)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL)
	{
		return NULL;
	}

	node->item = item;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void Initialize(Tree* pTree, int(Compare)(const Item item1, const Item item2))
{
	pTree->root = NULL;
	pTree->size = NULL;
	CompareFunc = Compare;
}

bool IsEmpty(const Tree* pTree)
{
	return pTree->root == NULL;
}

bool IsFull(const Tree* pTree)
{
	return pTree->size == MAX_TREE_SIZE;
}

bool AddItem(const Item* pItem, Tree* pTree)
{
	if (IsFull(pTree))
	{
		return false;
	}

	if (IsEmpty(pTree))
	{
		if (!(pTree->root = MakeNode(*pItem)))
		{
			return false;
		}

		return true;
	}

	Node* search = pTree->root;

	while (search != NULL)
	{
		if (pItem->key == search->item.key)
		{
			return false;
		}

		if (pItem->key < search->item.key)
		{
			if (search->left == NULL)
			{
				if (!(search->left = MakeNode(*pItem)))
				{
					return false;
				}

				return true;
			}
			search = search->left;
		}
		else
		{
			if (search->right == NULL)
			{
				if (!(search->right = MakeNode(*pItem)))
				{
					return false;
				}

				return true;
			}
			search = search->right;
		}
	}

	return false;
}

bool InTree(const Item* pItem, const Tree* pTree)
{
	if (IsEmpty(pTree))
	{
		return false;
	}

	Node* search = pTree->root;

	while (search != NULL)
	{
		if (pItem->key == search->item.key)
		{
			return true;
		}

		if (pItem->key < search->item.key)
		{
			search = search->left;
		}
		else
		{
			search = search->right;
		}
	}

	return false;
}

bool DeleteItem(const Item* pItem, Tree* pTree)
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
	if (IsEmpty(pTree))
	{
		return NULL;
	}

	Node* search = pTree->root;

	while (search != NULL)
	{
		if (key.key == search->item.key)
		{
			return &(search->item);
		}

		if (key.key < search->item.key)
		{
			search = search->left;
		}
		else
		{
			search = search->right;
		}
	}

	return NULL;
}