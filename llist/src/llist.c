/*
 * llist.c
 */
#ifdef __cplusplus
extern "C" {
#endif

#include <llist/llist.h>
#include <stdlib.h>
#include <stdio.h>

int llist_addToHead(int data, llist_node **listHead)
{
  llist_node *newNode;
  if (!listHead)
  {
    return -1;
  }

  newNode = (llist_node *)malloc(sizeof(llist_node));

  if (!newNode)
  {
    //ran out of memory
    return -2;
  }

  newNode->data = data;
  if(!*listHead)
  {
    newNode->next = NULL;
  }
  else
  {
    newNode->next = *listHead;
  }
  *listHead = newNode;
  return 1;
}

int llist_addToTail(int data, llist_node **listHead)
{
  llist_node *newNode;
  llist_node *prev, *runner;

  if (!listHead)
  {
    return -1;
  }

  newNode = (llist_node *)malloc(sizeof(llist_node));
  if (!newNode)
  {
    //ran out of memory
    return -2;
  }
  newNode->data = data;
  newNode->next = NULL;

  if (!*listHead)
  {
    *listHead = newNode;
    return 1;
  }

  prev = *listHead;
  runner = *listHead;
  while (runner)
  {
    prev = runner;
    runner = runner->next;
  }
  prev->next = newNode;

  return 1;
}

int llist_getLength(const llist_node *listHead)
{
  llist_node *runner;
  int length = 0;

  if (!listHead)
  {
    return 0;
  }
  runner = listHead;
  while(runner)
  {
    length++;
    runner = runner->next;
  }
  return length;
}

int llist_removeAll(llist_node **listHead)
{
  llist_node *runner;
  if (!listHead || !*listHead)
  {
    return 0;
  }

  while(*listHead)
  {
    runner = *listHead;
    *listHead = runner->next;
    free(runner);
  }
  return 1;
}

void llist_printList(const llist_node *listHead)
{
  llist_node *runner;

  if (!listHead)
  {
    printf("List is empty\n");
    return;
  }
  runner = listHead;
  printf("List Entries\n");
  printf("============\n");
  while(runner)
  {
    printf("%d\n", runner->data);
    runner = runner->next;
  }
  return;
}

int llist_containsCycle(const llist_node *listHead)
{
  llist_node *fastRunner;
  llist_node *slowRunner;

  if(!listHead || !listHead->next)
  {
    return 0;
  }
  fastRunner = listHead->next;
  slowRunner = listHead;

  while(fastRunner)
  {
    if(fastRunner == slowRunner)
    {
      return 1;
    }
    slowRunner = slowRunner->next;
    if(!fastRunner->next)
    {
      return 0;
    }
    fastRunner = fastRunner->next->next;
  }
  return 0;
}

llist_node* llist_reverse(llist_node *listHead)
{
  llist_node *prev = NULL;
  llist_node *runner = NULL;
  llist_node *advance = NULL;

  if(!listHead)
  {
    return NULL;
  }
  runner = listHead;
  advance = runner->next;
  while(advance)
  {
    runner->next = prev;
    prev = runner;
    runner = advance;
    advance = runner->next;
  }
  runner->next = prev;
  return runner;

}

#ifdef __cplusplus
}
#endif
