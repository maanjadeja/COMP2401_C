#include <stdio.h>
#include <stdlib.h>

int main() {
  // Show a list of files
  system("clear");
  system("ls");
  printf("\n");

  // Find out who the user is
  system("who");
  printf("\n");

  // Run the userInput program
  system("./userInput");
}
