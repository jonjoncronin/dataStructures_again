#include <stddef.h>
#include <gtest/gtest.h>
#include <stack/stack.h>

TEST(StackTest, HappyStackCreate) {
  stack *someStack = NULL;
  someStack = stack_createStack();

  ASSERT_EQ(0, someStack->stackSize);
  ASSERT_EQ(0, someStack->top);
  ASSERT_EQ(0, someStack->minStack);
  stack_destroyStack(someStack);
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
  stack_destroyStack(someStack);
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

  stack_destroyStack(someStack);
}

TEST(StackTest, HappyStackPeek) {
  stack *someStack = NULL;
  stack_node *peeked = NULL;
  int data[3] = {0,1,2};

  someStack = stack_createStack();

  for(int i = 0; i<3;i++)
  {
    stack_push(data[i],someStack);
  }
  stack_printStack(someStack);
  peeked = stack_peek(someStack);
  ASSERT_EQ(2, peeked->data);

  stack_destroyStack(someStack);
}

TEST(StackTest, HappyStackIsEmpty) {
  stack *someStack = NULL;
  int data[3] = {0,1,2};

  someStack = stack_createStack();
  ASSERT_EQ(1, stack_isEmpty(someStack));

  for(int i = 0; i<3;i++)
  {
    stack_push(data[i],someStack);
  }
  stack_printStack(someStack);

  ASSERT_EQ(0, stack_isEmpty(someStack));
  stack_destroyStack(someStack);
}

TEST(StackTest, HappyStackMinValue) {
  stack *someStack = NULL;
  int minValue;
  int data[5] = {0,1,2,3,4};

  someStack = stack_createStack();
  ASSERT_EQ(1, stack_isEmpty(someStack));

  for(int i = 0; i<5;i++)
  {
    stack_push(data[i],someStack);
  }
  stack_printStack(someStack);

  minValue = stack_minValue(someStack);
  ASSERT_EQ(0,minValue);

  stack_destroyStack(someStack);
}

TEST(StackTest, HappyStackPrintReversed) {
  stack *someStack = NULL;
  int minValue;
  int data[5] = {0,1,2,3,4};

  someStack = stack_createStack();

  for(int i = 0; i<5;i++)
  {
    stack_push(data[i],someStack);
  }
  stack_printStack(someStack);

  stack_printStackInReverse(someStack);

  stack_destroyStack(someStack);
}

TEST(StackTest, HappyStackSorted) {
  stack *someStack = NULL;
  stack *sortedStack = NULL;
  int minValue;
  int data[5] = {0,1,2,3,4};

  someStack = stack_createStack();

  for(int i = 0; i<5;i++)
  {
    stack_push(data[i],someStack);
  }
  stack_printStack(someStack);
  sortedStack = stack_sortStack(someStack);
  stack_printStack(sortedStack);
}
