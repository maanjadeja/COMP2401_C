#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int status, child;

  printf("I am the parent (PID=%d)\n", getpid());
  printf("I am spawning a child  ...\n");
  child = fork();

  if (child == 0) {
    printf("     I am the child (PID=%d) ... I will sleep for 2sec\n", getpid());
    sleep(2);
    printf("     I am awake!\n");  	
  }
  else {
    printf("I am now waiting for my child to wake up ...\n");
    wait(&status);
    printf("It looks like my child is awake, so I will quit in 2sec ...\n");
    sleep(2);
  }
  printf("Process %d terminating.\n", getpid());
}
