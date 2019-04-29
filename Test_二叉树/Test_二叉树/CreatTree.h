#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <queue>
#include <iostream>

typedef struct TreeNode
{
	struct TreeNode* left;			//�������ڵ�
	struct TreeNode* right;			//�������ڵ�
	char val;						//�ڵ��е�ֵ
}	TreeNode;

typedef struct Result
{	
	TreeNode* root;					//�������ĸ��ڵ�
	int used;						//�������д��� val �ĸ���
}	Result;


Result CreatTree(char preorder[], int size)
{	//������� size == 0
	if (size == 0)
	{
		Result result;
		result.root = NULL;
		result.used = 0;
		return result;
	}

	//�������
	char rootVal = preorder[0];
	if (rootVal == '#')
	{
		Result result;
		result.root = NULL;
		result.used = 1;
		return result;
	}

	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = rootVal;
	root->left = root->right = NULL;

	//������
	Result left_result = CreatTree(preorder + 1, size - 1);
	//������
	Result right_result = CreatTree(preorder + 1 + left_result.used, size - 1 - left_result.used);

	root->left = left_result.root;
	root->right = right_result.root;

	Result result;
	result.root = root;
	result.used = 1 + left_result.used + right_result.used;

	return result;

}

void InorderTraversal(TreeNode * root)
{
	if (root == NULL)
	{
		return;
	}

	InorderTraversal(root->left);
	printf("%c ", root->val);
	InorderTraversal(root->right);

}

//��������ڵ����
//������˼��
void TreeSize(TreeNode *root, int *size)
{
	if (root == NULL)
	{
		return;
	}

	(*size)++;
	TreeSize(root->left,size);
	TreeSize(root->right, size);
}
//���Ƶ�˼��
int TreeSize2(TreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + TreeSize2(root->left) + TreeSize2(root->right);
}

//Ҷ�ӽڵ�ĸ���
//������˼��

void LeafSize(TreeNode* root, int *leaf_size)
{
	if (root == NULL)
	{
		return;
	}

	if (root->left == NULL && root->right == NULL)
	{
		(*leaf_size)++;		
	}

	LeafSize(root->left,leaf_size);
	LeafSize(root->right,leaf_size);
}
//���Ƶ�˼��

int LeafSize2(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return LeafSize2(root->left) + LeafSize2(root->right);
}

int Levelk(TreeNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}


	return LevelK(root->left, k - 1) + LevelK(root->right, k - 1);
}

TreeNode * Find(TreeNode * root, int x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->val == x)
	{
		return root;
	}

	TreeNode *result = Find(root->left, x);
	//�ҵ���
	if (result != NULL)
	{
		return result;
	}

	//������û���ҵ�

	result = Find(root->right , x);
	if (result != NULL)
	{
		//�ҵ���
		return result;
	}
	else
	{
		//û�ҵ�
		return NULL;
	}
}

void LevelorderTravelsal(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	std::queue<TreeNode *> qu;
	
	qu.push(root);
	while (!qu.empty())
	{
		TreeNode *front = qu.front();
		qu.pop();

		printf("%c ", front->val);

		if (front->left != NULL)
		{
			qu.push(front->left);
		}

		if (front->right != NULL)
		{
			qu.push(front->right);
		}
	}
}

bool IsComplateBinaryTree(TreeNode * root)
{
	if (root == NULL)
	{
		return NULL;
	}

	std::queue<TreeNode *> qu;
	qu.push(root);

	while (1)
	{
		TreeNode * front = qu.front();
		qu.pop();

		//����NULL�ڵ�
		if (front == NULL)
		{
			break;
		}
		qu.push(front->left);
		qu.push(front->right);
	}

	while (!qu.empty())
	{
		TreeNode * front = qu.front();

		qu.pop();
		if (front == NULL)
		{
			return false;
		}
	}

	return true;
}