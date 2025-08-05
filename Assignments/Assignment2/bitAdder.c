#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){


  int firstByteValue;   //Variable to store first digit the user inputs
  int secondByteValue;  //Variable to store second digit the user inputs

  //Prompting the user to enter first and second digit
  printf("Enter 1st byte: ");
  scanf("%d", &firstByteValue);

  printf("Enter 2nd byte: ");
  scanf("%d", &secondByteValue);

  //Saving both input digits as unsigned chars in order to be able to do bit shifting on them
  unsigned char number1 = (unsigned char)firstByteValue;
  unsigned char number2 = (unsigned char)secondByteValue;


  //Retrieving bits of first input value in order of least significant to most significant, where firstBit1 is considered the least significant bit, and firstBit8 is considered the most significant bit
  unsigned char firstBit1 =   number1&0b00000001;
  unsigned char firstBit2 = (number1&0b00000010)>>1;
  unsigned char firstBit3 = (number1&0b00000100)>>2;
  unsigned char firstBit4 = (number1&0b00001000)>>3;
  unsigned char firstBit5 = (number1&0b00010000)>>4;
  unsigned char firstBit6 = (number1&0b00100000)>>5;
  unsigned char firstBit7 = (number1&0b01000000)>>6;
  unsigned char firstBit8 = (number1&0b10000000)>>7;

  //Retrieving bits of second input value in order of least significant to most significant, where secondBit1 is considered the least significant bit, and secondBit8 is considered the most significant bit
  unsigned char secondBit1  =  number2&0b00000001;
  unsigned char secondBit2 = (number2&0b00000010)>>1;
  unsigned char secondBit3 = (number2&0b00000100)>>2;
  unsigned char secondBit4 = (number2&0b00001000)>>3;
  unsigned char secondBit5 = (number2&0b00010000)>>4;
  unsigned char secondBit6 = (number2&0b00100000)>>5;
  unsigned char secondBit7 = (number2&0b01000000)>>6;
  unsigned char secondBit8 = (number2&0b10000000)>>7;




  printf("\n");

  printf("a = ");

  printf("%u%u%u%u%u%u%u%u",firstBit8,firstBit7,firstBit6,firstBit5,firstBit4,firstBit3,firstBit2,firstBit1);         //Printing out the bits of the first value

  printf(" = %3d",firstByteValue);  //Printing out the first input value in decimal form

  printf("\n");

  printf("b = ");

  printf("%u%u%u%u%u%u%u%u",secondBit8,secondBit7,secondBit6,secondBit5,secondBit4,secondBit3,secondBit2,secondBit1); //Printing out the bits of the second value

  printf(" = %3d",secondByteValue); //Printing out the second input value in decimal form

  printf("\n");
  printf("------------------\n"); //Printing out the line to seperate the sum value with the inut values

  printf("c = ");

  //Performing bitwise operations as given in the assignment specification in order to retrieve bits of the sum value
  unsigned char cIn=0;

  unsigned char firstExclusiveOr8 = firstBit1^secondBit1;
  unsigned char sValue8 = firstExclusiveOr8^cIn;
  unsigned char bottomAnd8 = firstBit1&secondBit1;
  unsigned char topAnd8 = firstExclusiveOr8&cIn;
  unsigned char cOutValue8 = topAnd8|bottomAnd8;

  cIn = cOutValue8;

  unsigned char firstExclusiveOr7 = firstBit2^secondBit2;
  unsigned char sValue7 = firstExclusiveOr7^cIn;
  unsigned char bottomAnd7 = firstBit2&secondBit2;
  unsigned char topAnd7 = firstExclusiveOr7&cIn;
  unsigned char cOutValue7 = topAnd7|bottomAnd7;

  cIn = cOutValue7;

  unsigned char firstExclusiveOr6 = firstBit3^secondBit3;
  unsigned char sValue6 = firstExclusiveOr6^cIn;
  unsigned char bottomAnd6 = firstBit3&secondBit3;
  unsigned char topAnd6 = firstExclusiveOr6&cIn;
  unsigned char cOutValue6 = topAnd6|bottomAnd6;

  cIn = cOutValue6;

  unsigned char firstExclusiveOr5 = firstBit4^secondBit4;
  unsigned char sValue5 = firstExclusiveOr5^cIn;
  unsigned char bottomAnd5 = firstBit4&secondBit4;
  unsigned char topAnd5 = firstExclusiveOr5&cIn;
  unsigned char cOutValue5 = topAnd5|bottomAnd5;

  cIn = cOutValue5;

  unsigned char firstExclusiveOr4 = firstBit5^secondBit5;
  unsigned char sValue4 = firstExclusiveOr4^cIn;
  unsigned char bottomAnd4 = firstBit5&secondBit5;
  unsigned char topAnd4 = firstExclusiveOr4&cIn;
  unsigned char cOutValue4 = topAnd4|bottomAnd4;

  cIn = cOutValue4;

  unsigned char firstExclusiveOr3 = firstBit6^secondBit6;
  unsigned char sValue3 = firstExclusiveOr3^cIn;
  unsigned char bottomAnd3 = firstBit6&secondBit6;
  unsigned char topAnd3 = firstExclusiveOr3&cIn;
  unsigned char cOutValue3 = topAnd3|bottomAnd3;

  cIn = cOutValue3;

  unsigned char firstExclusiveOr2 = firstBit7^secondBit7;
  unsigned char sValue2 = firstExclusiveOr2^cIn;
  unsigned char bottomAnd2 = firstBit7&secondBit7;
  unsigned char topAnd2 = firstExclusiveOr2&cIn;
  unsigned char cOutValue2 = topAnd2|bottomAnd2;

  cIn = cOutValue2;

  unsigned char firstExclusiveOr1 = firstBit8^secondBit8;
  unsigned char sValue1 = firstExclusiveOr1^cIn;
  unsigned char bottomAnd1 = firstBit8&secondBit8;
  unsigned char topAnd1 = firstExclusiveOr1&cIn;
  unsigned char cOutValue1 = topAnd1|bottomAnd1;

  cIn = cOutValue1;

  printf("%u%u%u%u%u%u%u%u",sValue1,sValue2,sValue3,sValue4,sValue5,sValue6,sValue7,sValue8);   //Printing out the bits of the sum value after bitwise above for each bit in order of most significant to least significant, where sValue1 is most significant bit and sValue8 is the least significant bit

  printf(" = ");

  unsigned int sumValue3 = (cOutValue1 << 8) | (sValue1 << 7) | (sValue2 << 6) | (sValue3 << 5) | (sValue4 << 4) | (sValue5 << 3) | (sValue6 << 2) | (sValue7 << 1) | sValue8; //We use unsigned int sumValue to hold the decimal form of the sum of both input digits, the reason we use unsigned int is for cases where the sum value can possibly go over 255
  printf("%3u\n",sumValue3); //Printing out the sum value in decimal form

  printf("\n");



}
