/*
 * list.h
 */

#ifndef INCLUDE_LLIST_H_
#define INCLUDE_LLIST_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _llist_node
{
  int data;
  struct _llist_node *next;
} llist_node;

extern int llist_addToHead(llist_node *newNode, llist_node *listHead);
extern int llist_addToTail(llist_node *newNode, llist_node *listHead);
extern int llist_getLength(llist_node *listHead);
extern int llist_removeAll(llist_node *listHead);

extern int llist_containsCycle(llist_node *listHead);
extern llist_node* llist_reverse(llist_node *listHead);

#ifdef __cplusplus
}
#endif
#endif /* INCLUDE_LLIST_H_ */
