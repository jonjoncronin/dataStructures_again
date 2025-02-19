/*
 * sort.h
 */

#ifndef INCLUDE_SORT_H_
#define INCLUDE_SORT_H_

#ifdef __cplusplus
extern "C" {
#endif

extern void sort_bubble(int someArray[], int length);
extern void sort_selection(int someArray[], int length);
extern void sort_merge(int someArray[], int leftIdx, int rightIdx);
extern void sort_insertion(int someArray[], int length);

extern void sort_printArray(int someArray[], int length);

#ifdef __cplusplus
}
#endif
#endif /* INCLUDE_SORT_H_ */
