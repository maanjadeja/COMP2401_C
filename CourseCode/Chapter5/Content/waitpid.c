#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
  int status, child, parent, children[5], sleepTimes[5] = {1, 5, 8, 2, 4};

  printf("I am the parent (PID=%d)\n", parent = getpid());
  printf("I am spawning 5 children  ...\n");
  for (int i=0; i<5; i++) {
    if (getpid() == parent)
      children[i] = fork();
      if (children[i] == 0) {
	printf("     I am a child (PID=%d) ... I will sleep for %dsec\n", getpid(), sleepTimes[i]);
	sleep(sleepTimes[i]);
	printf("     I am awake!  Process %d terminating.\n", getpid());
	exit(0);
      }
  }

  printf("I am now waiting for child 3 to wake up ...\n");
  child = waitpid(children[2], &status, 0);
  printf("It looks like my slowest child (PID=%d) has awoken.\n", child);
  printf("All children are done.  Process %d terminating.\n", getpid());
}
