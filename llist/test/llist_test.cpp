#include <stddef.h>
#include <gtest/gtest.h>
#include <llist/llist.h>


TEST(LinkedListTest, HappyAdd) {
  llist_node *someList;
  llist_node headNode = {0};
  llist_node newNode = {0};

  headNode.data = 0;
  headNode.next = NULL;
  someList = &headNode;

  newNode.data = 1;
  newNode.next = NULL;

  ASSERT_EQ(1, llist_addToHead(&newNode, &someList));
  ASSERT_EQ(&newNode, someList);

  llist_printList(someList);
}

TEST(LinkedListTest, AddNullNode) {
  ASSERT_EQ(0,0);
}

TEST(LinkedListTest, AddNodeToNullList) {
  ASSERT_EQ(0,0);
}

TEST(LinkedListTest, AddToTail) {
  ASSERT_EQ(0,0);
}

TEST(LinkedListTest, HappyGetLength) {
  llist_node *someList;
  llist_node headNode = {0};
  llist_node newNode = {0};

  headNode.data = 0;
  headNode.next = NULL;
  someList = &headNode;

  newNode.data = 1;
  newNode.next = NULL;

  ASSERT_EQ(1, llist_addToHead(&newNode, &someList));
  ASSERT_EQ(&newNode, someList);
  ASSERT_EQ(2, llist_getLength(someList));
  llist_printList(someList);
}

TEST(LinkedListTest, GetLengthNullList) {
  ASSERT_EQ(0,0);
}

TEST(LinkedListTest, RemoveAll) {
  ASSERT_EQ(0,0);
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
