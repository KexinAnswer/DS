#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//typedef int STDataType;

typedef struct Stack
{
	int array[100];
	int top;
}	Stack;

void StackInit(Stack* stack)
{
	stack->top = 0;
}

void StackDestory(Stack* stack)
{
	
}

//ѹջ
//β��

void StackPush(Stack* stack, int val)
{
	assert(stack->top < 100);

	stack->array[stack->top] = val;

	stack->top++;

}

//��ջ
//βɾ

void StackPop(Stack* stack)
{
	stack->top--;
}

int StackTop(Stack* stack)
{
	return stack->array[stack->top];
}

int StackEmpty(Stack* stack)
{
	return stack->top == 0 ? 1 : 0;
}

int StackSize(Stack* stack)
{
	return stack->top;
}

