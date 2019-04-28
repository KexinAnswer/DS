#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int QUDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QUDataType val;
}	QueueNoode;

typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
	int size;
}	Queue;

void QueueInit(Queue* queue)
{
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}

void QueueDestory(Queue* queue)
{
	assert(queue != NULL);

	QueueNode* cur = queue->front;
	QueueNode* next;

	while (cur != NULL)
	{
		next = cur->next;
		free(cur);

		cur = next;
	}

	queue->front = queue->rear = NULL;
	queue->size = 0;
}

QueueNode * BuyQueueNode(QUDataType val)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));

	assert(node);

	node->val = val;
	node->next = NULL;

}

void QueuePush(Queue* queue, QUDataType val)
{
	assert(queue != NULL);
	
	QueueNode* node = BuyQueueNode(val);
	if (queue->size == 0)
	{
		queue->front = node;
		queue->rear = node;
	}
	else
	{
		queue->rear->next = node;
		queue->rear = node;

	}
	queue->size++;
}

