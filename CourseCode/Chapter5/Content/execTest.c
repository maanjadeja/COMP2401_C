#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
  char  buffer[80]; 
  char *args[2];
  int   childPID;
  
  printf("This program is running.\n");
  printf("Now let's run the userInput program ...\n");

  strcpy(buffer, "./userInput");
  args[0] = "userInput";
  args[1] = NULL;

  childPID = execvp(buffer, args);

  // This code is never reached, unless the userInput program does not exist.
  printf("We returned from that program, which ran with PID = %d\n", childPID);
  printf("It appears, therefore, that the userInput program was not found.\n");
}

