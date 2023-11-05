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

void Push(Stack* stack, Element item)
{

}

Element Pop(Stack* stack)
{

}