#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int count;

  if (argc < 2)
    count = 1;
  else
    count = atoi(argv[1]);

  printf("Parent:  %d\n", getpid());

  for (int i=0; i<count; i++) {
    fork();
    fork();
  }

  printf("Child %d with parent %d \n", getpid(), getppid());
}
