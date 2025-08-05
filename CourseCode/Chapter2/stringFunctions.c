#include <stdio.h>
#include <string.h>

int main() {

  char *t1 = "Mark";
  char *t2 = "";
  char *t3;
  //char  t4[];
  char  t5[] = "";
  char  t6[25];
  char  t7[25] = "";
  
  printf("strlen(t1) = %d\n", strlen(t1));
  printf("strlen(t2) = %d\n", strlen(t2));
  //printf("strlen(t3) = %d\n", strlen(t3));
  printf("strlen(t5) = %d\n", strlen(t5));
  printf("strlen(t6) = %d\n", strlen(t6));
  printf("strlen(t7) = %d\n", strlen(t7));


  
  char *s = "Please enter your two names: ";
  int count = 0;
  for (int i=0; i<strlen(s); i++) {
    if (s[i] == ' ')
      count++;
  }
  printf("Number of spaces = %d\n", count);



  char *s1 = "This is the original";
  char s2[50];
  strcpy(s2, s1);
  s2[8] = ' ';
  s2[9] = 'u';
  s2[10] = 'n';
  s2[11] = '-';
  printf("s1 = %s\n", s1);   // displays "This is the original"
  printf("s2 = %s\n", s2);   // displays "This is  un-original"


  
  char s3[20];
  strncpy(s3, s1, 11);
  printf("s3 = %s\n", s3);  // displays "This is the/�+y�"
  s3[11] = '\0';
  printf("s3 = %s\n", s3);  // displays "This is the"

  

  char *s4 = "Chris";
  char *s5 = "Jen";
  char *s6 = "Will";
  printf("strcmp(Chris, Jen) = %d\n", strcmp(s4, s5));  // 43
  printf("strcmp(Jen, Chris) = %d\n", strcmp(s5, s4));  // 43
  printf("strcmp(Jen, Will) = %d\n", strcmp(s5, s6));   // 43
  printf("strcmp(Will, Chris) = %d\n", strcmp(s6, s4)); // 43
  printf("strcmp(Jen, Jen) = %d\n", strcmp(s5, s5));    // 0

  

  char *s7 = "Max";
  char *s8 = "Mark";
  char *s9 = "Melvin";
  printf("strncmp(Max, Mark, 2) = %d\n", strncmp(s7, s8, 2));  // -1
  printf("strncmp(Max, Mark, 3) = %d\n", strncmp(s7, s8, 3));  // 1
  printf("strncmp(Melvin, Mark, 1) = %d\n", strncmp(s9, s7, 1));// -1
  printf("strncmp(Max, Melvin, 5) = %d\n", strncmp(s7, s9, 5)); // 1
  printf("strncmp(Max, Max, 8) = %d\n", strncmp(s7, s7, 8));    // 0

  

  char *n1 = "Steve";
  char *n2 = "Martha";
  char *n3 = "Jacob";
  char result[50] = "";
  strcat(result, n1);
  strcat(result, ", ");
  strcat(result, n2);
  strcat(result, ", ");
  strcat(result, n3);
  printf("result = %s\n", result);   // displays "Steve, Martha, Jacob"

  

  char *n4 = "Steve";
  char *n5 = "ariel";
  char *n6 = "tup";
  char result2[50] = "";  
  strncat(result2, n4, 2);
  strncat(result2, n5,2);
  strncat(result2, n6, 3);
  strncat(result2, n4, 999);  // only appends 5 chars since null is there
  printf("result2 = %s\n", result2);   // displays "Startup"



  char answer[50];
  char    *name = "Bob";
  int       num = 1026784;
  float balance = 67.32;
  int     chars = sprintf(answer, "%s's account %d with $%0.2f", 
			  name, num, balance);
  printf("The string is \"%s\" with %d characters\n", answer, chars);

  
  return 0;
}

