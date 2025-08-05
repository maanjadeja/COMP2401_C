/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct Guest {

  int age;
  int heightInCm;
  float totalMoneyOnGuest; //ORIGINALLY THIS WAS OF TYPE INT
  int totalNumberOfTicketsOnGuest; //set to 0 at start
  int allDayRidePassOnGuest; //1 if true 0 if false
  int totalRidesGuestRode;

} Guest;


int initializeRandomValue(int,int);
Guest *getRandomArrayForGuests(int);
void freeDynamicallyAllocatedGuests(Guest*);

int main()
{
    Guest *theArrayOfGuests = getRandomArrayForGuests(300);

    printf("The age of the first guest is: %d\n",theArrayOfGuests[10].age);


    freeDynamicallyAllocatedGuests(theArrayOfGuests);



    return 0;
}


  int initializeRandomValue(int theLowerEndValue,int theUpperEndValue){

    int theRandomValue=0;

    theRandomValue = (rand() % (theUpperEndValue - theLowerEndValue + 1) + theLowerEndValue);

    return theRandomValue;



  }

 Guest *getRandomArrayForGuests(int theSizeOfGuestArray){

     Guest *guestPointer = (Guest *) malloc(theSizeOfGuestArray * sizeof(Guest));

     if(guestPointer==NULL){
         printf("Memory Allocation was UNSUCCESSFUL\n");
         exit(0);
     }
     for (int i=0; i<theSizeOfGuestArray; i++){

         Guest newGuest=NULL;
         guestPointer[i]=newGuest;

     }

     return guestPointer;

 }

 void freeDynamicallyAllocatedGuests(Guest* theNewDynamicallyAllocatedArray){


    free(theNewDynamicallyAllocatedArray);


 }
