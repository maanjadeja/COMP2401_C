#include <stdio.h>
#include <string.h>


int main(int argc, char **argv){

  char name[100];
  printf("Enter Name: ");
  scanf("%s",name);

  for(int i = 0; i < strlen(name); i++) {
      printf("Character: %c  ASCII: %d\n",name[i], name[i]);
  }

  return 0;

}
