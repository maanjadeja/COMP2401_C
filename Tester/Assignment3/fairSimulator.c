#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>



#define MAX_CHARACTERS 50
#define PRICE_OF_ADMISSION_ABOVE_13 15.26
//Guests that are 6 years old or under have free price of admission
#define PRICE_OF_ADMISSION_FOR_6_TO_13 7.63
#define PRICE_OF_ADMISSION_FOR_UNDER_6 0.00
#define COST_OF_SINGLE_RIDE_TICKET 1.13
#define COST_OF_ALL_DAY_RIDE_PASS 43.51

#define STARTING_AVAILABLE_TICKETS 5000
#define STARTING_AVAILABLE_ALL_DAY_RIDE_PASSES 200
#define TOTAL_NUMBER_OF_RIDES_AT_FAIR 10

#define MAX_GUESTS 300
#define NUMBER_OF_TICKETS_WHEN_GUEST_CANT_BUY_ALL_DAY_RIDE_PASS 40 //If guest cant afford the all day ride pass,how can they afford 40 ride tickets???


typedef struct TicketBooth {

  int rideTicketsSold;
  int allDayRidePassesSold;
  float totalMoneyMade;

} TicketBooth;

typedef struct Ride {

  char rideName[MAX_CHARACTERS];
  int numberOfTicketsRequired; //particular data type for values betwee 1-5 (unsigned int?)
  int heightRequirementInCm;
  int totalNumberOfRiders;
  int numberOfGuestsDeniedForHeightRequirement;

} Ride;

typedef struct Guest {

  int age;
  int heightInCm;
  float totalMoneyOnGuest; //ORIGINALLY THIS WAS OF TYPE INT
  int totalNumberOfTicketsOnGuest; //set to 0 at start
  int allDayRidePassOnGuest; //1 if true 0 if false
  int totalRidesGuestRode;

} Guest;

typedef struct Fair {

  TicketBooth theTicketBooth;
  Ride allRides[TOTAL_NUMBER_OF_RIDES_AT_FAIR];

} Fair;

int initializeRideInArray(Fair*,char[],int,int,int);
void addGuestsToArray(Guest[]);
void initGuests();
int calculateAgeValueOfGuest(int);
int initializeRandomValue(int,int);
void calculateMoneyOnGuest(Guest*);
void calculateHeightOnGuest(Guest*);
int admitGuestToFair(Fair*,Guest*);
int purchaseRideTicketsForGuest(Fair*,Guest*,int);
int purchaseAllDayRidePassForGuest(Fair*,Guest*);




int main(int argc, char **argv){

    Fair funFair;
    TicketBooth funFairTicketBooth;
    funFairTicketBooth.rideTicketsSold = 0;
    funFairTicketBooth.allDayRidePassesSold = 0;
    funFairTicketBooth.totalMoneyMade = 0.0;


    funFair.theTicketBooth = funFairTicketBooth;

    int indexValueOfRideInArray = 0;
    //initialize ride function(ride* ride, name, ....)
    initializeRideInArray(&funFair,"Fun House",1,60,indexValueOfRideInArray);
    indexValueOfRideInArray++;
    //strcpy(ride1.rideName, "Fun House");
    //ride1.numberOfTicketsRequired = 1;
    //ride1.heightRequirementInCm = 60;
    //&(funfair.allRides[0])

    //Ride ride2;
    initializeRideInArray(&funFair,"Merry-Go-Round",2,60,indexValueOfRideInArray);
    indexValueOfRideInArray++;
    //strcpy(ride2.rideName, "Merry-Go-Round");
    //ride2.numberOfTicketsRequired = 2;
    //ride2.heightRequirementInCm = 60;
    //addRideToFair(funFair,ride2);


    //Ride ride3;
    initializeRideInArray(&funFair,"Calm Train",3,105,indexValueOfRideInArray);
    indexValueOfRideInArray++;
    //strcpy(ride3.rideName, "Calm Train");
    //ride3.numberOfTicketsRequired = 3;
    //ride3.heightRequirementInCm = 105;
    //addRideToFair(funFair,ride3);


    //Ride ride4;
    initializeRideInArray(&funFair,"Tea Cups",3,108,indexValueOfRideInArray);
    indexValueOfRideInArray++;
    //strcpy(ride4.rideName, "Tea Cups");
    //ride4.numberOfTicketsRequired = 3;
    //ride4.heightRequirementInCm = 108;
    //addRideToFair(funFair,ride4);


    //Ride ride5;
    initializeRideInArray(&funFair,"Ferris Wheel",3,108,indexValueOfRideInArray);
    indexValueOfRideInArray++;
    //strcpy(ride5.rideName, "Ferris Wheel");
    //ride5.numberOfTicketsRequired = 4;
    //addRideToFair(funFair,ride5);
    //ride5.heightRequirementInCm = 110;


    //Ride ride6;
    initializeRideInArray(&funFair,"Back Destroyer",4,150,indexValueOfRideInArray);
    indexValueOfRideInArray++;
    //strcpy(ride6.rideName, "Back Destroyer");
    //ride6.numberOfTicketsRequired = 4;
    //ride6.heightRequirementInCm = 150;
    //addRideToFair(funFair,ride6);


    //Ride ride7;
    initializeRideInArray(&funFair,"Pirate Ship",4,152,indexValueOfRideInArray);
    indexValueOfRideInArray++;
    //strcpy(ride7.rideName, "Pirate Ship");
    //ride7.numberOfTicketsRequired = 4;
    //ride7.heightRequirementInCm = 152;
    //addRideToFair(funFair,ride7);


    //Ride ride8;
    initializeRideInArray(&funFair,"Drop To Death",5,154,indexValueOfRideInArray);
    indexValueOfRideInArray++;
    //strcpy(ride8.rideName, "Drop To Death");
    //ride8.numberOfTicketsRequired = 5;
    //ride8.heightRequirementInCm = 154;
    //addRideToFair(funFair,ride8);


    //Ride ride9;
    initializeRideInArray(&funFair,"Roller Coaster",5,156,indexValueOfRideInArray);
    indexValueOfRideInArray++;
    //strcpy(ride9.rideName, "Roller Coaster");
    //ride9.numberOfTicketsRequired = 5;
    //ride9.heightRequirementInCm = 156;
    //addRideToFair(funFair,ride9);


    //Ride ride10;
    initializeRideInArray(&funFair,"Tummy Tosser",5,160,indexValueOfRideInArray);
    indexValueOfRideInArray++;
    //strcpy(ride10.rideName, "Tummy Tosser");
    //ride10.numberOfTicketsRequired = 5;
    //ride10.heightRequirementInCm = 160;
    //addRideToFair(funFair, &ride10);*/

    //printf("NAME: %s\n",funFair.allRides[0].rideName);
    //printf("NUMBER OF TICKETS: %d\n",funFair.allRides[0].numberOfTicketsRequired);
    //printf("HEIGHT REQUIREMENT: %d\n",funFair.allRides[0].heightRequirementInCm);


    //Guest allGuests[MAX_GUESTS];
    //addGuestsToArray(allGuests);
    //initGuests();

    /*printf("WE ARE TESTING THE ADMIT TO FAIR FUNCTION HERE: \n");

    Guest aNewGuest;
    aNewGuest.age = 15;
    aNewGuest.heightInCm = 180;
    aNewGuest.totalMoneyOnGuest = 5.00;
    aNewGuest.allDayRidePassOnGuest=0;
    aNewGuest.totalRidesGuestRode=0;

    admitGuestToFair(&funFair,&aNewGuest);*/

    /*printf("WE ARE TESTING THE ALL DAY RIDE PASS PURCHASE FOR GUESTS HERE: \n");

    Guest aNewGuest;
    aNewGuest.age = 15;
    aNewGuest.heightInCm = 180;
    aNewGuest.totalMoneyOnGuest = 2.00;
    aNewGuest.allDayRidePassOnGuest=0;
    aNewGuest.totalRidesGuestRode=0;

    //purchaseRideTicketsForGuest(&funFair,&aNewGuest,10000);
    purchaseAllDayRidePassForGuest(&funFair,&aNewGuest);*/

    Guest allGuests[MAX_GUESTS];
    for(int i=0; i<MAX_GUESTS; i++){

      int ageValueOfGuest = calculateAgeValueOfGuest(i);
      allGuests[i].age = ageValueOfGuest;
      allGuests[i].allDayRidePassOnGuest=0;
      allGuests[i].totalNumberOfTicketsOnGuest=0;
      allGuests[i].totalRidesGuestRode=0;


      //printf("HERE WE ARE TESTING THE AGE VALUE OF THE GUEST:\n");
      //printf("THE AGE VALUE OF THE GUEST IS %d\n",allGuests[i].age);
      //printf("\n");
      calculateMoneyOnGuest(&allGuests[i]);
      //printf("HERE WE ARE TESTING THE MONEY CALCULATION OF THE GUEST:\n");
      //printf("TOTAL MONEY ON GUEST OF AGE %2d is $%.2f\n", allGuests[i].age, allGuests[i].totalMoneyOnGuest);
      printf("\n");
      calculateHeightOnGuest(&allGuests[i]);
      //printf("HERE WE ARE TESTING THE HEIGHT VALUE OF THE GUEST:\n");
      //printf("THE HEIGHT OF THE GUEST WHOSE AGE IS %d IS: %d\n", allGuests[i].age,allGuests[i].heightInCm);
      printf("\n");
      //printf("HERE WE ARE TESTING THE ADMIT GUEST TO FAIR FUNCTIONS:\n");
      if(admitGuestToFair(&funFair,&allGuests[i]) == 1){

        if(i<MAX_GUESTS/2){
          //purchase an all day ride pass
          printf("CALLING THE PURCHASE All DAY RIDE PASS FUNCTION BELOW:\n");

          if((purchaseAllDayRidePassForGuest(&funFair,&allGuests[i])) == 0){

            printf("TESTING THE CASE WHERE THE GUEST COULD NOT PURCHASE THE ALL DAY RIDE PASS\n");

            purchaseRideTicketsForGuest(&funFair,&allGuests[i],NUMBER_OF_TICKETS_WHEN_GUEST_CANT_BUY_ALL_DAY_RIDE_PASS);  //guest has to purchase 40 tickets in case they could not buy the all day ride pass

          }
          else{
            
              printf("TESTING THE CASE WHERE THE GUEST DID PURCHASE THE ALL DAY RIDE PASS\n");

              purchaseAllDayRidePassForGuest(&funFair,&allGuests[i]);
          }

          printf("\n");

        }
        else{
          //purchase tickets
          int numberOfTicketsGuestWantsToPurchase = initializeRandomValue(10,40);

          while(numberOfTicketsGuestWantsToPurchase%5!=0){

            numberOfTicketsGuestWantsToPurchase = initializeRandomValue(10,40);

          }

          printf("CALLING THE PURCHASE RIDE TICKETS FUNCTION BELOW:\n");

          if((purchaseRideTicketsForGuest(&funFair,&allGuests[i],numberOfTicketsGuestWantsToPurchase)) == 0){

            int updatedNumberOfTicketsGuestWantsToPurchase = numberOfTicketsGuestWantsToPurchase-5;
            float theFinalPrice1 = updatedNumberOfTicketsGuestWantsToPurchase*COST_OF_SINGLE_RIDE_TICKET;

            printf("THE UPDATED NUMBER OF TICKETS GUEST WANTS TO PURCAHASE IS %d ",updatedNumberOfTicketsGuestWantsToPurchase);
            printf("THE GUEST HAS A TOTAL OF $%.2f ",allGuests[i].totalMoneyOnGuest);
            printf("THE FINAL PRICE OF BUYING %d TICKETS WOULD BE $%.2f\n",updatedNumberOfTicketsGuestWantsToPurchase,theFinalPrice1);


            while((purchaseRideTicketsForGuest(&funFair,&allGuests[i],updatedNumberOfTicketsGuestWantsToPurchase)) == 0){ //THIS IS CAUSING THE FUNCTION TO GO INTO AN INFINITE LOOP??????

              float theFinalPrice2 = updatedNumberOfTicketsGuestWantsToPurchase*COST_OF_SINGLE_RIDE_TICKET;

              printf("THE PURCHASE OF BUYING %d TICKETS WAS NOT SUCCESSFUL ",updatedNumberOfTicketsGuestWantsToPurchase);
              printf("BECAUSE THE GUEST HAS A TOTAL OF $%.2f ",allGuests[i].totalMoneyOnGuest);
              printf("AND THE TOTAL PRICE TO PURCHASE %d TICKETS ",updatedNumberOfTicketsGuestWantsToPurchase);
              printf("WAS GOING TO BE $%.2f\n",theFinalPrice2);

              //printf("THE PURCHASE OF BUYING %d TICKETS WAS NOT SUCCESSFULE BECAUSE THE GUEST HAS $.2f AND THE TOTAL PRICE OF BUYING %d TICKETS WAS GOING TO BE $.2f\n",updatedNumberOfTicketsGuestWantsToPurchase,allGuests[i].totalMoneyOnGuest,updatedNumberOfTicketsGuestWantsToPurchase,theFinalPrice);
              updatedNumberOfTicketsGuestWantsToPurchase = updatedNumberOfTicketsGuestWantsToPurchase-5;


            }

            /*float theFinalPrice3 = updatedNumberOfTicketsGuestWantsToPurchase*COST_OF_SINGLE_RIDE_TICKET;

            printf("\n");
            printf("HERE WE FINALLY CHECK THE CASE WHERE THEY WERE ABLE TO PURCHASE THE TICKETS\n");
            printf("\n");

            printf("THE PURCHASE OF BUYING %d TICKETS WAS SUCCESSFUL ",updatedNumberOfTicketsGuestWantsToPurchase);
            printf("BECAUSE THE GUEST HAS A TOTAL OF $%.2f ",allGuests[i].totalMoneyOnGuest);
            printf("AND THE TOTAL PRICE TO PURCHASE %d TICKETS ",updatedNumberOfTicketsGuestWantsToPurchase);
            printf("WAS GOING TO BE $%.2f\n ",theFinalPrice3);*/


          }
          else{
            purchaseRideTicketsForGuest(&funFair,&allGuests[i],numberOfTicketsGuestWantsToPurchase);
          }



        }





      }


    }

    for(int j=0; j<MAX_GUESTS; j++){


      printf("\n");
      printf("THE GUESTS AGE IS %d\n",allGuests[j].age);
      printf("THE GUESTS HEIGHT IN cm IS %d\n",allGuests[j].heightInCm);
      printf("THE TOTAL AMOUNT OF MONEY ON GUEST IS $%.2f\n",allGuests[j].totalMoneyOnGuest);
      printf("THE TOTAL NUMBER OF TICKETS GUEST HAS IS %d\n",allGuests[j].totalNumberOfTicketsOnGuest);
      printf("THE GUEST HAS AN ALL DAY RIDE PASS VALUE OF %d\n",allGuests[j].allDayRidePassOnGuest);
      printf("THE TOTAL NUMBER OF RIDES THE GUEST RODE IS %d\n",allGuests[j].totalRidesGuestRode);
      printf("\n");

    }


}


int initializeRideInArray(Fair* theFair,char theName[],int theNumberOfTicketsRequired,int theHeightRequiredInCm, int theIndexValue){

  if(theIndexValue>TOTAL_NUMBER_OF_RIDES_AT_FAIR){
    return 0;
  }
  else{

    //printf("THE NAME: %s\n",theName);
    strcpy(theFair->allRides[theIndexValue].rideName, theName);
    theFair->allRides[theIndexValue].numberOfTicketsRequired = theNumberOfTicketsRequired;
    theFair->allRides[theIndexValue].heightRequirementInCm = theHeightRequiredInCm;
    return 1;

  }



}

/*void initGuests(Guest){

  srand(time(NULL));

  Guest allGuests[MAX_GUESTS];
  Fair newFair;

  //if i>MAX_GUESTS/2+MAX_GUESTS/4

  for(int i=0; i<MAX_GUESTS; i++){

    if(i<MAX_GUESTS/2){

      int ageValue1 = initializeRandomValue(13,19);

      //int upperAgeValue1 = 19;
      //int lowerAgeValue1 = 13;

      //ageValue1 = (rand() % (upperAgeValue1 - lowerAgeValue1 + 1) + lowerAgeValue1);

      //printf("AGE VALUE 1: %d\n",ageValue1);

      allGuests[i].age = ageValue1;

      calculateMoneyOnGuest(&allGuests[i]);

      printf("TOTAL MONEY ON GUEST OF AGE %2d is $%.2f\n", ageValue1, allGuests[i].totalMoneyOnGuest);

      calculateHeightOnGuest(&allGuests[i]);

      //printf("AGE OF THE GUEST WE ARE LOOKING AT: %d\n",allGuests[i].age);

      //admitGuestToFair(&newFair,&allGuests[i]);

      printf("THE HEIGHT OF THE GUEST WHOSE AGE IS %d IS: %d\n", allGuests[i].age,allGuests[i].heightInCm);

      admitGuestToFair(&newFair,&allGuests[i]);





    }
    else if((MAX_GUESTS*0.5 < i)  && (i < 0.75*MAX_GUESTS)){

      int ageValue2 = initializeRandomValue(5,12);

      //int upperAgeValue2 = 12;
      //int lowerAgeValue2 = 5;

      //ageValue2 = (rand() % (upperAgeValue2 - lowerAgeValue2 + 1) + lowerAgeValue2);

      //printf("AGE VALUE 2: %d\n",ageValue2);


      allGuests[i].age = ageValue2;
      calculateMoneyOnGuest(&allGuests[i]);
      printf("TOTAL MONEY ON GUEST OF AGE %2d is $%.2f\n", ageValue2, allGuests[i].totalMoneyOnGuest);
      calculateHeightOnGuest(&allGuests[i]);

      //printf("AGE OF THE GUEST WE ARE LOOKING AT: %d\n",allGuests[i].age);

      //admitGuestToFair(&newFair,&allGuests[i]);


      printf("THE HEIGHT OF THE GUEST WHOSE AGE IS %d IS: %d\n", allGuests[i].age,allGuests[i].heightInCm);

      //admitGuestToFair(&newFair,&allGuests[i]);




    }
    else{

      int ageValue3 = initializeRandomValue(20,65);


      //int upperAgeValue3 = 65;
      //int lowerAgeValue3 = 20; //This part is printing out the wrong ages, values are going above 65;

      //ageValue3 = (rand() % (upperAgeValue3 - lowerAgeValue3 + 1) + lowerAgeValue3);

      //printf("AGE VALUE 3: %d\n",ageValue3);


      allGuests[i].age = ageValue3;
      calculateMoneyOnGuest(&allGuests[i]);
      printf("TOTAL MONEY ON GUEST OF AGE %2d is $%.2f\n", ageValue3, allGuests[i].totalMoneyOnGuest);
      calculateHeightOnGuest(&allGuests[i]);

      //printf("AGE OF THE GUEST WE ARE LOOKING AT: %d\n",allGuests[i].age);
      //admitGuestToFair(&newFair,&allGuests[i]);


      printf("THE HEIGHT OF THE GUEST WHOSE AGE IS %d IS: %d\n", allGuests[i].age,allGuests[i].heightInCm);


      admitGuestToFair(&newFair,&allGuests[i]);





    }

  }


}*/

int calculateAgeValueOfGuest(int indexValueInGuestArray){

  if(indexValueInGuestArray < MAX_GUESTS/2){

    int ageValue1 = initializeRandomValue(13,19);
    printf("THE AGE FOUND FOR FIRST HALF OF GUEST IS %d\n",ageValue1 );
    return ageValue1;


  }
  else if((MAX_GUESTS*0.5 < indexValueInGuestArray)  && (indexValueInGuestArray < 0.75*MAX_GUESTS)){

    int ageValue2 = initializeRandomValue(5,12);
    printf("THE AGE FOUND FOR THIRD QUARTER OF GUEST IS %d\n",ageValue2 );

    return ageValue2;



  }

  else{

    int ageValue3 = initializeRandomValue(20,65);
    printf("THE AGE FOUND FOR LAST QUARTER OF GUEST IS %d\n",ageValue3);

    return ageValue3;

  }



}




  int initializeRandomValue(int theLowerEndValue,int theUpperEndValue){

    int theRandomValue=0;

    theRandomValue = (rand() % (theUpperEndValue - theLowerEndValue + 1) + theLowerEndValue);

    return theRandomValue;



  }


  void calculateMoneyOnGuest(Guest* theGuest){

    int totalMoney=0;

    int randomValue = initializeRandomValue(20,28);


    while(randomValue%2!=0){

      randomValue = initializeRandomValue(20,28);


    }

    /*if(randomValue%2!=0){

      randomValue = initializeRandomValue(20,28);

      //printf("THE RANDOM VALUE: %d\n",randomValue);

    }*/


      totalMoney = randomValue;
      //printf("THE RANDOM VALUE IN ELSE STATEMENT: %d\n", totalMoney);


      if(theGuest->age>=10){

        int numberOfDecades = floor(theGuest->age/10);

        int moneyToMultiplyWithDecades=initializeRandomValue(20,45);


        while(moneyToMultiplyWithDecades%5!=0){

          moneyToMultiplyWithDecades=initializeRandomValue(20,45);

        }


        //moneyToMultiplyWithDecades = initializeRandomValue(20,45);
        //printf("MONEY TO MULTIPLY: %d\n",moneyToMultiplyWithDecades);



        totalMoney += numberOfDecades * moneyToMultiplyWithDecades;
        theGuest->totalMoneyOnGuest = (float)totalMoney;


      }
      else{

        theGuest->totalMoneyOnGuest = (float)totalMoney;



      }





  }

  void calculateHeightOnGuest(Guest* theGuest){

    int heightOfGuest=0;

    if(theGuest->age<=12){

      int valueToMultiplyAgeWith = initializeRandomValue(72,81);

      heightOfGuest = valueToMultiplyAgeWith + (theGuest->age * 6);

      theGuest->heightInCm = heightOfGuest;


    }
    else{

      heightOfGuest = initializeRandomValue(149,280);
      theGuest->heightInCm = heightOfGuest;



    }



  }

  int admitGuestToFair(Fair* theFair,Guest* theGuest){

    if(theGuest->age >= 13 && theGuest->totalMoneyOnGuest>=PRICE_OF_ADMISSION_ABOVE_13){

      printf("SUCCESS FOR AGE >= 13 \n");
      theGuest->totalMoneyOnGuest-=PRICE_OF_ADMISSION_ABOVE_13;

      return 1;

    }
    else if((theGuest->age > 6) && (theGuest->age < 13) && theGuest->totalMoneyOnGuest>=PRICE_OF_ADMISSION_FOR_6_TO_13){

      printf("SUCCESS FOR AGE > 6 AND < 13 \n");
      theGuest->totalMoneyOnGuest-=PRICE_OF_ADMISSION_FOR_6_TO_13;

      return 1;


    }
    else if(theGuest->age <= 6 && theGuest->totalMoneyOnGuest>=PRICE_OF_ADMISSION_FOR_UNDER_6){

      printf("SUCCESS FOR AGE < 6\n");
      theGuest->totalMoneyOnGuest-=PRICE_OF_ADMISSION_FOR_UNDER_6;

      return 1;

    }
    else{

      printf("DID NOT ADMIT GUEST OF AGE %d BECAUSE THEY ONLY HAD $%.2f!\n",theGuest->age,theGuest->totalMoneyOnGuest);

      return 0;

    }

  }



  int purchaseRideTicketsForGuest(Fair* theFair,Guest* theGuest,int numberOfTicketsRequestedToBePurchased){

    int currentNumberOfTicketsAvailable = STARTING_AVAILABLE_TICKETS - theFair->theTicketBooth.rideTicketsSold;

    if(currentNumberOfTicketsAvailable < numberOfTicketsRequestedToBePurchased){

      printf("NOT ENOUGH TICKETS TO BE GIVEN TO THE GUEST BECAUSE THEY ARE ASKING FOR %d AND THERE ARE ONLY %d TICKETS AVAILABLE\n",numberOfTicketsRequestedToBePurchased,currentNumberOfTicketsAvailable);
      return 0;

    }
    else{

      float totalPriceOfTicketPurchase = COST_OF_SINGLE_RIDE_TICKET * numberOfTicketsRequestedToBePurchased;

      if(totalPriceOfTicketPurchase <= theGuest->totalMoneyOnGuest){

        printf("\n");
        printf("PURCHASE OF %d RIDE TICKETS WAS SUCCESSFUL BECAUSE THE TOTAL PRICE WAS $%.2f AND THE GUEST HAD A TOTAL OF $%.2f! \n",numberOfTicketsRequestedToBePurchased,totalPriceOfTicketPurchase,theGuest->totalMoneyOnGuest);
        printf("\n");

        printf("ORIGINAL AMOUNT OF NUMBER OF TICKETS SOLD %d\n", theFair->theTicketBooth.rideTicketsSold);
        printf("ORIGINAL AMOUNT OF MONEY FAIR HAS IS $%.2f\n", theFair->theTicketBooth.totalMoneyMade);
        printf("ORIGINAL AMOUNT OF MONEY THE GUEST HAS IS $%.2f\n", theGuest->totalMoneyOnGuest);


        theFair->theTicketBooth.rideTicketsSold+=numberOfTicketsRequestedToBePurchased;
        theFair->theTicketBooth.totalMoneyMade = totalPriceOfTicketPurchase;

        theGuest->totalMoneyOnGuest-=totalPriceOfTicketPurchase;

        printf("WE ARE CHECKING THE CURRENT VALUES OF EVERYTHING CHANGED AFTER BUYING RIDE TICKETS:\n");
        printf("THE TOTAL NUMBER OF RIDE TICKETS SOLD IS %d\n",theFair->theTicketBooth.rideTicketsSold);
        printf("THE TOTAL AMOUNT OF MONEY MADE FROM SELLING RIDE TICKETS IS $%.2f\n",theFair->theTicketBooth.totalMoneyMade);
        printf("THE CURRENT AMOUNT OF MONEY ON THE GUEST IS $%.2f\n",theGuest->totalMoneyOnGuest);


        return 1;


      }
      else{

        printf("PURCHASE OF RIDE TICKETS WAS NOT SUCCESSFUL BECAUSE THE TOTAL PRICE WAS $%.2f AND THE GUEST HAD A TOTAL OF $%.2f! \n",totalPriceOfTicketPurchase,theGuest->totalMoneyOnGuest);
        return 0;


      }



    }


  }


  int purchaseAllDayRidePassForGuest(Fair* theFair,Guest* theGuest){

    int currentNumberOfAllDayRidePassesAvailable = STARTING_AVAILABLE_ALL_DAY_RIDE_PASSES - theFair->theTicketBooth.allDayRidePassesSold;

    if(currentNumberOfAllDayRidePassesAvailable==0){

      printf("THERE ARE NO ALL DAY RIDE PASSES AVAILABLE AS THE CURRENT NUMBER OF RIDE PASSES AVAILABLE IS %d\n",currentNumberOfAllDayRidePassesAvailable);
      theGuest->allDayRidePassOnGuest=0;
      return 0;

    }
    else{

      if(theGuest->totalMoneyOnGuest >= COST_OF_ALL_DAY_RIDE_PASS){

        printf("\n");
        printf("PURCHASE OF ALL DAY RIDE PASS WAS SUCCESSFUL AS THE PRICE OF ALL DAY RIDE PASS IS $%.2f AND THE CURRENT AMOUNT OF MONEY ON THE GUEST IS $%.2f\n",COST_OF_ALL_DAY_RIDE_PASS,theGuest->totalMoneyOnGuest);
        printf("\n");

        printf("ORIGINAL AMOUNT OF ALL DAY RIDE PASSES SOLD %d\n", theFair->theTicketBooth.allDayRidePassesSold);
        printf("ORIGINAL AMOUNT OF MONEY FAIR HAS IS $%.2f\n", theFair->theTicketBooth.totalMoneyMade);
        printf("ORIGINAL AMOUNT OF MONEY THE GUEST HAS IS $%.2f\n", theGuest->totalMoneyOnGuest);

        theFair->theTicketBooth.allDayRidePassesSold++;
        theFair->theTicketBooth.totalMoneyMade+=COST_OF_ALL_DAY_RIDE_PASS;
        theGuest->totalMoneyOnGuest-=COST_OF_ALL_DAY_RIDE_PASS;
        theGuest->allDayRidePassOnGuest=1;


        printf("WE ARE CHECKING THE CURRENT VALUES OF EVERYTHING CHANGED AFTER BUYING AN ALL DAY RIDE PASS:\n");
        printf("THE TOTAL NUMBER OF ALL DAY RIDE PASSES SOLD IS %d\n",theFair->theTicketBooth.allDayRidePassesSold);
        printf("THE TOTAL AMOUNT OF MONEY MADE FROM SELLING ALL DAY RIDE PASSES IS $%.2f\n",theFair->theTicketBooth.totalMoneyMade);
        printf("THE CURRENT AMOUNT OF MONEY ON THE GUEST IS $%.2f\n",theGuest->totalMoneyOnGuest);

        return 1;


      }
      else{

        printf("PURCHASE OF ALL DAY RIDE PASS WAS NOT SUCCESSFUL BECAUSE THE TOTAL PRICE WAS $%.2f AND THE GUEST HAD A TOTAL OF $%.2f! \n",COST_OF_ALL_DAY_RIDE_PASS,theGuest->totalMoneyOnGuest);
        theGuest->allDayRidePassOnGuest=0;

        return 0;

      }


    }


  }
