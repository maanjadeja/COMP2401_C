#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handleSig1(int);
void handleSig2(int);

int main() {
  signal(SIGUSR1, handleSig1);
  signal(SIGUSR2, handleSig2);

  printf("\n  HANDLER: Running (PID=%d)\n", getpid());

  // Go into an infinite loop
  while (1)
    sleep(1);

  printf("This line of code is never reached.\n");
}

void handleSig1(int i) {
  printf("  HANDLER: Signal 1 has been received.  Continuing...\n");
}

void handleSig2(int i) {
  printf("  HANDLER: Signal 2 has been received.  Quitting...\n");
  exit(SIGUSR2);
}
