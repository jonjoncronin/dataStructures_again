/*
 * bstree.c
 */
#ifdef __cplusplus
extern "C" {
#endif

#include <bstree/bstree.h>
#include <stdlib.h>
#include <stdio.h>

// file private functions - helper functions
static int max(int a, int b)
{
  return (a > b) ? a : b;
}

static int height(bstree_node *someNode)
{
  if(!someNode)
  {
    return 0;
  }
  return someNode->height;
}

static int getBalance(bstree_node *someNode)
{
  if(!someNode)
  {
    return 0;
  }
  return height(someNode->left) - height(someNode->right);
}

static bstree_node* rightRotate(bstree_node *someNode)
{
  //rooted at someNode - right rotate the subtree
  bstree_node *newRoot = someNode->left;
  bstree_node *newRootRight = newRoot->right;

  // rotating
  newRoot->right = someNode;
  someNode->left = newRootRight;

  someNode->height = max(height(someNode->left), height(someNode->right))+1;
  newRoot->height = max(height(newRoot->left), height(newRoot->right))+1;
  return newRoot;
}

static bstree_node* leftRotate(bstree_node *someNode)
{
  //rooted at someNode - left rotate the subtree
  bstree_node *newRoot = someNode->right;
  bstree_node *newRootLeft = newRoot->left;

  // rotating
  newRoot->left = someNode;
  someNode->right = newRootLeft;

  someNode->height = max(height(someNode->left), height(someNode->right))+1;
  newRoot->height = max(height(newRoot->left), height(newRoot->right))+1;
  return newRoot;
}

static bstree_node* bstree_insert(bstree_node *root, int someKey)
{
  bstree_node *newNode = NULL;
  int balance = 0;

  if(root == NULL)
  {
    newNode = malloc(sizeof(bstree_node));
    if(!newNode)
    {
      // We ran out of memory
      return NULL;
    }

    newNode->key = someKey;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
  }

  if(root->key == someKey)
  {
    free(newNode);
    return NULL;
  }

  if(someKey < root->key)
  {
    root->left = bstree_insert(root->left, someKey);
  }
  else if(someKey > root->key)
  {
    root->right = bstree_insert(root->right, someKey);
  }

  // update heights
  root->height = 1 + max(height(root->left), height(root->right));

  // get balance value of the subtree
  balance = getBalance(root);

  // Left Left Rotation needed
  if(balance > 1 && someKey < root->left->key)
  {
    return rightRotate(root);
  }
  // Right Right Rotation needed
  if(balance < -1 && someKey > root->right->key)
  {
    return leftRotate(root);
  }
  // Left Right Rotation needed
  if(balance > 1 && someKey > root->left->key)
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  // Right Left Rotation needed
  if(balance < -1 && someKey < root->right->key)
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  // This return is here to make the compiler happy.
  // We do not expect to hit this return.
  return root;
}

static void bsTree_printInorder(bstree_node *root)
{
  if(!root)
  {
    // we've reached a leaf
    return;
  }
  bsTree_printInorder(root->left);
  printf(" (%d) \n", root->key);
  bsTree_printInorder(root->right);
}

bstree* bstree_createTree()
{
  bstree *newTree = malloc(sizeof(bstree));
  if(!newTree)
  {
    /* we ran out of memory */
    return NULL;
  }

  newTree->root = NULL;
  newTree->count = 0;
  return newTree;
}

int bstree_insertKey(bstree* someTree, int someKey)
{
  int result = 0;

  if(!someTree)
  {
    return 0;
  }

  someTree->root = bstree_insert(someTree->root, someKey);
  if(someTree->root != NULL)
  {
    result = 1;
  }

  if(result)
  {
    someTree->count += 1;
  }

  return result;
}

void bsTree_printTreeInorder(bstree* someTree)
{
  if(!someTree)
  {
    printf("Tree doesn't exist\n");
  }
  else
  {
    bsTree_printInorder(someTree->root);
  }

  return;
}

#ifdef __cplusplus
}
#endif
