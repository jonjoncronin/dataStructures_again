/*
 * bstree.h
 */

#ifndef INCLUDE_BSTREE_H_
#define INCLUDE_BSTREE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _bstree_node
{
  int key;
  struct _bstree_node *left;
  struct _bstree_node *right;
} bstree_node;

typedef struct _bstree
{
  bstree_node *root;
  int count;
} bstree;

extern bstree* bstree_createTree();
extern int bstree_insertKey(bstree* someTree, int someKey);
extern void bsTree_printTreeInorder(bstree* someTree);

#ifdef __cplusplus
}
#endif
#endif /* INCLUDE_BSTREE_H_ */
