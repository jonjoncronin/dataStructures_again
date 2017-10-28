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

extern int llist_addToHead(int data, llist_node **listHead);
extern int llist_addToTail(int data, llist_node **listHead);
extern int llist_getLength(const llist_node *listHead);

extern int llist_removeHead(llist_node **listHead);
extern int llist_removeTail(llist_node **listHead);
extern int llist_removeAll(llist_node **listHead);

extern void llist_printList(const llist_node *listHead);

extern int llist_containsCycle(const llist_node *listHead);
extern llist_node* llist_reverse(llist_node *listHead);
extern void llist_removeDuplicates(llist_node *listHead);

extern llist_node* llist_getNode(llist_node *listHead, int index);

#ifdef __cplusplus
}
#endif
#endif /* INCLUDE_LLIST_H_ */
