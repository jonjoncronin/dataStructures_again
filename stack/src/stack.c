/*
 * stack.c
 */
#ifdef __cplusplus
extern "C" {
#endif

#include <stack/stack.h>
#include <stdlib.h>
#include <stdio.h>

stack* stack_createStack()
{
  stack *newStack = malloc(sizeof(stack));
  if(!newStack)
  {
    /* we ran out of memory */
    return NULL;
  }

  newStack->top = NULL;
  newStack->stackSize = 0;
  newStack->minStack = NULL;
  return newStack;
}

void stack_destroyStack(stack *someStack)
{
  if(!someStack)
  {
    return;
  }
  while(someStack->stackSize != 0)
  {
    stack_node *nodeToDelete = stack_pop(someStack);
    free(nodeToDelete);
  }
  free(someStack);
}

stack_node* stack_pop(stack *someStack)
{
  stack_node *popped, *minPopped;

  if(!someStack)
  {
    return NULL;
  }
  popped = someStack->top;
  someStack->top = someStack->top->next;
  someStack->stackSize -= 1;
  minPopped = someStack->minStack;
  someStack->minStack = someStack->minStack->next;
  free(minPopped);

  return popped;
}

int stack_push(int data, stack *someStack)
{
  stack_node *newNode;
  stack_node *newMinNode;
  if(!someStack)
  {
    return 0;
  }

  newNode = malloc(sizeof(stack_node));
  newNode->data = data;
  newNode->next = someStack->top;
  someStack->top = newNode;
  someStack->stackSize += 1;

  newMinNode = malloc(sizeof(stack_node));
  if(!someStack->minStack)
  {
    newMinNode->data = newNode->data;
  }
  else if(someStack->minStack->data >= newNode->data)
  {
    newMinNode->data = newNode->data;
  }
  else
  {
    newMinNode->data = someStack->minStack->data;
  }
  newMinNode->next = someStack->minStack;
  someStack->minStack = newMinNode;

  return 1;
}

stack_node* stack_peek(stack *someStack)
{
  stack_node *peeker;

  if(!someStack)
  {
    return NULL;
  }
  peeker = someStack->top;
  return peeker;
}

int stack_isEmpty(stack *someStack)
{
  if(!someStack)
  {
    return 1;
  }
  if(someStack->stackSize == 0)
  {
    return 1;
  }
  return 0;
}

void stack_printStack(stack *someStack)
{
  stack_node *runner;
  if(!someStack)
  {
    printf("Stack doesn't exist\n");
    return;
  }

  if(!someStack->top)
  {
    printf("Stack is empty\n");
    return;
  }

  runner = someStack->top;
  printf("Stack Contents (size: %d)- \n", someStack->stackSize);
  printf("============================\n");
  while(runner)
  {
    printf(" %d\n",runner->data);
    runner = runner->next;
  }
  return;
}

static void stack_printStackInReverseHelper(stack_node *root)
{
  if(!root)
  {
    return;
  }
  stack_printStackInReverseHelper(root->next);
  printf("%d\n", root->data);
}

void stack_printStackInReverse(stack *someStack)
{
  if(!someStack)
  {
    printf("Stack doesn't exist\n");
    return;
  }
  if(stack_isEmpty(someStack))
  {
    printf("Stack is empty\n");
  }
  printf("Stack Contents Reversed (size: %d)\n", someStack->stackSize);
  printf("==================================\n");
  stack_printStackInReverseHelper(someStack->top);
}

int stack_minValue(stack *someStack)
{
  if(!someStack)
  {
    return -1;
  }
  if(stack_isEmpty(someStack))
  {
    return -1;
  }
  return someStack->minStack->data;
}

#ifdef __cplusplus
}
#endif
