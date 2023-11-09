#include <stdio.h>
#include <string.h>

#include "linkedQueue.h"

Item GetItem(const int key)
{
	Item newItem;
	newItem.key = key;

	return newItem;
}

void PrintItem(Item item)
{
	printf("%d ", item.key);
}

void PrintQueue(Queue* queue)
{
	printf("Front: %d at %p, Rear: %d at %p, Size %d\n",
		queue->front == NULL ? -1 : queue->front->item.key, queue->front,
		queue->rear == NULL ? -1 : queue->rear->item.key, queue->rear, queue->itemCount);

	printf("Queue: ");
	if (IsEmpty(queue))
	{
		printf("Empty");
	}
	else
	{
		Traverse(queue, PrintItem);
	}
	printf("\n\n");
}

int main(void)
{
	Queue queue;
	Item temp;

	Initialize(&queue);

	EnQueue(GetItem(0), &queue);
	PrintQueue(&queue);

	EnQueue(GetItem(1), &queue);
	PrintQueue(&queue);

	EnQueue(GetItem(2), &queue);
	PrintQueue(&queue);

	EnQueue(GetItem(3), &queue);
	PrintQueue(&queue);

	if (DeQueue(&temp, &queue))
	{
		printf("Item from queue: %d\n", temp.key);
	}
	PrintQueue(&queue);

	if (DeQueue(&temp, &queue))
	{
		printf("Item from queue: %d\n", temp.key);
	}
	PrintQueue(&queue);

	if (DeQueue(&temp, &queue))
	{
		printf("Item from queue: %d\n", temp.key);
	}
	PrintQueue(&queue);

	if (DeQueue(&temp, &queue))
	{
		printf("Item from queue: %d\n", temp.key);
	}
	PrintQueue(&queue);


	printf("------- Circulation Test -------\n");

	Initialize(&queue);

	for (int i = 0; i < 10; ++i)
	{
		EnQueue(GetItem(1), &queue);
		PrintQueue(&queue);

		if (DeQueue(&temp, &queue))
		{
			printf("Item from queue: %d\n", temp.key);
		}
		PrintQueue(&queue);
	}

	return 0;
}