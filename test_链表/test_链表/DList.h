#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int DLDataType;

typedef struct DListNode
{
	DLDataType val;
	struct DListNode* next;
	struct DListNode* prev;
}	DListNode;

typedef struct DList
{
	DListNode* head;
}	DList;

DListNode* BuyDListNode(DLDataType val)
{
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));

	node->val;
	node->next = NULL;
	node->prev = NULL;

	return node;

}

void DListInit(DList* dlist)
{
	assert(dlist != NULL);

	dlist->head = BuyDListNode(0);

	dlist->head->next = dlist->head;
	dlist->head->prev = dlist->head;
}

void DListClear(DList* dlist)
{
	DListNode *cur, *next;
	cur = dlist->head->next;

	while (cur != dlist->head)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}

	dlist->head->next = dlist->head->prev = dlist->head;
}

void DListDestory(DList* dlist)
{
	DListClear(dlist);
	free(dlist->head);
	dlist->head = NULL;

}

void DListPushBack(DList* list, DLDataType x)
{
	assert(list != NULL);

	DListNode* node = BuyDListNode(x);
	node->next = list->head;
	node->prev = list->head->prev;
	list->head->prev->next = node;
	list->head->prev = node;

}

void DListPopBack(DList* list)
{
	assert(list != NULL);

	DListNode* node = list->head->prev;

	node->prev->next = list->head;
	list->head->prev = node->prev;
	
	free(node);
	node = NULL;
}

void DListPushFront(DList* list, DLDataType x)
{
	assert(list != NULL);

	DListPushBack(list, x);

	list->head = list->head->prev;

	
}