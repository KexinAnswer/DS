#include <stdio.h>
#include <malloc.h>

typedef struct TreeNode{
  struct TreeNode *left;
  struct TreeNode *right;
  char val;
} TreeNode;


typedef struct Result{
  TreeNode *root;
  int used;
} Result;

Result CreatTree(char preorder[], int size)
{
  if(size == 0)
  {
    Result result;
    result.root = NULL;
    result.used = 0;
    return result;
  }
  
  char rootVal = preorder[0];
  if(rootVal== '#')
  {
    Result result;
    result.root = NULL;
    result.used = 1;

    return result;
  }
  
  TreeNode *node = (TreeNode*) malloc (sizeof(TreeNode));
  node->val = rootVal;
  node->left = node->right = NULL;

  Result left_result = CreatTree(preorder + 1 , size - 1);
  Result right_result = CreatTree(preorder + 1 + left_result.used , size - 1 - left_result.used);
  
  node->left = left_result.root;
  node->right = right_result.root;

  Result result;
  result.root = node;
  result.used = 1 + left_result.used + right_result.used;

  return result;

}

//求二叉树节点
void TreeSize1(TreeNode * root, int *size)
{
  if(root == NULL)
  {
    return;
  }
  
  (*size)++;
  TreeSize1(root->left, size);
  TreeSize1(root->right,size);
}

//递推的思想
int TreeSize2(TreeNode * root)
{
  if(root == NULL)
  {
    return 0;
  }
  return 1 + TreeSize2(root->left) + TreeSize2(root->right);  
}

//叶子节点个数
//遍历的思想

void LeafSize1(TreeNode *root, int *size)
{
  if(root == NULL)
  {
    return;
  }

  if(root->left == NULL && root->right == NULL)
  {
    (*size)++;
  }
}

//递推的思想

int LeafSize2(TreeNode *root)
{
  if(root == NULL)
  {
    return 0;
  }

  if(root->left == NULL && root->right == NULL)
  {
    return 1;
  }

  return LeafSize2(root->left) + LeafSize2(root->right);
}

























