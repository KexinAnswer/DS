#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;

typedef struct SListNode
{
	SLDataType val;
	struct SListNode* next;
}	SListNode;

typedef struct SList
{
	SListNode* head;
}	SList;

void SListInit(SList* list)
{
	assert(list != NULL);

	list->head = NULL;
}

void SListDestory(SList* list)
{
	assert(list != NULL);

	SListNode* cur = list->head;
	SListNode* next = NULL;
	while (cur != NULL)
	{
		if (cur->next != NULL)
		{
			next = cur->next;
		}

		free(cur);
		cur->val = 0;
		cur = NULL;

		cur = next;
	}
}

SListNode* BuySListNode(SLDataType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	assert(node);
	node->val = x;
	return node;
}

void SListPushFront(SList* list, SLDataType x)
{
	assert(list != NULL);

	SListNode* node = BuySListNode(x);

	assert(node);

	node->next = list->head;
	list->head = node;

}

void SListPopFront(SList* list)
{
	assert(list != NULL);

	if (list->head->next == NULL)
	{
		list->head = NULL;
		return;
	}

	SListNode* node = list->head;
	list->head = list->head->next;

	free(node);
	node->val = 0;
	node = NULL;

}

void SListPushBack(SList* list, SLDataType val)
{
	assert(list != NULL);

	if (list->head == NULL)
	{
		SListPushFront(list, val);
		return;
	}

	SListNode* cur = list->head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	SListNode* node = BuySListNode(val);
	cur->next = node;
	node->next = NULL;
}

void SListPopBack(SList* list)
{
	assert(list != NULL);

	if (list->head->next == NULL)
	{
		free(list->head);
		list->head = NULL;
	}

	SListNode* cur = list->head;

	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}

	SListNode* node = cur->next;
	free(node);
	node = NULL;
	cur->next = NULL;
}

SListNode* SListFind(SList* list, SLDataType x)
{
	assert(list != NULL);

	SListNode* cur = list->head;

	while (cur != NULL)
	{
		if (cur->val == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	//没找到
	return NULL;
}


void SListInsertAfter(SListNode* pos, SLDataType x)
{
	SListNode* node = BuySListNode(x);

	node->next = pos->next;
	pos->next = node;

}

void SListEraseAfter(SListNode* pos)
{
	SListNode* node = pos->next;
	pos->next = pos->next->next;

	free(node);
	node = NULL;
}

void SListInsertBefore(SList* list, SListNode* pos, SLDataType x)
{
	assert(list != NULL);

	SListNode* cur = list->head;
	while (cur->next != pos)
	{
		cur = cur->next;
	}

	SListNode* node = BuySListNode(x);

	cur->next = node;
	node->next = pos;
}

void SListNodeUpdata(SListNode* node, SLDataType val)
{
	node->val = val;
}

void SListPrint(SList* list)
{
	assert(list != NULL);

	SListNode* cur = list->head;
	for (cur = list->head; cur != NULL; cur = cur->next)
	{
		printf("%d-> ", cur->val);
	}

	printf("\n");
}

void TestSList1() {
	SList list;
	SListInit(&list);
	assert(list.head == NULL);

	SListPushBack(&list, 11);
	SListPushBack(&list, 12);
	SListPushBack(&list, 13);
	SListPrint(&list);
	SListNode *n12 = SListFind(&list, 12);
	assert(n12 != NULL);

	SListPrint(&list);
	// 11 12 13

	SListInsertAfter(n12, 103);


	SListPrint(&list);
	// 11 12 103 13

	SListEraseAfter(n12);

	SListPrint(&list);
	// 11 12 13

	SListInsertBefore(&list, n12, 101);

	SListPrint(&list);
	// 11 101 12 13

	printf("大成功\n");
}