#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stack/stack.h>
#define NUM_LOOPS 500000000
// crticial/shared resource
stack *sharedStack;

long long sum = 0;
pthread_mutex_t countLock = PTHREAD_MUTEX_INITIALIZER;

void* counting_function(void *startData)
{
  int offset = *(int *)startData;

  pthread_mutex_lock(&countLock);
  for (long long i = 0; i < NUM_LOOPS; i++)
  {
    sum += offset;
  }
  pthread_mutex_unlock(&countLock);
  pthread_exit(NULL);
  return NULL;
}

void* produceRandomVal(void *data)
{
  // while forever
  // generate an random value
  // get the stack if it is free
  // push the value into the stack
  // give the stack back
  // wait 2 seconds
  int valueIn;
  while(1)
  {
    valueIn = rand();
    pthread_mutex_lock(&countLock);
    stack_push(valueIn, sharedStack);
    printf("You are producing something\n");
    pthread_mutex_unlock(&countLock);
    sleep(2);
  }
  return NULL;
}

void* consumerRandomVal(void *data)
{
  // while forever
  // get the stack if it is free
  // pop the value and store it
  // give the stack back
  // print the value and free the node
  // wait 1 second
  int valueOut;
  stack_node *nodeOut = NULL;
  while(1)
  {
    pthread_mutex_lock(&countLock);
    nodeOut = stack_pop(sharedStack);
    pthread_mutex_unlock(&countLock);
    if(!nodeOut)
    {
      printf("You consumed too fast\n");
      sleep(10);
    }
    else
    {
      valueOut = nodeOut->data;
      free(nodeOut);
      nodeOut = NULL;
      printf("%d\n", valueOut);
      sleep(1);
    }
  }

  return NULL;
}

int main(void)
{
  pthread_t producer_tid;
  pthread_t consumer_tid;

  // initialize the stack
  sharedStack = stack_createStack();
  // create the threads
  pthread_create(&producer_tid, NULL, produceRandomVal, NULL);
  pthread_create(&consumer_tid, NULL, consumerRandomVal, NULL);

  // wait for the threads to finish
  pthread_join(producer_tid, NULL);
  pthread_join(consumer_tid, NULL);
  return 0;
}
