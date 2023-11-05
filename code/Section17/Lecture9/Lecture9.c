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

Element GetElement(const int key)
{
	Element newElement;
	newElement.key = key;
	return newElement;
}

int main(void)
{
	Stack myStack;

	Initialize(&myStack);
	PrintStack(&myStack);

	Push(&myStack, GetElement(1));
	PrintStack(&myStack);

	Push(&myStack, GetElement(3));
	PrintStack(&myStack);

	Push(&myStack, GetElement(4));
	PrintStack(&myStack);

	Push(&myStack, GetElement(5));
	PrintStack(&myStack);

	Push(&myStack, GetElement(6));
	PrintStack(&myStack);

	Push(&myStack, GetElement(7));
	PrintStack(&myStack);

	for (int i = 0; i < MAX_STACK_SIZE + 1; ++i)
	{
		printf("Pop: %d\n", Pop(&myStack).key);
		PrintStack(&myStack);
	}

	return 0;
}