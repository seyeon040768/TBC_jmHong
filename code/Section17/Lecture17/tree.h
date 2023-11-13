#pragma once

#include <stdbool.h>

#define MAX_TREE_SIZE 20

typedef struct
{
	int key;
	int value;
} Item;

typedef struct Node
{
	Item item;
	struct Node* left;
	struct Node* right;
} Node;

typedef struct Tree
{
	Node* root;
	int size;
} Tree;

void Initialize(Tree* pTree, int(Compare)(const Item item1, const Item item2));
bool IsEmpty(const Tree* pTree);
bool IsFull(const Tree* pTree);
bool AddItem(const Item* pi, Tree* pTree);
bool InTree(const Item* pi, const Tree* pTree);
bool DeleteItem(const Item* pi, Tree* pTree);
void Traverse(const Tree* pTree, void (*pFunc)(Item item));
void DeleteAll(Tree* pTree);
Item* TreeSearch(Tree* pTree, const Item key);