#include <bstree/bstree.h>
#include <stddef.h>
#include <gtest/gtest.h>

TEST(BsTreeTest, HappyTreeCreate) {
  bstree *someTree = bstree_createTree();

  int val = (someTree != NULL) ? 1 : 0;
  ASSERT_NE(0, val);
  ASSERT_EQ(0, someTree->root);
  ASSERT_EQ(0, someTree->count);
}

TEST(BsTreeTest, HappyTreeInsert) {
  bstree *someTree = bstree_createTree();
  int values[1] = {10};
  int result = 0;
  int val;

  result = bstree_insertKey(someTree, values[0]);
  val = (someTree->root != NULL) ? 1 : 0;

  ASSERT_EQ(1, result);
  ASSERT_EQ(1, someTree->count);
  ASSERT_NE(0, val);
}

TEST(BsTreeTest, HappyTreePrintInorder) {
  bstree *someTree = bstree_createTree();
  bstree *otherTree = bstree_createTree();
  int someValues[7] = {4,2,6,1,3,5,7};
  int otherValues[7] = {7,6,5,4,3,2,1};
  int result = 0;

  for(int i = 0; i < 7; i++)
  {
    result = bstree_insertKey(someTree, someValues[i]);
    ASSERT_EQ(1, result);
    result = bstree_insertKey(otherTree, otherValues[i]);
    ASSERT_EQ(1, result);
  }
  ASSERT_EQ(7, someTree->count);
  ASSERT_EQ(7, otherTree->count);

  printf("some tree\n");
  bsTree_printTree(someTree, 4);
  printf("other tree\n");
  bsTree_printTree(otherTree, 4);

}

TEST(BsTreeTest, HappyTreeFind) {
  bstree *someTree = bstree_createTree();
  bstree_node *found = NULL;
  int someValues[7] = {4,2,6,1,3,5,7};
  int result = 0;
  int val = 0;

  for(int i = 0; i < 7; i++)
  {
    result = bstree_insertKey(someTree, someValues[i]);
    ASSERT_EQ(1, result);
  }
  found = bsTree_findKey(someTree, 4);
  ASSERT_EQ(4, found->key);

  found = bsTree_findKey(someTree, 7);
  ASSERT_EQ(7, found->key);

  found = bsTree_findKey(someTree, 10);
  val = (found != NULL) ? 1 : 0;
  ASSERT_EQ(0, val);
}
