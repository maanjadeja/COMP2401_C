#include<stdio.h>
#include<string.h>

// This is a forward reference
int palindrome(char *s);

int main() {

  char word[30];


  printf ("Enter a word or \"q\" to stop: ");
  scanf ("%s", word);

  while (strcmp(word, "q") != 0) {
    palindrome(word);
    printf ("Enter a word or \"q\" to stop: ");
    scanf ("%s", word);
  };

  return 0;

}

int palindrome(char *s)
{

  for(int i=0; i<strlen(s); i++){

    if(s[i] == s[strlen(s)-i]) {

      printf("%s is a palindrome\n",s);
      return 1;

    }
    else{

      printf("%s is not a palindrome\n",s);
      return 0;

    }


  }


  // add code to test for palindrome and print a message

}
