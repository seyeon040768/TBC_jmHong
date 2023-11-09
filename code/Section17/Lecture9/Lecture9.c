#include <stdio.h>
#include "stack.h"

PrintStack(const Stack* stack)
{
	printf("Stack: ");
	if (IsEmpty(stack))
	{
		printf("Empty");
	}
	else
	{
		for (int i = 0; i <= stack->top; ++i)
		{
			printf("%d ", stack->items[i].key);
		}
	}
	printf("\n");
}

Item GetItem(const int key)
{
	Item newItem;
	newItem.key = key;
	return newItem;
}

int main(void)
{
	Stack myStack;

	Initialize(&myStack);
	PrintStack(&myStack);

	Push(&myStack, GetItem(1));
	PrintStack(&myStack);

	Push(&myStack, GetItem(3));
	PrintStack(&myStack);

	Push(&myStack, GetItem(4));
	PrintStack(&myStack);

	Push(&myStack, GetItem(5));
	PrintStack(&myStack);

	Push(&myStack, GetItem(6));
	PrintStack(&myStack);

	Push(&myStack, GetItem(7));
	PrintStack(&myStack);

	for (int i = 0; i < MAX_STACK_SIZE + 1; ++i)
	{
		printf("Pop: %d\n", Pop(&myStack).key);
		PrintStack(&myStack);
	}

	return 0;
}