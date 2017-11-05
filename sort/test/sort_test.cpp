#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <gtest/gtest.h>
#include <sort/sort.h>

#define MAX_LIST_SIZE 100000

TEST(SortTest, HappyBubbleSort) {
  clock_t t;
  double elapsed;
  int randomNum;
  int largeList[MAX_LIST_SIZE] = {0};

  for(int ii = 0; ii < MAX_LIST_SIZE; ii++)
  {
    // insert a random number between 1 and 1000
    largeList[ii] = rand() % ((MAX_LIST_SIZE * 10) + 1);
  }
  t = clock();
  sort_bubble(largeList,MAX_LIST_SIZE);
  t = clock() - t;
  elapsed = ((double)t)/CLOCKS_PER_SEC;
  printf("Elapsed %f seconds\n", elapsed);
  //sort_printArray(largeList, MAX_LIST_SIZE);
}

TEST(SortTest, HappySelectionSort) {
  clock_t t;
  double elapsed;
  int randomNum;
  int largeList[MAX_LIST_SIZE] = {0};

  for(int ii = 0; ii < MAX_LIST_SIZE; ii++)
  {
    // insert a random number between 1 and 1000
    largeList[ii] = rand() % ((MAX_LIST_SIZE * 10) + 1);
  }
  t = clock();
  sort_selection(largeList,MAX_LIST_SIZE);
  t = clock() - t;
  elapsed = ((double)t)/CLOCKS_PER_SEC;
  printf("Elapsed %f seconds\n", elapsed);
  // sort_printArray(largeList, MAX_LIST_SIZE);
}

TEST(SortTest, HappyMergeSort) {
  clock_t t;
  double elapsed;
  int randomNum;
  int largeList[MAX_LIST_SIZE] = {0};

  for(int ii = 0; ii < MAX_LIST_SIZE; ii++)
  {
    // insert a random number between 1 and 1000
    largeList[ii] = rand() % ((MAX_LIST_SIZE * 10) + 1);
  }
  t = clock();
  sort_merge(largeList, 0, MAX_LIST_SIZE - 1);
  t = clock() - t;
  elapsed = ((double)t)/CLOCKS_PER_SEC;
  printf("Elapsed %f seconds\n", elapsed);
  // sort_printArray(largeList, MAX_LIST_SIZE);
}

TEST(SortTest, HappyInsertionSort) {
  clock_t t;
  double elapsed;
  int randomNum;
  int largeList[MAX_LIST_SIZE] = {0};

  for(int ii = 0; ii < MAX_LIST_SIZE; ii++)
  {
    // insert a random number between 1 and 1000
    largeList[ii] = rand() % ((MAX_LIST_SIZE * 10) + 1);
  }
  t = clock();
  sort_insertion(largeList, MAX_LIST_SIZE);
  t = clock() - t;
  elapsed = ((double)t)/CLOCKS_PER_SEC;
  printf("Elapsed %f seconds\n", elapsed);
  // sort_printArray(largeList, MAX_LIST_SIZE);
}
