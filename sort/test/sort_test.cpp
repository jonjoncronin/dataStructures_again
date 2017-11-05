#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <gtest/gtest.h>
#include <sort/sort.h>

TEST(SortTest, HappyBubbleSort) {
  clock_t t;
  double elapsed;
  int randomNum;
  int largeList[10000] = {0};

  for(int ii = 0; ii < 10000; ii++)
  {
    // insert a random number between 1 and 1000
    largeList[ii] = rand() % 100000 + 1;
  }
  t = clock();
  sort_bubble(largeList,10000);
  t = clock() - t;
  elapsed = ((double)t)/CLOCKS_PER_SEC;
  printf("Elapsed %f seconds\n", elapsed);
  //sort_printArray(largeList, 10000);
}
