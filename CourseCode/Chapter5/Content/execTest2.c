#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
  char  buffer[80]; 
  char *args[4];
  int   childPID;
  
  printf("This program is running.\n");
  printf("Now let's run the cmdLineArgs program ...\n");

  strcpy(buffer, "./cmdLineArgs");
  args[0] = "cmdLineArgs";
  args[1] = "one";
  args[2] = "two";
  args[3] = NULL;

  childPID = execvp(buffer, args);

  // This code is never reached, unless the cmdLineArgs program does not exist.
  printf("We returned from that program, which ran with PID = %d\n", childPID);
  printf("It appears, therefore, that the cmdLineArgs program was not found.\n");
}

