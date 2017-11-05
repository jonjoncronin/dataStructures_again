/*
 * sort.c
 */
#ifdef __cplusplus
extern "C" {
#endif

#include <sort/sort.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void swap(int *value1, int *value2)
{
  int temp = *value1;
  *value1 = *value2;
  *value2 = temp;
}

void sort_bubble(int someArray[], int length)
{
  bool swapped;
  // Start at the beginning of the array but
  // don't worry about the last entry.
  // We will sort and sort in the worst case
  // as many times as there are numbers in the
  // set.
  for(int ii = 0; ii < length - 1; ii++)
  {
    swapped = false;
    // Starting from the beginning of the array
    // until we do a pass without swapping
    // swap the largest value to the end of the
    // array.
    for(int jj = 0; jj < length - 1 - ii; jj++)
    {
      if(someArray[jj] > someArray[jj+1])
      {
        swap(&someArray[jj],&someArray[jj+1]);
        swapped = true;
      }
    }
    if(!swapped)
    {
      break;
    }
  }
}

void sort_selection(int someArray[], int length)
{
  int minIndex;
  for(int ii = 0; ii < length - 1; ii++)
  {
    minIndex = ii;
    for(int jj = ii + 1; jj < length; jj++)
    {
      if(someArray[jj] < someArray[minIndex])
      {
        minIndex = jj;
      }
    }
    swap(&someArray[ii], &someArray[minIndex]);
  }
}
void sort_printArray(int someArray[], int length)
{
  printf("Array listing\n");
  printf("=================\n");
  for(int ii = 0; ii < length; ii++)
  {
    printf("%5d\n",someArray[ii]);
  }
}

#ifdef __cplusplus
}
#endif
