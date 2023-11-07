#include <stdio.h>
#include "arrayQueue.h"

void Initialize(Queue* queue)
{
	queue->front = 0;
	queue->rear = 0;
	queue->itemCount = 0;
}

bool IsFull(const Queue* queue)
{
	return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

bool IsEmpty(const Queue* queue)
{
	return queue->front == queue->rear;
}

bool EnQueue(Element item, Queue* queue)
{
	if (IsFull(queue))
	{
		printf("Queue is full. Cannot enqueue.\n");
		return false;
	}

	queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;

	queue->items[queue->rear] = item;

	++(queue->itemCount);

	return true;
}

bool DeQueue(Element* pItem, Queue* queue)
{
	if (IsEmpty(queue))
	{
		printf("Queue is empty. Cannot dequeue.\n");
		return false;
	}

	queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;

	*pItem = queue->items[queue->front];

	--(queue->itemCount);

	return true;
}

void Traverse(Queue* queue, void (*func)(Element item))
{
	// itemCount의 최대값은 MAX_QUEUE_SIZE - 1
	for (int i = 1; i <= queue->itemCount; ++i)
	{
		(*func)(queue->items[(queue->front + i) % MAX_QUEUE_SIZE]);
	}
}
