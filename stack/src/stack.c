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
  return NULL;
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
  return NULL;
}

int stack_isEmpty(stack *someStack)
{
  return 1;
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

#ifdef __cplusplus
}
#endif
