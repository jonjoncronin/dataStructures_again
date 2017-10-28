#include <stddef.h>
#include <gtest/gtest.h>
#include <stack/stack.h>

TEST(StackTest, HappyStackCreate) {
  stack *someStack = NULL;
  someStack = stack_createStack();

  ASSERT_EQ(0, someStack->stackSize);
  ASSERT_EQ(0, someStack->top);
  ASSERT_EQ(0, someStack->minStack);
}

TEST(StackTest, HappyStackDestroy) {
  stack *someStack = NULL;
  int data[3] = {0,1,2};

  someStack = stack_createStack();
  for(int i = 0; i<3;i++)
  {
    stack_push(data[i],someStack);
  }
  stack_printStack(someStack);

  stack_destroyStack(someStack);

  ASSERT_EQ(0, someStack->stackSize);
  ASSERT_EQ(0, someStack->top);
  ASSERT_EQ(0, someStack->minStack);
}

TEST(StackTest, HappyStackPush) {
  stack *someStack = NULL;
  int data[3] = {0,1,2};

  someStack = stack_createStack();

  for(int i = 0; i<3;i++)
  {
    ASSERT_EQ(1,stack_push(data[i],someStack));
  }
  stack_printStack(someStack);
}

TEST(StackTest, HappyStackPop) {
  stack *someStack = NULL;
  stack_node *popped = NULL;
  int data[3] = {0,1,2};

  someStack = stack_createStack();

  for(int i = 0; i<3;i++)
  {
    stack_push(data[i],someStack);
  }
  stack_printStack(someStack);

  popped = stack_pop(someStack);
  ASSERT_EQ(2, popped->data);

  popped = stack_pop(someStack);
  ASSERT_EQ(1, popped->data);

  popped = stack_pop(someStack);
  ASSERT_EQ(0, popped->data);

  ASSERT_EQ(0, someStack->stackSize);
  ASSERT_EQ(0, someStack->top);
  ASSERT_EQ(0, someStack->minStack);
}
