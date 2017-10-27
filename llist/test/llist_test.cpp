#include <stddef.h>
#include <gtest/gtest.h>
#include <llist/llist.h>


TEST(LinkedListTest, HappyAdd) {
  llist_node *someList;
  llist_node headNode = {0};

  headNode.data = 0;
  headNode.next = NULL;
  someList = &headNode;


  ASSERT_EQ(1, llist_addToHead(1, &someList));
  ASSERT_NE(&headNode, someList);
  llist_printList(someList);
}

TEST(LinkedListTest, AddToTail) {
  llist_node *someList;
  llist_node headNode = {0};

  headNode.data = 0;
  headNode.next = NULL;
  someList = &headNode;

  ASSERT_EQ(1, llist_addToTail(1, &someList));
  ASSERT_EQ(&headNode, someList);
  llist_printList(someList);
}

TEST(LinkedListTest, AddToHeadEmptyList) {
  llist_node *someList = NULL;

  ASSERT_EQ(0, someList);
  ASSERT_EQ(1, llist_addToHead(1, &someList));
  llist_printList(someList);
}

TEST(LinkedListTest, AddToTailEmptyList) {
  llist_node *someList = NULL;

  ASSERT_EQ(0, someList);
  ASSERT_EQ(1, llist_addToTail(1, &someList));
  // llist_printList(someList);
}

TEST(LinkedListTest, AddNodeToNullList) {
  ASSERT_EQ(-1, llist_addToHead(1, NULL));
  ASSERT_EQ(-1, llist_addToTail(1, NULL));
}

TEST(LinkedListTest, HappyGetLength) {
  llist_node *someList;
  llist_node headNode = {0};

  headNode.data = 0;
  headNode.next = NULL;
  someList = &headNode;

  ASSERT_EQ(1, llist_addToHead(1, &someList));
  ASSERT_EQ(2, llist_getLength(someList));
  llist_printList(someList);
}

TEST(LinkedListTest, GetLengthNullList) {
  ASSERT_EQ(0, llist_getLength(NULL));
}

TEST(LinkedListTest, RemoveAll) {
  llist_node *someList;
  llist_node headNode = {0};
  int dataList[5] = {0,1,2,3,4};
  for (int i = 0; i<5;i++)
  {
    llist_addToHead(dataList[i],&someList);
  }
  llist_printList(someList);
  ASSERT_EQ(1, llist_removeAll(&someList));
  llist_printList(someList);
}

TEST(LinkedListTest, HappyListReverse) {
  ASSERT_EQ(0,0);
}

TEST(LinkedListTest, HappyCycleCheck) {
  ASSERT_EQ(0,0);
}

TEST(LinkedListTest, RemoveDups) {
  ASSERT_EQ(0,0);
}
