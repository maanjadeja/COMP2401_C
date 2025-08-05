#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){

  //char = 1 byte = 8 bits = 8 binary [00000000] -> LARGEST NUMBER FOR CHAR = [11111111] = 255, therefore the largest number a char can hold is 255
 //int = 4 byte  = 32 bits

  int firstByteValue;
  int secondByteValue;

  printf("Enter 1st byte: ");
  scanf("%d", &firstByteValue);

  printf("Enter 2nd byte: ");
  scanf("%d", &secondByteValue);


  unsigned char number1 = (unsigned char)firstByteValue;
  unsigned char number2 = (unsigned char)secondByteValue;


  unsigned char firstBit1 =   number1&0b00000001;
  unsigned char firstBit2 = (number1&0b00000010)>>1;
  unsigned char firstBit3 = (number1&0b00000100)>>2;
  unsigned char firstBit4 = (number1&0b00001000)>>3;
  unsigned char firstBit5 = (number1&0b00010000)>>4;
  unsigned char firstBit6 = (number1&0b00100000)>>5;
  unsigned char firstBit7 = (number1&0b01000000)>>6;
  unsigned char firstBit8 = (number1&0b10000000)>>7;

  unsigned char secondBit1  =  number2&0b00000001;
  unsigned char secondBit2 = (number1&0b00000010)>>1;
  unsigned char secondBit3 = (number1&0b00000100)>>2;
  unsigned char secondBit4 = (number1&0b00001000)>>3;
  unsigned char secondBit5 = (number1&0b00010000)>>4;
  unsigned char secondBit6 = (number1&0b00100000)>>5;
  unsigned char secondBit7 = (number1&0b01000000)>>6;
  unsigned char secondBit8 = (number1&0b10000000)>>7;




  printf("\n");

  printf("a = ");

  printf("%u%u%u%u%u%u%u%u",firstBit8,firstBit7,firstBit6,firstBit5,firstBit4,firstBit3,firstBit2,firstBit1);

  printf(" = %d",firstByteValue);

  printf("\n");

  printf("b = ");

  printf("%u%u%u%u%u%u%u%u",secondBit8,secondBit7,secondBit6,secondBit5,secondBit4,secondBit3,secondBit2,secondBit1);

  printf(" = %d",secondByteValue);

  printf("\n");
  printf("------------------\n");

  printf("c = ");

  unsigned char cIn=0;
  //rename these to 8
  unsigned char firstExclusiveOr8 = firstBit1^secondBit1;
  unsigned char sValue8 = firstExclusiveOr8^cIn;
  unsigned char bottomAnd8 = firstBit1&secondBit1;
  unsigned char topAnd8 = firstExclusiveOr8&cIn;
  unsigned char cOutValue8 = topAnd8|bottomAnd8;

 // printf("%u",sValue8);
  cIn = cOutValue8;
  
   //printf("cout at 8 %u",cOutValue8);

  unsigned char firstExclusiveOr7 = firstBit2^secondBit2;
  unsigned char sValue7 = firstExclusiveOr7^cIn;
  unsigned char bottomAnd7 = firstBit2&secondBit2;
  unsigned char topAnd7 = firstExclusiveOr7&cIn;
  unsigned char cOutValue7 = topAnd7|bottomAnd7;



  //printf("%u",sValue7);
  cIn = cOutValue7;

  unsigned char firstExclusiveOr6 = firstBit3^secondBit3;
  unsigned char sValue6 = firstExclusiveOr6^cIn;
  unsigned char bottomAnd6 = firstBit3&secondBit3;
  unsigned char topAnd6 = firstExclusiveOr6&cIn;
  unsigned char cOutValue6 = topAnd6|bottomAnd6;

  //printf("%u",sValue6);
  cIn = cOutValue6;

  unsigned char firstExclusiveOr5 = firstBit4^secondBit4;
  unsigned char sValue5 = firstExclusiveOr5^cIn;
  unsigned char bottomAnd5 = firstBit4&secondBit4;
  unsigned char topAnd5 = firstExclusiveOr5&cIn;
  unsigned char cOutValue5 = topAnd5|bottomAnd5;

  //printf("%u",sValue5);
  cIn = cOutValue5;

  unsigned char firstExclusiveOr4 = firstBit5^secondBit5;
  unsigned char sValue4 = firstExclusiveOr4^cIn;
  unsigned char bottomAnd4 = firstBit5&secondBit5;
  unsigned char topAnd4 = firstExclusiveOr4&cIn;
  unsigned char cOutValue4 = topAnd4|bottomAnd4;

 // printf("%u",sValue4);
  cIn = cOutValue4;

  unsigned char firstExclusiveOr3 = firstBit6^secondBit6;
  unsigned char sValue3 = firstExclusiveOr3^cIn;
  unsigned char bottomAnd3 = firstBit6&secondBit6;
  unsigned char topAnd3 = firstExclusiveOr3&cIn;
  unsigned char cOutValue3 = topAnd3|bottomAnd3;

 // printf("%u",sValue3);
  cIn = cOutValue3;

  unsigned char firstExclusiveOr2 = firstBit7^secondBit7;
  unsigned char sValue2 = firstExclusiveOr2^cIn;
  unsigned char bottomAnd2 = firstBit7&secondBit7;
  unsigned char topAnd2 = firstExclusiveOr2&cIn;
  unsigned char cOutValue2 = topAnd2|bottomAnd2;

 // printf("%u",sValue2);
  cIn = cOutValue2;

  unsigned char firstExclusiveOr1 = firstBit8^secondBit8;
  unsigned char sValue1 = firstExclusiveOr1^cIn;
  unsigned char bottomAnd1 = firstBit8&secondBit8;
  unsigned char topAnd1 = firstExclusiveOr1&cIn;
  unsigned char cOutValue1 = topAnd1|bottomAnd1;

 // printf("%u",sValue1);
  cIn = cOutValue1;

  printf(" = ");
  
  printf("\nc = %u%u%u%u%u%u%u%u",sValue1,sValue2,sValue3,sValue4,sValue5,sValue6,sValue7,sValue8);

  //unsigned char finalValue; try and combine bits into 1 unsigned char?


  printf("\n");
 //printf("\n s value at 7 %u\n",sValue7);

  //unsigned char cOut8 = and8|andValue8;
  //unsigned char sValue8 = cIn^exOr8;



  /*unsigned char exOr7 = firstBit7^secondBit7;
  unsigned char and7 = firstBit7&secondBit7;
  unsigned char andValue7 = exOr7&cIn;
  unsigned char cOut7 = and7|andValue7;
  unsigned char sValue7 = cIn^exOr7;

  printf("%u",sValue7);
  cIn = cOut7;

  unsigned char exOr6 = firstBit6^secondBit6;
  unsigned char and6 = firstBit6&secondBit6;
  unsigned char andValue6 = exOr6&cIn;
  unsigned char cOut6 = and6|andValue6;
  unsigned char sValue6 = cIn^exOr6;

  printf("%u",sValue6);
  cIn = cOut6;

  unsigned char exOr5 = firstBit5^secondBit5;
  unsigned char and5 = firstBit5&secondBit5;
  unsigned char andValue5 = exOr5&cIn;
  unsigned char cOut5 = and5|andValue5;
  unsigned char sValue5 = cIn^exOr5;

  printf("%u",sValue5);
  cIn = cOut5;

  unsigned char exOr4 = firstBit4^secondBit4;
  unsigned char and4 = firstBit4&secondBit4;
  unsigned char andValue4 = exOr4&cIn;
  unsigned char cOut4 = and4|andValue4;
  unsigned char sValue4 = cIn^exOr4;

  printf("%u",sValue4);
  cIn = cOut4;

  unsigned char exOr3 = firstBit3^secondBit3;
  unsigned char and3 = firstBit3&secondBit3;
  unsigned char andValue3 = exOr3&cIn;
  unsigned char cOut3 = and3|andValue3;
  unsigned char sValue3 = cIn^exOr3;

  printf("%u",sValue3);
  cIn = cOut3;

  unsigned char exOr2 = firstBit2^secondBit2;
  unsigned char and2 = firstBit2&secondBit2;
  unsigned char andValue2 = exOr2&cIn;
  unsigned char cOut2 = and2|andValue2;
  unsigned char sValue2 = cIn^exOr2;

  printf("%u",sValue2);
  cIn = cOut2;

  unsigned char exOr1 = firstBit1^secondBit1;
  unsigned char and1 = firstBit1&secondBit1;
  unsigned char andValue1 = exOr1&cIn;
  unsigned char cOut1 = and1|andValue1;
  unsigned char sValue1 = cIn^exOr1;

  printf("%u",sValue1);
  cIn = cOut1;*/






  //int bitPosition=0;

  //firstByteValue = (firstByteValue & (1 << bitPosition)) >> bitPosition;

  //bitPosition++;

  //save all bits seperately from right to left


  //(firstByteValue & secondByteValue);






}

