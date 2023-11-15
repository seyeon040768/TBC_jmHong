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

		++(pTree->size);
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

				++(pTree->size);
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

				++(pTree->size);
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
	Node** previousNode = &(pTree->root);
	Node* search = pTree->root;

	while (search != NULL)
	{
		if (pItem->key == search->item.key)
		{
			break;
		}

		if (pItem->key < search->item.key)
		{
			previousNode = &(search->left);
			search = search->left;
		}
		else
		{
			previousNode = &(search->right);
			search = search->right;
		}
	}

	if (search == NULL)
	{
		return false;
	}

	if (search->left == NULL && search->right == NULL)
	{
		*previousNode = NULL;
		free(search);

		return true;
	}
	else if (search->left == NULL)
	{
		*previousNode = search->right;
		free(search);

		return true;
	}
	else if (search->right == NULL)
	{
		*previousNode = search->left;
		free(search);

		return true;
	}
	else
	{
		*previousNode = search->left;

		Node* temp = *previousNode;
		while (temp->right != NULL)
		{
			temp = temp->right;
		}

		temp->right = search->right;

		free(search);
		return true;
	}
}

void TraverseRecursive(Node* pNode, void (*pFunc)(Item item))
{
	if (pNode == NULL)
	{
		return;
	}

	TraverseRecursive(pNode->left, pFunc);
	TraverseRecursive(pNode->right, pFunc);

	(*pFunc)(pNode->item);
}

void Traverse(const Tree* pTree, void (*pFunc)(Item item))
{
	TraverseRecursive(pTree->root, pFunc);
}

void DeleteRecursive(Node* pNode)
{
	if (pNode == NULL)
	{
		return;
	}

	DeleteRecursive(pNode->left);
	DeleteRecursive(pNode->right);

	free(pNode);
}

void DeleteAll(Tree* pTree)
{
	DeleteRecursive(pTree->root);
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