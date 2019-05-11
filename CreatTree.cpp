#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <queue>
#include <stack>


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

//求第k层节点个数
int LevelK(TreeNode * root, int k)
{
  if(root == NULL)
  {
    return 0;
  }

  if(k == 1)
  {
    return 1;
  }

  return LevelK(root->left,k-1) + LevelK(root->right,k-1);
}


TreeNode * Find(TreeNode * root , int val)
{
  if(root == NULL)
  {
    return NULL;
  }

  if(root->val == val)
  {
    return root;
  }

  TreeNode* result = Find(root->left, val);
  //在左子树中找到了
  if(result != NULL)
  {
    return result;
  }

  //左子树中没有找到
  result = Find(root->right , val);
  if(result != NULL)
  {
    //在右子树中找到了
    return result;
  }
  else
  {
    return NULL;
  }
}

void LevelOrderTravalsal(TreeNode * root)
{
  if(root == NULL)
  {
    return;
  }
  
  //创建打印队列
  std::queue<TreeNode *> qu;

  //获取根节点
  qu.push(root);
  //如果队列不为空，一直打印到队列为空
  while(!qu.empty())
  {
    //获取队首元素
    TreeNode* front = qu.front();
    qu.pop();

    //打印队首元素
    printf("%c",front->val);

    //如果队首元素有左子树，则将左子树压入队列中
    if(front->left != NULL)
    {
      qu.push(front->left);
    }

    //如果队首元素有右子树，则将右子树压入队列中
    if(front->right != NULL)
    {
      qu.push(front->right);
    }
  }
  
}

bool IsComplateBinaryTree(TreeNode * root)
{
  //如果是空树直接返回真
  if(root == NULL)
  {
    return true;
  }

  //创建队列 将二叉树压入队列中
  std::queue<TreeNode *> qu;
  qu.push(root);

  while(1)
  {
    TreeNode* front = qu.front();
    qu.pop();

    //二叉树中子树为空 循环停止
    if(front == NULL)
    {
      break;
    }

    qu.push(front->left);
    qu.push(front->right);
  }

  //查看队列中剩余字数，如果剩余子树中不都是空节点 那就不是完全二叉树
  while(!qu.empty())
  {
    TreeNode* front = qu.front();
    qu.pop();

    if(front != NULL)
    {
      return false;
    }
  }
  //队列剩余节点都是空节点，二叉树为完全二叉树
  return true;
}

void PerorderTraversalNor(TreeNode * root)
{
  TreeNode* cur = root;
  TreeNode* top;
  TreeNode* last = NULL;


  //创建栈，存放二叉树节点
  std::stack<TreeNode*> st;

  //当栈不为空或者cur部位空时，循环不结束
  while(!st.empty() || cur != NULL)
  {
    //当cur部位NULL时，打印左子树并向左子树延申，并且压入栈
    while(cur != NULL)
    {
      printf("%c ", cur->val);
      st.push(cur);
      cur = cur->left;
    }
    
    // 记录栈顶元素
    top = st.top();

    if(top->right == NULL)
    {
      cur = top->right;
      st.pop();
      last = top;
    }
    else{
      if(top->right != last)
      {
        cur = top->right;
      }
      else{
        st.pop();
        last = top;
      }
    }

  }
}

void ProrderTraversalNor2(TreeNode * root)
{
  if(root == NULL)
  {
    return;
  }
  
  //遍历节点的指针
  TreeNode* cur = root;
  //记录栈顶元素的指针
  TreeNode* top;
  std::stack<TreeNode*> st;

  while(!st.empty() || cur != NULL)
  {

    //优先遍历二叉树的左子树
    while(cur != NULL)
    {
      printf("%c ", cur->val);
      st.push(cur);
      cur = cur->left;
    }

    //当左子树打印完毕，向上寻找上一个节点的右子树进行遍历
    top = st.top();
    st.pop();
    cur = top->right;
  }
}

void InorderTraversalNor(TreeNode * root)
{
  if(root == NULL){
    return;
  }

  TreeNode* cur = root;
  TreeNode* top;
  TreeNode* last = NULL;

  std::stack<TreeNode*> st;

  while(!st.empty() || cur != NULL)
  {
    while(cur != NULL)
    {
      st.push(cur);
      cur = cur->left;
    }
    top = st.top();

    if(top->right == NULL)
    {
      printf("%c ",top->val);
      cur = top->right;
      st.pop();
      last = top;
    }
    else
    {
      if(top->right != last)
      {

        printf("%c ", top->val);
        cur = top->right;

      }
      else
      {
        st.pop();
        last = top;
      }
    }
  }
}


void InorderTraversalNor2(TreeNode * root)
{
  //遍历二叉树的指针
  TreeNode* cur = root;
  //记录栈顶元素的指针
  TreeNode* top;

  std::stack<TreeNode*> st;

  while(!st.empty() || cur != NULL)
  {
    
    while(cur != NULL)
    {
      st.push(cur);
      cur = cur->left;
    }
    top = st.top();
    printf("%c ", top->val);
    cur = top->right;
    st.pop();

  }
}


void PosterorderTraversalNor(TreeNode * root)
{
  if(root == NULL)
  {
    return;
  }

  TreeNode* cur = root;
  TreeNode* top;
  TreeNode* last = NULL;

  std::stack<TreeNode*> st;

  while(!st.empty() || cur != NULL)
  {
    while(cur != NULL)
    {
      st.push(cur);
      cur = cur->left;

    }
     top = st.top();

     if(top->right == NULL)
     {
       printf("%c ", top->val);
       cur = top->right;
       st.pop();
       last = top;
     }
     else
     {
       if(top != last)
       {
         cur = top->right;
       }
       else
       {
         printf("%c ",top->val);
         st.pop();
         last = top;
       }
     }
  }
}




