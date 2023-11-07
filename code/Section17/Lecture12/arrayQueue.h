#pragma once

#include <stdbool.h>
#include "element.h"

#define MAX_QUEUE_SIZE 4

typedef struct Queue
{
	int front;
	int rear;
	int itemCount;
	Element items[MAX_QUEUE_SIZE];
} Queue;

void Initialize(Queue* queue);
bool IsFull(const Queue* queue);
bool IsEmpty(const Queue* queue);
bool EnQueue(Element item, Queue* queue);
bool DeQueue(Element* pItem, Queue* queue);
void Traverse(Queue* queue, void (*func)(Element item));