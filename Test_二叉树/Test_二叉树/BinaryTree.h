#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Node
{
	struct Node *left;
	struct Node *right;
	int val;
}	Node;

void preorder(Node * root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%d->", root->val);
	preorder(root->left);
	preorder(root->right);

}

void inorder(Node * root)
{
	if (root == NULL)
	{
		return 0;
	}

	inorder(root->left);
	printf("%d->", root->val);
	inorder(root->right);

}

void postorder(Node * root)
{
	if (root == NULL)
	{
		return;
	}

	preorder(root->left);
	preorder(root->right);
	printf("%d->", root->val);

}

struct Node * buyNode(int val)
{
	struct Node* node = (struct Node*) malloc(sizeof(Node));
	assert(node != NULL);
	
	node->val = val;

	node->right = node->left = NULL;

	return node;

}

void Test() {
		Node *a = buyNode(1);
	Node *b = buyNode(2);
	Node *c = buyNode(3);
	Node *d = buyNode(4);
	Node *e = buyNode(5);
	Node *f = buyNode(6);
	Node *g = buyNode(7);

	a->left = b;
	a->right = c;
	c->left = d;
	c->right = f;
	d->right = e;
	f->right = g;

	preorder(a);	printf("\n");
	inorder(a);	printf("\n");
	postorder(a);	printf("\n");
}