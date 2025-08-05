#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void ignoreMessage(int);
void sleep5();

int main() {
  printf("  Process %d running\n", getpid());
  printf("  Ignoring the interrupt signal...\n");
  signal(SIGINT, SIG_IGN);

  sleep5();

  printf("\n  Really ignoring the interrupt signal...\n");
  signal(SIGINT, ignoreMessage);

  sleep5();

  printf("\n  Restoring the default handler...\n");
  signal(SIGINT, SIG_DFL);

  sleep5();

  printf("\n  All done!\n");
}

void ignoreMessage(int x) {
  printf("  Stop bugging me.\n");
}

void sleep5() {
  for (int i=1; i<=5; ++i) {
    sleep(1);
    printf("  Sleeping %d\n",i);
  }
}

