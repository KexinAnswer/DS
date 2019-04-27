#pragma once

#include<stdio.h>
#include <stdlib.h>
#include <assert.h>

/// Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l2;
	}

	struct ListNode* newHead = l2;

	if (l1->val < l2->val)
		newHead = l1;
	newHead->next = NULL;
	struct ListNode* node = newHead;
	struct ListNode* cur1 = l1;
	struct ListNode* cur2 = l2;
	struct ListNode* next1;
	struct ListNode* next2;

	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->val < cur2->val)
		{
			next1 = cur1->next;
			if (cur1 != newHead)
			{
				while (node->next != NULL)
				{
					node = node->next;
				}
				node->next = cur1;
				cur1->next = NULL;
				cur1 = next1;
			}
		}
		else
		{
			next2 = cur2->next;
			if (cur2 != newHead)
			{
				while (node->next != NULL)
				{
					node = node->next;
				}
				node->next = cur2;
				cur2->next = NULL;
				cur2 = next2;
			}
		}
	}

	if (cur1 == NULL && cur2 != NULL)
	{
		node->next = cur2;
	}

	if (cur2 == NULL && cur1 != NULL)
	{
		node->next = cur1;
	}

	return newHead;

}