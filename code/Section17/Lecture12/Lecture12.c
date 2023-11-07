#include <stdio.h>
#include <string.h>

#include "arrayQueue.h"

Element GetItem(const int key)
{
	Element newItem;
	newItem.key = key;
	return newItem;
}

void PrintItem(Element item)
{
	printf("%d ", item.key);
}

void PrintQueue(Queue* queue)
{
	printf("Front: %d, Rear: %d, Size: %d\n", queue->front, queue->rear, queue->itemCount);

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
	Element temp;

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