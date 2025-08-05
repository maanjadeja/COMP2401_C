#include <stdio.h>
#include <math.h>

void printAsBinary(unsigned char);


int main() {
  unsigned char n1  = 157;        // 10011101
  unsigned char n2  = 198;        // 11000110
  
  unsigned char answer;

  answer = ~n1;
  printf("~157 = %d, ~10011101 = ", answer);  printAsBinary(answer);
  answer = n1>>1;
  printf("\n157 >> 1 =  %d, 10011101 >> 1 = ", answer);  printAsBinary(answer);
  answer = n1>>2;
  printf("157 >> 2 =  %d, 10011101 >> 2 = ", answer);  printAsBinary(answer);
  answer = n1<<1; 
  printf("157 << 1 =  %d, 10011101 << 1 = ", answer);  printAsBinary(answer);
  answer = n1<<2;
  printf("157 << 2 = %d, 10011101 << 2 = ", answer);  printAsBinary(answer);
  answer = n1&n2;
  printf("\n157 & 198 = %d, 10011101 & 11000110 = ", answer);  printAsBinary(answer);
  answer = n1|n2;
  printf("157 | 198 = %d, 10011101 | 11000110 = ", answer);  printAsBinary(answer);
  answer = n1^n2;
  printf("157 ^ 198 =  %d, 10011101 ^ 11000110 = ", answer);  printAsBinary(answer);

  char  n3 = -100;    // 10011100
  char  answer2;
  
  answer2 = n3<<1;
  printf("\n-100 << 1 =  %d, 10011100 << 1 = ", answer2);printAsBinary(answer2);
  answer2 = n3<<4;
  printf("-100 << 4 = %d, 10011100 << 4 = ", answer2);printAsBinary(answer2);
  answer2 = n3>>1;
  printf("-100 >> 1 = %d, 10011100 >> 1 = ", answer2);printAsBinary(answer2);
  answer2 = n3>>4;
  printf("-100 >> 4 =  %d, 10011100 >> 4 = ", answer2);printAsBinary(answer2);


  return 0;
}


// Convert an unsigned char to an integer that looks like binary
void printAsBinary(unsigned char n) {
  for (int i=7; i>=0; i--) {
    //printf("(n=%d, p=%d, d=%d)", n, (int)pow(2,i), (int)(n/pow(2,i)));
    if ((int)(n/pow(2,i)) > 0) {
      printf("1");
      n = n - pow(2,i);
    }
    else
      printf("0");
  }
  printf("\n");
}
