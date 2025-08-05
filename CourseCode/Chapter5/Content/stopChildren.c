#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main() {
  int parent, childProcess[5];

  printf("I am the parent (PID=%d)\n", parent = getpid());
  printf("I am spawning 3 children  ...\n");
  for (int i=0; i<3; i++) {
    if (getpid() == parent)
      childProcess[i] = fork();
      if (childProcess[i] == 0) {
	for (int j=30; j>0; j--) {
	  printf("     Child (PID=%d) sleeping for %d more sec\n", getpid(), j);
	  sleep(1);
	}
	exit(0);
      }
  }
  system("ps");
  
  printf("I am now waiting for 3 seconds then will stop all the children ...\n");
  sleep(3);
  for (int i=0; i<3; i++)
    kill(childProcess[i], SIGKILL);

  system("ps");
  sleep(3);
  printf("I stopped all child processes ... terminating now.\n");
}
