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
  int values[7] = {4,2,6,1,3,5,7};
  int result = 0;

  for(int i = 0; i < 7; i++)
  {
    result = bstree_insertKey(someTree, values[i]);
    ASSERT_EQ(1, result);
  }
  ASSERT_EQ(7, someTree->count);

  bsTree_printTreeInorder(someTree);

}
