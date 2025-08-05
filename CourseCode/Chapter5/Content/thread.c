#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *printMsg(void*);
int  times[] = {4, 8, 2};  // # of seconds for each thread to run


int main() {
  pthread_t    t1, t2, t3;
  
  pthread_create(&t1, NULL, printMsg, "1");
  pthread_create(&t2, NULL, printMsg, "2");
  pthread_create(&t3, NULL, printMsg, "3");

  printf("\nThreads all created.  Waiting for Thread 1 now ...\n");
  pthread_join(t1, NULL);
  printf("\nThread 1 is back.  Waiting for Thread 2 now ...\n");
  pthread_join(t2, NULL);
  printf("Thread 2 is back.  Waiting for Thread 3 now ...\n");
  pthread_join(t3, NULL);
  printf("Thread 3 is back. Time to quit.\n");
}


// Function called at the start of each thread
void *printMsg(void *str) {
  char   threadNum = ((char *)str)[0] - 48;
  for (int i=0; i<times[threadNum-1]; i++) {
    for (int j=0; j<threadNum; j++) // indent a bit for visual clarity
      printf("  ");
    printf("Thread %d \n", threadNum);
    sleep(1);
  }
}

