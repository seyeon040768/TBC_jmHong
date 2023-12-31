#include <stdio.h>
#include <stdlib.h>

#include "linkedQueue.h"

void Initialize(Queue* queue)
{
	queue->front = NULL;
	queue->rear = NULL;
	queue->itemCount = 0;
}

bool IsFull(const Queue* queue)
{
	return queue->itemCount == MAX_QUEUE_SIZE;
}

bool IsEmpty(const Queue* queue)
{
	return queue->itemCount == 0;
}

bool EnQueue(Item item, Queue* queue)
{
	if (IsFull(queue))
	{
		return false;
	}

	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	node->item = item;
	node->next = NULL;

	if (IsEmpty(queue))
	{
		queue->front = node;
	}
	else
	{
		queue->rear->next = node;
	}

	queue->rear = node;

	++(queue->itemCount);

	return true;
}

bool DeQueue(Item* pItem, Queue* queue)
{
	if (IsEmpty(queue))
	{
		return false;
	}

	*pItem = queue->front->item;
	
	Node* temp = queue->front;

	queue->front = queue->front->next;

	free(temp);

	--(queue->itemCount);

	if (IsEmpty(queue))
	{
		queue->rear = NULL;
	}

	return true;
}

void Traverse(Queue* queue, void (*func)(Item item))
{
	Node* search = queue->front;

	while (search != NULL)
	{
		(*func)(search->item);
		search = search->next;
	}
}
