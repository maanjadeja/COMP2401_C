#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void* threadFunc(void*);

volatile int count = 0;
sem_t mutex;


int main() {
  int          numInc = 100000000; // count to 100 million
  pthread_t    t1, t2;

  if (sem_init(&mutex, 0, 1) < 0) {
    printf("Error: on semaphore init.\n");
    exit(1);
  }

  pthread_create(&t1, NULL, threadFunc, &numInc);
  pthread_create(&t2, NULL, threadFunc, &numInc);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  if (count != (2 * numInc))
    printf("Error: Count is %d instead of 200,000,000.\n", count);
  else
    printf("Count is %d, which is correct.\n", count);
}


// Function to increase count variable by amount specified by arg
void* threadFunc(void *arg)  {
  int inc = *((int *)arg);

  for (int i=0; i<inc; i++) {
    if (sem_wait(&mutex) < 0) {
      printf("Error: on semaphore wait.\n");
      exit(1);
    }
    count++;
    if (sem_post(&mutex) < 0) {
      printf("Error: on semaphore post.\n");
      exit(1);
    }
  }
  return(0);
}

