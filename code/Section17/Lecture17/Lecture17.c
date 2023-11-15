#include <stdio.h>
#include <string.h>

#include "tree.h"

#define SPACING 30

int Compare(const Item first, const Item second)
{
	return first.key - first.value;
}

void PrintItem(Item item)
{
	printf("%d: %d\n", item.key, item.value);
}

void Print2DUtil(Node* root, int space)
{
	space += SPACING;

	if (root == NULL)
	{
		for (int i = SPACING; i < space; ++i)
		{
			printf(" ");
		}
		printf("NULL");
		return;
	}

	Print2DUtil(root->right, space);

	printf("\n");
	for (int i = SPACING; i < space; ++i)
	{
		printf(" ");
	}
	PrintItem(root->item);

	Print2DUtil(root->left, space);
}

void PrintNode(Node* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%d: %d -> ", root->item.key, root->item.value);

	if (root->left == NULL)
	{
		printf("NULL, ");
	}
	else
	{
		printf("%d: %d, ", root->left->item.key, root->left->item.value);
	}

	if (root->right == NULL)
	{
		printf("NULL, ");
	}
	else
	{
		printf("%d: %d, ", root->right->item.key, root->right->item.value);
	}

	printf("\n");

	PrintNode(root->left);
	PrintNode(root->right);
}

void PrintTree(Tree* pTree)
{
	printf("\n--------------------\n");

	Traverse(pTree, PrintItem);

	printf("\n--------------------\n");

	Print2DUtil(pTree->root, 0);

	printf("\n--------------------\n");

	PrintNode(pTree->root);
}

int main(void)
{
	/* Assume that there is no duplicated items */

	Item items[] = {
		{1, 11},
		{6, 16},
		{4, 14},
		{8, 18},
		{2, 12},
		{9, 19},
		{0, 10},
		{5, 15},
		{3, 13},
		{7, 17},
	};

	int n = sizeof(items) / sizeof(items[0]);

	Tree tree;
	Initialize(&tree, &Compare);

	for (int i = 0; i < n; ++i)
	{
		AddItem(&items[i], &tree);
	}

	/* Try to add duplicated Item */
	AddItem(&items[2], &tree);
	PrintTree(&tree);

	/* Searching Test */
	Item key = { 7, };
	Item* result = TreeSearch(&tree, key);
	if (result == NULL)
	{
		printf("\nSearch failed.\n");
	}
	else
	{
		printf("\n%d is the %d\n", result->key, result->value);
	}

	/* Deleting tests */
	key.key = 1;
	DeleteItem(&key, &tree);
	PrintTree(&tree);

	DeleteAll(&tree);

	return 0;
}