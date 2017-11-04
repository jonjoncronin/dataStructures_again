/*
 * bstree.c
 */
#ifdef __cplusplus
extern "C" {
#endif

#include <bstree/bstree.h>
#include <stdlib.h>
#include <stdio.h>

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

static bstree_node* bstree_insert(bstree_node *root, int someKey)
{
  bstree_node *newNode = NULL;

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

  // This return is here to make the compiler happy.
  // We do not expect to hit this return.
  return root;
}

int bstree_insertKey(bstree* someTree, int someKey)
{
  int result = 0;

  if(!someTree)
  {
    return 0;
  }

  if(!someTree->root)
  {
    someTree->root = bstree_insert(someTree->root, someKey);
    if(someTree->root != NULL)
    {
      result = 1;
    }
  }
  else
  {
    result = (bstree_insert(someTree->root, someKey) != NULL) ? 1 : 0;
  }

  if(result)
  {
    someTree->count += 1;
  }

  return result;
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
