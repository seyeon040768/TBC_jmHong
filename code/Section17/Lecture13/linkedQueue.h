#pragma once

#include <stdbool.h>

#define MAX_QUEUE_SIZE 3

typedef struct Element
{
	int key;
} Element;

typedef struct Node
{
	Element item;
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
bool EnQueue(Element item, Queue* queue);
bool DeQueue(Element* pItem, Queue* queue);
void Traverse(Queue* queue, void (*func)(Element item));