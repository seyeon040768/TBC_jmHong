#include "stack.h"

void Initialize(Stack* stack)
{
	stack->top = -1;
}

bool IsFull(const Stack* stack)
{
	return stack->top + 1 >= MAX_STACK_SIZE;
}

bool IsEmpty(const Stack* stack)
{
	return stack->top == -1;
}

void Push(Stack* stack, Item item)
{
	if (IsFull(stack))
	{
		printf("Stack is full. Cannot add.\n");
		return;
	}

	++(stack->top);
	stack->items[stack->top] = item;
}

Item Pop(Stack* stack)
{
	if (IsEmpty(stack))
	{
		printf("Stack is empty. Cannot remove.\n");
		return (Item) { .i = -1, .j = -1 };
	}

	return stack->items[(stack->top)--];
}