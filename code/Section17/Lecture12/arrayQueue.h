#pragma once

#include <stdbool.h>
#include "element.h"

#define MAX_QUEUE_SIZE 8

typedef struct Queue
{
	int front;
	int rear;
	int itemCount;
	Element itmes[MAX_QUEUE_SIZE];
} Queue;

void Initialize(Queue* queue);
bool IsFull(const Queue* queue);
bool IsEmpty(const Queue* queue);
int CountItem(const Queue* queue);
bool EnQueue(Element item, Queue* queue);
bool DeQueue(Element* pItem, Queue* queue);
void TraverseQueue(Queue* queue, void (*func)(Element item));