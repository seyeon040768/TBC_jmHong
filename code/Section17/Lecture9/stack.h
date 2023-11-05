#pragma once

#include "element.h"
#include <stdbool.h>

#define MAX_STACK_SIZE 5

typedef struct Stack
{
	Element items[MAX_STACK_SIZE];
	int top;
} Stack;

void Initialize(Stack* stack);
bool IsFull(const Stack* stack);
bool IsEmpty(const Stack* stack);
void Push(Stack* stack, Element item);
Element Pop(Stack* stack);