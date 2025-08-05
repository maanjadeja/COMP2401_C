#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>



#define MAX_CHARACTERS 50                                           //Constant variable to store the maximum number of characters a name can have

#define PRICE_OF_ADMISSION_ABOVE_13 15.26                           //Constant variable to store the price of admission for a guest greater than or equal to the age of 13
#define PRICE_OF_ADMISSION_FOR_6_TO_13 7.63                         //Constant variable to store the price of admission for a guest whose age is above 6 and under 13
#define PRICE_OF_ADMISSION_FOR_UNDER_6 0.00                         //Constant variable to store the price of admission for a guest whose age is less than or equal to 6

#define COST_OF_SINGLE_RIDE_TICKET 1.13                             //Constant variable to store the price of a single ride ticket
#define COST_OF_ALL_DAY_RIDE_PASS 43.51                             //Constant variable to store the price of a single all day ride pass

#define STARTING_AVAILABLE_TICKETS 5000                             //Constant variable to store the starting available number of tickets
#define STARTING_AVAILABLE_ALL_DAY_RIDE_PASSES 200                  //Constant variable to store the starting available number of all day ride passes
#define TOTAL_NUMBER_OF_RIDES_AT_FAIR 10                            //Constant variable to store the number of rides at the fair

#define MAX_GUESTS 300                                              //Constant variable to store the maximum number of guests at the fair
#define NUMBER_OF_TICKETS_WHEN_GUEST_CANT_BUY_ALL_DAY_RIDE_PASS 40  //Constant variable to store the number of tickets the guest tries to purchase when they could not buy an all day ride pass


typedef struct TicketBooth {

  unsigned short rideTicketsSold;                           //Variable to store the total number of ride tickets sold
  unsigned char allDayRidePassesSold;                       //Variable to store the total number of all day ride passes sold
  float totalMoneyMade;                                     //Variable to store the total amount of money made at the fair

} TicketBooth;

typedef struct Ride {

  char rideName[MAX_CHARACTERS];                            //Variable to store the name of the ride
  unsigned char numberOfTicketsRequired;                    //Variable to store the total number of ride tickets required to get on the ride
  unsigned short heightRequirementInCm;                     //Variable to store the height requirement for the guest to get on the ride
  unsigned short totalNumberOfRiders;                       //Variable to store the total number of guests that rode the ride
  unsigned short numberOfGuestsDeniedForHeightRequirement;  //Variable to store the total number of guests denied to get on the ride due to not meeting the height requirement

} Ride;

typedef struct Guest {

  unsigned char age;                                        //Variable to store the age of the guest
  unsigned short heightInCm;                                //Variable to store the height of the guest in cm
  float totalMoneyOnGuest;                                  //Variable to store the total amount of money the guest has
  unsigned short totalNumberOfTicketsOnGuest;               //Variable to store the total number of ride tickets the guest has
  unsigned char allDayRidePassOnGuest;                      //Variable to determine whether the guest has an all day ride pass, it would be 1 if they do have an all day ride pass, and 0 if they do not have an all day ride pass
  unsigned char totalRidesGuestRode;                        //Variable to store the total number of rides the guest went on

} Guest;

typedef struct Fair {

  TicketBooth theTicketBooth;                               //Variable to store a ticket booth for the fair
  Ride allRides[TOTAL_NUMBER_OF_RIDES_AT_FAIR];             //Variable to store the array of rides at the fair

} Fair;

int initializeRideInArray(Fair*,char[],int,int,int);  //Function to add a ride into the ride array of the fair with the details required: name, number of tickets required, height requirement, and index value of location in the array to save the ride in. Return 1 if succussful and 0 if unsuccessful.
//void addGuestsToArray(Guest[]);
//void initGuests();
int calculateAgeValueOfGuest(int);                    //Function to calculate the age of the guest with a parameter of the index value in the guest array to determine the 1/2 and 1/4 of the guests age to be as specified, and return the calculated value
int initializeRandomValue(int,int);                   //Function that returns a random value according the maximum and minimum values given in the parameters inclusively
void calculateMoneyOnGuest(Guest*);                   //Function that calculates the amount of money the guest will have, and setting the amount of money on Guest* parameter to the calculated value
void calculateHeightOnGuest(Guest*);                  //Function that calculates the height of the guest, setting the height on Guest* parameter to the calculated value
int admitGuestToFair(Fair*,Guest*);                   //Function attempts to admit a guest to the fair, by checking if they can pay the fee and making them pay the fee. Return 1 if succussful and 0 if unsuccessful.
int purchaseRideTicketsForGuest(Fair*,Guest*,int);    //Function that attempts to purchase requested number of tickets as specified in the parameters. Function checks if they can afford it or not and if there are enough tickets to sell. Return 1 if successful and 0 if unsuccessful.
int purchaseAllDayRidePassForGuest(Fair*,Guest*);     //Function that attempts to purchase an all day ride pass for the guest by checking there are enough passes and if the guest can afford it. Return 1 if successful and 0 if unsuccessful.
int guestAttemptsToGoOnRide(Guest*, Ride*);           //Function that attempts to make the guest go on the ride buy checking if they pass the height requirement, if they have required number of tickets, or an all day ride pass. Return 1 if successful and 0 if unsuccessful.




int main(int argc, char **argv){

    Fair funFair;                                 //Variable to create a fair
    TicketBooth funFairTicketBooth;               //Variable to create a ticket booth for the fair
    funFairTicketBooth.rideTicketsSold = 0;       //Initializing all the ticket booth values to 0
    funFairTicketBooth.allDayRidePassesSold = 0;
    funFairTicketBooth.totalMoneyMade = 0.0;


    funFair.theTicketBooth = funFairTicketBooth;  //Setting the creating ticket booth to be the ticket booth for the fair created

    int indexValueOfRideInArray = 0;  //Variable to keep track of the index in the ride array of the fair to place the created rides in the correct location

    //Calling initializeRideInArray function to create all rides with their requirements and adding them to the fair ride array at the right index value
    initializeRideInArray(&funFair,"Fun House",1,60,indexValueOfRideInArray);
    indexValueOfRideInArray++;

    initializeRideInArray(&funFair,"Merry-Go-Round",2,60,indexValueOfRideInArray);
    indexValueOfRideInArray++;

    initializeRideInArray(&funFair,"Calm Train",3,105,indexValueOfRideInArray);
    indexValueOfRideInArray++;

    initializeRideInArray(&funFair,"Tea Cups",3,108,indexValueOfRideInArray);
    indexValueOfRideInArray++;

    initializeRideInArray(&funFair,"Ferris Wheel",4,110,indexValueOfRideInArray);
    indexValueOfRideInArray++;

    initializeRideInArray(&funFair,"Back Destroyer",4,150,indexValueOfRideInArray);
    indexValueOfRideInArray++;

    initializeRideInArray(&funFair,"Pirate Ship",4,152,indexValueOfRideInArray);
    indexValueOfRideInArray++;

    initializeRideInArray(&funFair,"Drop To Death",5,154,indexValueOfRideInArray);
    indexValueOfRideInArray++;

    initializeRideInArray(&funFair,"Roller Coaster",5,156,indexValueOfRideInArray);
    indexValueOfRideInArray++;

    initializeRideInArray(&funFair,"Tummy Tosser",5,160,indexValueOfRideInArray);
    indexValueOfRideInArray++;



    //Initializing all pending values of the rides: totalNumberOfRiders and numberOfGuestsDeniedForHeightRequirement to 0
    for(int x=0; x<TOTAL_NUMBER_OF_RIDES_AT_FAIR; x++){

      funFair.allRides[x].totalNumberOfRiders=0;
      funFair.allRides[x].numberOfGuestsDeniedForHeightRequirement=0;


    }


    Guest allGuests[MAX_GUESTS];                  //Creating guest array of size 300
    for(int i=0; i<MAX_GUESTS; i++){

      //Initializing all values of the guest data to 0
      allGuests[i].age=0;
      allGuests[i].heightInCm=0;
      allGuests[i].totalMoneyOnGuest=0.00;
      allGuests[i].totalNumberOfTicketsOnGuest=0;
      allGuests[i].allDayRidePassOnGuest=0;
      allGuests[i].totalRidesGuestRode=0;


      int ageValueOfTheGuest = calculateAgeValueOfGuest(i);   //Calling calculateAgeValueOfGuest function to find age of the guest
      allGuests[i].age = ageValueOfTheGuest;                  //Setting age of the guest to calculated age
      calculateMoneyOnGuest(&allGuests[i]);                   //Calling calculateMoneyOnGuest function to set the money of the guest
      calculateHeightOnGuest(&allGuests[i]);                  //Calling the calculateHeightOnGuest function to set the height of the guest

      if(admitGuestToFair(&funFair,&allGuests[i]) == 0){      //Handling the case where the guest could not be admitted to the fair and making sure they do not purchase tickets or all day ride passes

        allGuests[i].totalNumberOfTicketsOnGuest=0;
        allGuests[i].allDayRidePassOnGuest=0;

      }
      else{

        unsigned char coinToss = rand()%2; //Calling the rand function to help in requirement where 1/2 guests try to purchase all day ride pass and 1/2 try to purchase tickets

        if(coinToss==0){ //Handling case where guest will try to purchase all day ride pass

          if(purchaseAllDayRidePassForGuest(&funFair,&allGuests[i])==0){ //Handling the case where guest could not purchase an all day ride pass

            int currentNumberOfTicketsGuestWantsToPurchase = NUMBER_OF_TICKETS_WHEN_GUEST_CANT_BUY_ALL_DAY_RIDE_PASS;


            if(purchaseRideTicketsForGuest(&funFair,&allGuests[i],currentNumberOfTicketsGuestWantsToPurchase)==0){


              int theUpdatedNumberOfTicketsGuestWantsToPurchase  = currentNumberOfTicketsGuestWantsToPurchase;

              while(purchaseRideTicketsForGuest(&funFair,&allGuests[i],theUpdatedNumberOfTicketsGuestWantsToPurchase)==0){

                if(theUpdatedNumberOfTicketsGuestWantsToPurchase==5 || theUpdatedNumberOfTicketsGuestWantsToPurchase==4 || theUpdatedNumberOfTicketsGuestWantsToPurchase==3 || theUpdatedNumberOfTicketsGuestWantsToPurchase==2){

                  theUpdatedNumberOfTicketsGuestWantsToPurchase=1; //Making sure guest attempts to purchase at least 1 ticket

                }
                else if(theUpdatedNumberOfTicketsGuestWantsToPurchase>5)
                    {

                    theUpdatedNumberOfTicketsGuestWantsToPurchase = theUpdatedNumberOfTicketsGuestWantsToPurchase-5; //Making sure to reduce theUpdatedNumberOfTicketsGuestWantsToPurchase by 5 when they could not afford purchasing the previous number of tickets

                }
                else
                {
                    break;
                }

              }


            }
            else{
              //Case where they were able to purchase the value of currentNumberOfTicketsGuestWantsToPurchase tickets, so we did not need to call the function again as it is already called

            }

          }

        }
        else{ //Handling case where guest is trying to purchase ride tickets

          int theNumberOfTicketsTheGuestWantsToPurchase = initializeRandomValue(10,40);
          while(theNumberOfTicketsTheGuestWantsToPurchase%5!=0){
            theNumberOfTicketsTheGuestWantsToPurchase=initializeRandomValue(10,40);
          }

          if(purchaseRideTicketsForGuest(&funFair,&allGuests[i],theNumberOfTicketsTheGuestWantsToPurchase)==0){ //Handling case where guest could not purchase the calculated value of ride tickets

            int updatedNumberOfTicketsGuestWantsToPurchase=theNumberOfTicketsTheGuestWantsToPurchase;
            while(purchaseRideTicketsForGuest(&funFair,&allGuests[i],updatedNumberOfTicketsGuestWantsToPurchase)==0){

              if(updatedNumberOfTicketsGuestWantsToPurchase==5 || updatedNumberOfTicketsGuestWantsToPurchase==4 || updatedNumberOfTicketsGuestWantsToPurchase==3 || updatedNumberOfTicketsGuestWantsToPurchase==2){

                updatedNumberOfTicketsGuestWantsToPurchase=1; //Making sure guest attempts to purchase at least 1 ticket
              }
              else if(updatedNumberOfTicketsGuestWantsToPurchase>5){


                  updatedNumberOfTicketsGuestWantsToPurchase = updatedNumberOfTicketsGuestWantsToPurchase-5; //Making sure to reduce updatedNumberOfTicketsGuestWantsToPurchase by 5 when they could not afford purchasing the previous number of tickets

              }

              else
              {
                 break;
              }

            }

          }
          else{

            //Case where they were able to purchase the value of theNumberOfTicketsTheGuestWantsToPurchase tickets, so we did not need to call the function again as it is already called


          }


        }


      }


    }


    for(int j=0; j<MAX_GUESTS; j++){

      int repeatingRideProcess20Times=0;      //Variable to make sure that the guests attempt to go on at exactly 20 rides
      while(repeatingRideProcess20Times<20){

        if(allGuests[j].age<=12){ //Handling the case where the guest has age less than or equal to 12

          int randomIndexValueForFirstFiveRidesInRideArray = initializeRandomValue(0,4);                          //Variable to select random index value of for the first 5 rides in the array as required in the specification
          guestAttemptsToGoOnRide(&allGuests[j],&funFair.allRides[randomIndexValueForFirstFiveRidesInRideArray]); //Calling guestAttemptsToGoOnRide function to make guest attemp to go on the specific ride

        }
        else{ //Handling the case where the guest is older than 12 years


          int randomIndexValueForLastFiveRidesInRideArray = initializeRandomValue(5,9);                           //Variable to select random index value of for the last 5 rides in the array as required in the specification
          guestAttemptsToGoOnRide(&allGuests[j],&funFair.allRides[randomIndexValueForLastFiveRidesInRideArray]);  //Calling guestAttemptsToGoOnRide function to make guest attemp to go on the specific ride

        }
        repeatingRideProcess20Times++; //Increment this value to make sure above while loop works 20 times

      }


    }

    //Printing final output as specified in assignment after guests have their height, money, tickets and have attempted to go on rides
    for(int k=0; k<MAX_GUESTS; k++){

      printf("Guest #%3d,  Age:%4d,  Height:  %dcm,  Money:  $%6.2f,  Tickets:",k, allGuests[k].age, allGuests[k].heightInCm, allGuests[k].totalMoneyOnGuest);
      if(allGuests[k].allDayRidePassOnGuest==1){
        printf("PASS,");
      }
      else{

        printf("%4d,",allGuests[k].totalNumberOfTicketsOnGuest);

      }

      printf("  Rides:%4d\n",allGuests[k].totalRidesGuestRode);


    }

    printf("\n");
    printf("\n");

    printf("Here are the fair results:\n"); //Printing the fair reusults below as specified in the assignment for the total money made in the fair, and all day ride passes and tickets not sold
    printf("\n");

    int totalNumberOfRidePassesNotSold = STARTING_AVAILABLE_ALL_DAY_RIDE_PASSES - funFair.theTicketBooth.allDayRidePassesSold;
    int totalNumberOfRideTicketsNotSold = STARTING_AVAILABLE_TICKETS - funFair.theTicketBooth.rideTicketsSold;

    printf("$%6.2f has been earned. %d passes and %d tickets were not sold\n", funFair.theTicketBooth.totalMoneyMade, totalNumberOfRidePassesNotSold, totalNumberOfRideTicketsNotSold);

    printf("\n");
    printf("Here are the ride statistics: \n");
    printf("\n");

    for(int l=0; l<TOTAL_NUMBER_OF_RIDES_AT_FAIR; l++){ //Presenting details of the rides as specified in the specification

      printf("%14s allowed %3d guests on but turned away %3d guests\n",funFair.allRides[l].rideName,funFair.allRides[l].totalNumberOfRiders,funFair.allRides[l].numberOfGuestsDeniedForHeightRequirement);

    }


}


int initializeRideInArray(Fair* theFair,char theName[],int theNumberOfTicketsRequired,int theHeightRequiredInCm, int theIndexValue){

  if(theIndexValue>TOTAL_NUMBER_OF_RIDES_AT_FAIR){ //Checking if theIndexValue is a invalid number
    return 0;
  }
  else{ //Handling the case where theIndexValue is a valid number

    strcpy(theFair->allRides[theIndexValue].rideName, theName);
    theFair->allRides[theIndexValue].numberOfTicketsRequired = theNumberOfTicketsRequired;
    theFair->allRides[theIndexValue].heightRequirementInCm = theHeightRequiredInCm;
    return 1;

  }


}


int calculateAgeValueOfGuest(int indexValueInGuestArray){

  if(indexValueInGuestArray < MAX_GUESTS/2){ //Handling the case where 1/2 of guests have age in rage 13 to 19

    int ageValue1 = initializeRandomValue(13,19);
    return ageValue1;

  }
  else if((MAX_GUESTS*0.5 < indexValueInGuestArray)  && (indexValueInGuestArray < 0.75*MAX_GUESTS)){ //Handling the case where 1/4 of guests have age in rage 5 to 12

    int ageValue2 = initializeRandomValue(5,12);
    return ageValue2;

  }

  else{ //Handling the case where 1/4 of guests have age in rage 20 to 65

    int ageValue3 = initializeRandomValue(20,65);
    return ageValue3;

  }



}




  int initializeRandomValue(int theLowerEndValue,int theUpperEndValue){

    int theRandomValue=0;

    theRandomValue = (rand() % (theUpperEndValue - theLowerEndValue + 1) + theLowerEndValue); //Generating a random value in range of the parameters inclusively

    return theRandomValue;

  }


  void calculateMoneyOnGuest(Guest* theGuest){

    int totalMoney=0;

    int randomValue = initializeRandomValue(20,28);


    while(randomValue%2!=0){

      randomValue = initializeRandomValue(20,28); //Updating the randomValue which is the starting amount of money guest has by making sure it is divisible by 2


    }

      totalMoney = randomValue;

      if(theGuest->age>=10){  //Handling the case where the guest age is greater than or equal to 10

        int numberOfDecades = floor(theGuest->age/10);

        int moneyToMultiplyWithDecades=initializeRandomValue(20,45);


        while(moneyToMultiplyWithDecades%5!=0){

          moneyToMultiplyWithDecades=initializeRandomValue(20,45); //Updating the moneyToMultiplyWithDecades which is value we will multiply with number of decades with by making sure it is divisible by 5

        }


        totalMoney += numberOfDecades * moneyToMultiplyWithDecades; //Set totalMoney to the value of numberOfDecades multiplied by moneyToMultiplyWithDecades
        theGuest->totalMoneyOnGuest = (float)totalMoney;  //Set guests money to totalMoney variable


      }
      else{ //Handling the case where the guest age is less than 10

        theGuest->totalMoneyOnGuest = (float)totalMoney;

      }


  }


  void calculateHeightOnGuest(Guest* theGuest){

    int heightOfGuest=0;

    if(theGuest->age<=12){  //Handling the case where the guest age is less than or equal to 12

      int valueToMultiplyAgeWith = initializeRandomValue(72,81);

      heightOfGuest = valueToMultiplyAgeWith + (theGuest->age * 6);

      theGuest->heightInCm = heightOfGuest;


    }
    else{ //Handling the case where the guest age is greater than 12

      heightOfGuest = initializeRandomValue(149,280);
      theGuest->heightInCm = heightOfGuest;

    }

  }


  int admitGuestToFair(Fair* theFair,Guest* theGuest){

    if(theGuest->age >= 13 && theGuest->totalMoneyOnGuest>=PRICE_OF_ADMISSION_ABOVE_13){  //Handling case where guest age is greater than or equal to 13

      theGuest->totalMoneyOnGuest-=PRICE_OF_ADMISSION_ABOVE_13;
      theFair->theTicketBooth.totalMoneyMade+=PRICE_OF_ADMISSION_ABOVE_13;

      return 1;

    }
    else if((theGuest->age > 6) && (theGuest->age < 13) && theGuest->totalMoneyOnGuest>=PRICE_OF_ADMISSION_FOR_6_TO_13){ //Handling case where guest age is greater than 6 and less than 13

      theGuest->totalMoneyOnGuest-=PRICE_OF_ADMISSION_FOR_6_TO_13;
      theFair->theTicketBooth.totalMoneyMade+=PRICE_OF_ADMISSION_FOR_6_TO_13;

      return 1;

    }
    else if(theGuest->age <= 6 && theGuest->totalMoneyOnGuest>=PRICE_OF_ADMISSION_FOR_UNDER_6){ //Handling the case where guest age is less than or equal to 6

      theGuest->totalMoneyOnGuest-=PRICE_OF_ADMISSION_FOR_UNDER_6;
      theFair->theTicketBooth.totalMoneyMade+=PRICE_OF_ADMISSION_FOR_UNDER_6;

      return 1;

    }
    else{

      //Handling the case where guest could not pay for the admission

      return 0;

    }

  }



  int purchaseRideTicketsForGuest(Fair* theFair,Guest* theGuest,int numberOfTicketsRequestedToBePurchased){


    int currentNumberOfTicketsAvailable = STARTING_AVAILABLE_TICKETS - theFair->theTicketBooth.rideTicketsSold;

    if(currentNumberOfTicketsAvailable < numberOfTicketsRequestedToBePurchased){ //Handling the case where there are not enough tickets to sell to the guest

      return 0;

    }
    else{ //Handling the case where there are enough tickets to sell to the guest

      float totalPriceOfTicketPurchase = COST_OF_SINGLE_RIDE_TICKET * numberOfTicketsRequestedToBePurchased;

      if(totalPriceOfTicketPurchase <= theGuest->totalMoneyOnGuest){  //Handling the case where the guest can afford the total price of tickets they requested to purchase

        theFair->theTicketBooth.rideTicketsSold+=numberOfTicketsRequestedToBePurchased;
        theFair->theTicketBooth.totalMoneyMade += totalPriceOfTicketPurchase;

        theGuest->totalMoneyOnGuest-=totalPriceOfTicketPurchase;
        theGuest->totalNumberOfTicketsOnGuest += numberOfTicketsRequestedToBePurchased;

        return 1;


      }
      else{ //Handling the case where the guest could not pay for the tickets they requested to purchase

        return 0;

      }

    }

  }


  int purchaseAllDayRidePassForGuest(Fair* theFair,Guest* theGuest){

    int currentNumberOfAllDayRidePassesAvailable = STARTING_AVAILABLE_ALL_DAY_RIDE_PASSES - theFair->theTicketBooth.allDayRidePassesSold;

    if(currentNumberOfAllDayRidePassesAvailable==0){ //Handling the case where there are not enough all day ride passes to sell to the guest

      theGuest->allDayRidePassOnGuest=0;
      return 0;

    }
    else{ //Handling the case where there are enough all day ride passes to sell to the guest

      if(theGuest->totalMoneyOnGuest >= COST_OF_ALL_DAY_RIDE_PASS){ //Handling the case where the guest can afford the total price of the all day ride pass

        theFair->theTicketBooth.allDayRidePassesSold++;
        theFair->theTicketBooth.totalMoneyMade+=COST_OF_ALL_DAY_RIDE_PASS;
        theGuest->totalMoneyOnGuest-=COST_OF_ALL_DAY_RIDE_PASS;
        theGuest->allDayRidePassOnGuest=1;

        return 1;

      }
      else{ //Handling the case where the guest could not pay for the all day ride pass

        theGuest->allDayRidePassOnGuest=0;
        return 0;

      }


    }


  }



  int guestAttemptsToGoOnRide(Guest* theGuest, Ride* theRide){

    if(theGuest->heightInCm >= theRide->heightRequirementInCm){ //Checking the guest passes the height requirement for the ride

      if(theGuest->allDayRidePassOnGuest==1){ //Handling the case where the guest has an all day ride pass

        theRide->totalNumberOfRiders++;
        theGuest->totalRidesGuestRode++;

        return 1;
      }
      if(theGuest->totalNumberOfTicketsOnGuest>=theRide->numberOfTicketsRequired){  //Handling the case where the guest has enough tickets to get on the ride

        theRide->totalNumberOfRiders++;
        theGuest->totalNumberOfTicketsOnGuest-=theRide->numberOfTicketsRequired;
        theGuest->totalRidesGuestRode++;

        return 1;
      }
      else{ //Handling the case where the guest did not have an all day ride pass nor did they have enough ride tickets to get on the ride

        return 0;

      }


    }
    else{ //Handling the case where the guest could not get on the ride due to not meeting the height requirement

      theRide->numberOfGuestsDeniedForHeightRequirement++;
      return 0;

    }



  }
