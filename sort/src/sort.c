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

static void merge(int someArray[], int leftIdx, int midIdx, int rightIdx)
{
  int ii, jj, k;
  int leftLen = midIdx - leftIdx + 1;
  int rightLen = rightIdx - midIdx;
  int leftArray[leftLen];
  int rightArray[rightLen];

  for(ii = 0; ii < leftLen; ii++)
  {
    leftArray[ii] = someArray[leftIdx + ii];
  }
  for(jj = 0; jj < rightLen; jj++)
  {
    rightArray[jj] = someArray[midIdx + 1 + jj];
  }

  ii = 0;
  jj = 0;
  k = leftIdx;
  while(ii < leftLen && jj < rightLen)
  {
    if(leftArray[ii] <= rightArray[jj])
    {
      someArray[k] = leftArray[ii];
      ii++;
    }
    else
    {
      someArray[k] = rightArray[jj];
      jj++;
    }
    k++;
  }

  //clean up leftovers
  while(ii < leftLen)
  {
    someArray[k] = leftArray[ii];
    ii++;
    k++;
  }
  while(jj < rightLen)
  {
    someArray[k] = rightArray[jj];
    jj++;
    k++;
  }

}

void sort_merge(int someArray[], int leftIdx, int rightIdx)
{
  int midIdx;
  if(rightIdx > leftIdx)
  {
    midIdx = (leftIdx + rightIdx) / 2;
    sort_merge(someArray, leftIdx, midIdx);
    sort_merge(someArray, midIdx+1, rightIdx);
    merge(someArray, leftIdx, midIdx, rightIdx);
  }
}

void sort_insertion(int someArray[], int length)
{
  for(int keyIdx = 1; keyIdx < length; keyIdx++)
  {
    int swappingIdx = keyIdx;
    for(int checkIdx = keyIdx - 1; checkIdx >= 0; checkIdx--)
    {
      if(someArray[swappingIdx] < someArray[checkIdx])
      {
        swap(&someArray[swappingIdx], &someArray[checkIdx]);
        swappingIdx--;
      }
      continue;
    }
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
