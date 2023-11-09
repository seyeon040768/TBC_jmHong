#pragma once

#include <stdbool.h>
#include "item.h"

#define MAX_QUEUE_SIZE 4

typedef struct Queue
{
	int front;
	int rear;
	int itemCount;
	Item items[MAX_QUEUE_SIZE];
} Queue;

void Initialize(Queue* queue);
bool IsFull(const Queue* queue);
bool IsEmpty(const Queue* queue);
bool EnQueue(Item item, Queue* queue);
bool DeQueue(Item* pItem, Queue* queue);
void Traverse(Queue* queue, void (*func)(Item item));