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
  llist_node *someList = 0;
  llist_node node1, node2, node3;
  node1.data = 1;
  node1.next = 0;
  node2.data = 2;
  node2.next = 0;
  node3.data = 3;
  node3.next = 0;

  ASSERT_EQ(0, llist_containsCycle(someList));

  someList = &node1;
  ASSERT_EQ(0, llist_containsCycle(someList));

  node1.next = &node2;
  ASSERT_EQ(0, llist_containsCycle(someList));

  node2.next = &node1;
  ASSERT_EQ(1, llist_containsCycle(someList));

  node2.next = &node3;
  node3.next = &node2;
  ASSERT_EQ(1, llist_containsCycle(someList));
}

TEST(LinkedListTest, RemoveDups) {
  ASSERT_EQ(0,0);
}
