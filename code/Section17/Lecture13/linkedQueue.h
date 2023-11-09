#pragma once

#include <stdbool.h>

#define MAX_QUEUE_SIZE 3

typedef struct Item
{
	int key;
} Item;

typedef struct Node
{
	Item item;
	struct Node* next;
} Node;

typedef struct Queue
{
	Node* front;
	Node* rear;
	int itemCount;
} Queue;

void Initialize(Queue* queue);
bool IsFull(const Queue* queue);
bool IsEmpty(const Queue* queue);
bool EnQueue(Item item, Queue* queue);
bool DeQueue(Item* pItem, Queue* queue);
void Traverse(Queue* queue, void (*func)(Item item));