#include <stdio.h>
#include <unistd.h>

int main() {
  int childPID;

  printf("Forking...\n");

  childPID = fork();

  if (childPID == 0) {
    printf("fork() returned 0 ... so this is the spawned/child process\n");
    for (int i=1; i<=24; i++) {
      printf("The ants go marching *%2d* by *%2d*, hurrah, hurrah.\n", i, i);
      usleep(500000);
    }
  }
  else {
    printf("fork() returned %d ... so this is the parent process\n", childPID);
    for (int i=1; i<=24; i++) {
      printf("The ants go marching  %2d  by  %2d , hurrah, hurrah.\n", i, i);
      usleep(1000000);
    }
  }
}

