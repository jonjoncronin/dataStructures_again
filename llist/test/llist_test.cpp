#include <stddef.h>
#include <gtest/gtest.h>
#include <llist/llist.h>


TEST(LinkedListTest, HappyAddToHeadEmpty) {
  llist_node *someList = {0};
  int data = 1;

  ASSERT_EQ(1, llist_addToHead(data, &someList));
  llist_printList(someList);
}

TEST(LinkedListTest, HappyAddToTailEmpty) {
  llist_node *someList = {0};
  int data = 1;
  ASSERT_EQ(1, llist_addToTail(data, &someList));
  llist_printList(someList);
}

TEST(LinkedListTest, AddNodeToNullList) {
  ASSERT_EQ(-1, llist_addToHead(1, NULL));
  ASSERT_EQ(-1, llist_addToTail(1, NULL));
}

TEST(LinkedListTest, HappyGetLength) {
  llist_node *someList = {0};
  int data = 1;

  ASSERT_EQ(1, llist_addToHead(data, &someList));
  ASSERT_EQ(1, llist_addToHead(data, &someList));
  ASSERT_EQ(2, llist_getLength(someList));
  llist_printList(someList);
}

TEST(LinkedListTest, GetLengthNullList) {
  ASSERT_EQ(0, llist_getLength(NULL));
}

TEST(LinkedListTest, RemoveHead) {
  llist_node *someList = {0};
  int dataList[5] = {0,1,2,3,4};
  for (int i = 0; i<5;i++)
  {
    llist_addToHead(dataList[i],&someList);
  }
  llist_printList(someList);
  ASSERT_EQ(1, llist_removeHead(&someList));
  llist_printList(someList);
}

TEST(LinkedListTest, RemoveTail) {
  llist_node *someList = {0};
  int dataList[5] = {0,1,2,3,4};
  for (int i = 0; i<5;i++)
  {
    llist_addToHead(dataList[i],&someList);
  }
  llist_printList(someList);
  ASSERT_EQ(1, llist_removeTail(&someList));
  llist_printList(someList);
}

TEST(LinkedListTest, RemoveAll) {
  llist_node *someList = {0};
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
  llist_node *someList = {0};
  int dataList[3] = {1,2,3};
  for (int i = 0; i<3;i++)
  {
    llist_addToHead(dataList[i],&someList);
  }
  llist_printList(someList);
  someList = llist_reverse(someList);
  llist_printList(someList);
}

TEST(LinkedListTest, HappyCycleCheck) {
  llist_node *someList = {0};
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
  llist_node *someList = {0};
  int dataList[10] = {0,0,1,2,3,4,4,5,6,6};
  for (int i = 0; i<10;i++)
  {
    llist_addToHead(dataList[i],&someList);
  }
  llist_printList(someList);
  llist_removeDuplicates(someList);
  llist_printList(someList);
}

TEST(LinkedListTest, GetNodeAtIndex) {
  llist_node *someList = {0};
  llist_node *someNode;
  int dataList[5] = {0,1,2,3,4};
  for (int i = 0; i<5;i++)
  {
    llist_addToHead(dataList[i],&someList);
  }
  llist_printList(someList);

  someNode = llist_getNode(someList, 2);
  ASSERT_EQ(2, someNode->data);

  someNode = llist_getNode(someList, 0);
  ASSERT_EQ(4, someNode->data);

  someNode = llist_getNode(someList, 4);
  ASSERT_EQ(0, someNode->data);

  someNode = llist_getNode(someList, 5);
  ASSERT_EQ(0, someNode->data);
}
