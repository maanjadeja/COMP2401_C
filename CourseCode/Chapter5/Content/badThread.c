#include <stdio.h>
#include <pthread.h>

void* threadFunc(void*);

int count = 0;

int main() {
  int        numInc = 100000000; // count to 100 million
  pthread_t  t1, t2;

  pthread_create(&t1, NULL, threadFunc, &numInc);
  pthread_create(&t2, NULL, threadFunc, &numInc);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  if (count != (2 * numInc))
    printf("Error: Count is %d instead of 200,000,000.\n", count);
  else
    printf("Count is %d, which is correct.\n", count);

  return(0);
}

// Function to increase count variable by amount specified by arg
void* threadFunc(void *arg) {
  int inc = *((int *)arg);

  for (int i=0; i<inc; i++)
    count++;

  return (0);
}

