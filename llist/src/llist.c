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

int llist_removeHead(llist_node **listHead)
{
  llist_node *nodeToDelete;
  llist_node *newHead = NULL;

  if(!listHead)
  {
    return 0;
  }
  if(!*listHead)
  {
    return 0;
  }

  nodeToDelete = *listHead;
  newHead = nodeToDelete->next;
  *listHead = newHead;
  free(nodeToDelete);
  return 1;
}

int llist_removeTail(llist_node **listHead)
{
  llist_node *nodeToDelete;
  llist_node *prev;
  if(!listHead)
  {
    return 0;
  }
  if(!*listHead)
  {
    return 0;
  }

  prev = *listHead;
  nodeToDelete = *listHead;

  if(!nodeToDelete->next)
  {
    *listHead = NULL;
    free(nodeToDelete);
    return 1;
  }

  while(nodeToDelete->next)
  {
    prev = nodeToDelete;
    nodeToDelete = nodeToDelete->next;
  }
  prev->next = NULL;
  free(nodeToDelete);
  return 1;
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

void llist_removeDuplicates(llist_node *listHead)
{
  llist_node *checker;
  llist_node *runner;
  llist_node *prev;

  if(!listHead || !listHead->next)
  {
    return;
  }
  runner = listHead;
  prev = listHead;
  checker = listHead->next;

  while(runner->next)
  {
    while(checker)
    {
      if(runner->data == checker->data)
      {
        llist_node *nodeToDelete = checker;
        prev->next = checker->next;
        checker = checker->next;
        free(nodeToDelete);
      }
      else
      {
        prev = checker;
        checker = checker->next;
      }
    }
    if(!runner->next)
    {
      return;
    }
    runner = runner->next;
    checker = runner->next;
    prev = runner;
  }
}

llist_node* llist_getNode(llist_node *listHead, int index)
{
  llist_node *runner;
  int curPosition = 0;

  if(!listHead)
  {
    return NULL;
  }
  if(index < 0)
  {
    return NULL;
  }

  runner = listHead;
  while(runner->next)
  {
    if(index == curPosition)
    {
      return runner;
    }
    runner = runner->next;
    curPosition += 1;
  }
  return runner;
}

llist_node* llist_getNodeKFromEnd(llist_node *listHead, int indexFromEnd)
{
  llist_node *runner;
  llist_node *trailer;
  int curPosition = 0;

  if(!listHead)
  {
    return NULL;
  }
  if(indexFromEnd < 0)
  {
    return NULL;
  }

  runner = listHead;
  trailer = listHead;
  while(runner->next)
  {
    if(curPosition >= indexFromEnd)
    {
      trailer = trailer->next;
    }
    runner = runner->next;
    curPosition += 1;
  }
  return trailer;
}
#ifdef __cplusplus
}
#endif
