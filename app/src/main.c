#include <stdio.h>
#include <pthread.h>

#define NUM_LOOPS 500000000
// crticial/shared resource
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

int main(void)
{
  // spawn threads
  pthread_t tid;
  int inputVal = 1;
  pthread_create(&tid, NULL, counting_function, (void *)&inputVal);

  pthread_t tid2;
  int inputVal2 = -1;
  pthread_create(&tid2, NULL, counting_function, (void *)&inputVal2);

  // join threads
  pthread_join(tid, NULL);
  pthread_join(tid2, NULL);

  printf("Sum = %lld\n", sum);
  return 0;
}
