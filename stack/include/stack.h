/*
 * stack.h
 */

#ifndef INCLUDE_STACK_H_
#define INCLUDE_STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _stack_node {
  int data;
  struct _stack_node *next;
} stack_node;

typedef struct _stack {
  stack_node *top;
  int stackSize;
  stack_node *minStack;
} stack;

extern stack* stack_createStack();
extern void stack_destroyStack(stack *someStack);
extern stack_node* stack_pop(stack *someStack);
extern int stack_push(int data, stack *someStack);
extern stack_node* stack_peek(stack *someStack);
extern int stack_isEmpty(stack *someStack);

extern void stack_printStack(stack *someStack);
extern void stack_printStackInReverse(stack *someStack);

extern int stack_minValue(stack *someStack);

#ifdef __cplusplus
}
#endif
#endif /* INCLUDE_STACK_H_ */
