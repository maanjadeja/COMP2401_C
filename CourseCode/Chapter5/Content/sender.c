#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main() {
  int pid, choice, result;

  printf("SENDER: Enter PID that you want to signal: ");
  scanf("%d", &pid);

  while (1) {
    printf("SENDER: Enter signal number (1 or 2), use 0 to quit: ");
    scanf("%d", &choice);
    switch(choice) {
      case 0: exit(0);
      case 1: result = kill(pid, SIGUSR1); break;
      case 2: result = kill(pid, SIGUSR2);
    }
    if (result == -1)
      printf("SENDER: *** Error sending signal to Process %d ***\n", pid);
  }
}

