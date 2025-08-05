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

  unsigned short rideTicketsSold;
  unsigned short allDayRidePassesSold;
  float totalMoneyMade;

} TicketBooth;

typedef struct Ride {

  char rideName[MAX_CHARACTERS];
  unsigned char numberOfTicketsRequired; //particular data type for values betwee 1-5 (unsigned int?)
  unsigned short heightRequirementInCm;
  unsigned short totalNumberOfRiders;
  unsigned short numberOfGuestsDeniedForHeightRequirement;

} Ride;

typedef struct Guest {

  unsigned char age;
  unsigned short heightInCm;
  float totalMoneyOnGuest; //ORIGINALLY THIS WAS OF TYPE INT
  unsigned short totalNumberOfTicketsOnGuest; //set to 0 at start
  unsigned char allDayRidePassOnGuest; //1 if true 0 if false
  unsigned char totalRidesGuestRode;

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
int guestAttemptsToGoOnRide(Guest*, Ride*);




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
    initializeRideInArray(&funFair,"Ferris Wheel",4,110,indexValueOfRideInArray);
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
    for(int x=0; x<TOTAL_NUMBER_OF_RIDES_AT_FAIR; x++){

      funFair.allRides[x].totalNumberOfRiders=0;
      funFair.allRides[x].numberOfGuestsDeniedForHeightRequirement=0;


    }


    Guest allGuests[MAX_GUESTS];
    for(int i=0; i<MAX_GUESTS; i++){

      allGuests[i].age=0;
      allGuests[i].heightInCm=0;
      allGuests[i].totalMoneyOnGuest=0.00;
      allGuests[i].totalNumberOfTicketsOnGuest=0;
      allGuests[i].allDayRidePassOnGuest=0;
      allGuests[i].totalRidesGuestRode=0;


      int ageValueOfTheGuest = calculateAgeValueOfGuest(i);
      allGuests[i].age = ageValueOfTheGuest;
      calculateMoneyOnGuest(&allGuests[i]);
      calculateHeightOnGuest(&allGuests[i]);

      if(admitGuestToFair(&funFair,&allGuests[i]) == 0){

        allGuests[i].totalNumberOfTicketsOnGuest=0;
        allGuests[i].allDayRidePassOnGuest=0;

      }
      else{

        if(i<=MAX_GUESTS/2){

          if(purchaseAllDayRidePassForGuest(&funFair,&allGuests[i])==0){

            //printf("THE GUEST COULD NOT PURCHASE AN ALL DAY RIDE PASS\n"); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
            int currentNumberOfTicketsGuestWantsToPurchase = NUMBER_OF_TICKETS_WHEN_GUEST_CANT_BUY_ALL_DAY_RIDE_PASS;


            if(purchaseRideTicketsForGuest(&funFair,&allGuests[i],currentNumberOfTicketsGuestWantsToPurchase)==0){

              int theUpdatedNumberOfTicketsGuestWantsToPurchase = currentNumberOfTicketsGuestWantsToPurchase-5;
              while(purchaseRideTicketsForGuest(&funFair,&allGuests[i],theUpdatedNumberOfTicketsGuestWantsToPurchase)==0){
                //THE ERROR IS BELOW, I DONT KNOW HOW TO SET THE VALUE TO SET THE VALUE OF updatedNumberOfTicketsGuestWantsToPurchase TO 1 WHEN THE VALYE OF updatedNumberOfTicketsGuestWantsToPurchase IS 5 OR UNDER
                //AND THEN I AM TRYING TO PURCHASE 1 TICKET BUT IT DOESNT WORK AS THE VALUE OF updatedNumberOfTicketsGuestWantsToPurchase ENDS UP GOING BELOW 1 AND CHANGES TO HIGHER NUMBERS
                //NOTE THAT I HAVE CHANGED THE DATA TYPES OF TYPEDEF ATTRIBUTES TO MAKE THEM MINIMUM SIZE, SUCH AS "unsigned short" SO THIS IS THE ERROR

                printf("THE VALUE WE GOING TO SEND TO THE PURCHASE RIDE TICKET FUNCTION PART 1 IS: %3d AND THE INDEX VALUE IS %3d AND TOTAL MONEY ON THE GUEST IS $%.2f\n", theUpdatedNumberOfTicketsGuestWantsToPurchase,i,allGuests[i].totalMoneyOnGuest);
                /*if(theUpdatedNumberOfTicketsGuestWantsToPurchase==1){
                  printf("THE VALUE INSIDE THE CHECKING OF 1 IS %d\n",theUpdatedNumberOfTicketsGuestWantsToPurchase);

                  //purchaseRideTicketsForGuest(&funFair,&allGuests[i],theUpdatedNumberOfTicketsGuestWantsToPurchase);

                  continue;

                }*/

                //float totalPriceOfTheTicketsGuestWantsToPurchase = updatedNumberOfTicketsGuestWantsToPurchase*COST_OF_SINGLE_RIDE_TICKET;
                //printf("THE GUEST COULD NOT PURCHASE %d TICKETS AS IT COSTS $%.2f AND THE GUEST HAS A TOTAL OF $%.2f\n",updatedNumberOfTicketsGuestWantsToPurchase,totalPriceOfTheTicketsGuestWantsToPurchase,allGuests[i].totalMoneyOnGuest); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
                if(theUpdatedNumberOfTicketsGuestWantsToPurchase==5 || theUpdatedNumberOfTicketsGuestWantsToPurchase==4 || theUpdatedNumberOfTicketsGuestWantsToPurchase==3 || theUpdatedNumberOfTicketsGuestWantsToPurchase==2){
                  //printf("HERE WE ARE CHECKING IF THEY CAN EVEN BUY 1 TICKET:\n"); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
                  theUpdatedNumberOfTicketsGuestWantsToPurchase=1; // PART 4 CHECKING IF THEY CAN EVEN PURCHASE 1 TICKET IN CASE THE VALUE OF updateIS GOING TO GO LOWER THAN 5
                  printf("DEBUG 4\n");
                }
                else{

                  //while(theUpdatedNumberOfTicketsGuestWantsToPurchase>5){

                    theUpdatedNumberOfTicketsGuestWantsToPurchase = theUpdatedNumberOfTicketsGuestWantsToPurchase-5;


                  //}
                  printf("DEBUG 5\n");

                }

              }


            }
            else{
              printf("DEBUG 6\n");
              //purchaseRideTicketsForGuest(&funFair,&allGuests[i],currentNumberOfTicketsGuestWantsToPurchase);

            }




          }



        }
        else{

          //printf("\n");WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
          //printf("HERE WE WILL BE PURCHASING THE TICKETS\n");WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
          int theNumberOfTicketsTheGuestWantsToPurchase = initializeRandomValue(10,40);
          while(theNumberOfTicketsTheGuestWantsToPurchase%5!=0){
            theNumberOfTicketsTheGuestWantsToPurchase=initializeRandomValue(10,40);
          }

          if(purchaseRideTicketsForGuest(&funFair,&allGuests[i],theNumberOfTicketsTheGuestWantsToPurchase)==0){
            //printf("CHECKING THE CASE WHERE THEY COULD NOT BUY THE NUMBER OF TICKETS THEY WANTED %d TICKETS\n",theNumberOfTicketsTheGuestWantsToPurchase); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT

            int updatedNumberOfTicketsGuestWantsToPurchase=theNumberOfTicketsTheGuestWantsToPurchase-5;
            while(purchaseRideTicketsForGuest(&funFair,&allGuests[i],updatedNumberOfTicketsGuestWantsToPurchase)==0){
              //THE ERROR IS BELOW, I DONT KNOW HOW TO SET THE VALUE TO SET THE VALUE OF updatedNumberOfTicketsGuestWantsToPurchase TO 1 WHEN THE VALYE OF updatedNumberOfTicketsGuestWantsToPurchase IS 5 OR UNDER
              //AND THEN I AM TRYING TO PURCHASE 1 TICKET BUT IT DOESNT WORK AS THE VALUE OF updatedNumberOfTicketsGuestWantsToPurchase ENDS UP GOING BELOW 1 AND CHANGES TO HIGHER NUMBERS
              //NOTE THAT I HAVE CHANGED THE DATA TYPES OF TYPEDEF ATTRIBUTES TO MAKE THEM MINIMUM SIZE, SUCH AS "unsigned short" SO THIS IS THE ERROR
              printf("THE VALUE WE GOING TO SEND TO THE PURCHASE RIDE TICKET FUNCTION PART 2 IS: %3d AND THE INDEX VALUE IS %3d AND THE TOTAL MONEY ON THE GUEST IS $%.2f\n", updatedNumberOfTicketsGuestWantsToPurchase,i,allGuests[i].totalMoneyOnGuest);

              /*if(updatedNumberOfTicketsGuestWantsToPurchase==1){
                printf("THE VALUE INSIDE THE CHECKING OF 1 IS %d\n",updatedNumberOfTicketsGuestWantsToPurchase );
                //purchaseRideTicketsForGuest(&funFair,&allGuests[i],updatedNumberOfTicketsGuestWantsToPurchase);

                continue;
              }*/
              //float totalPriceOfTheTicketsGuestWantsToPurchase = updatedNumberOfTicketsGuestWantsToPurchase*COST_OF_SINGLE_RIDE_TICKET;
              //printf("THE GUEST COULD NOT PURCHASE %d TICKETS AS IT COSTS $%.2f AND THE GUEST HAS A TOTAL OF $%.2f\n",updatedNumberOfTicketsGuestWantsToPurchase,totalPriceOfTheTicketsGuestWantsToPurchase,allGuests[i].totalMoneyOnGuest); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
              if(updatedNumberOfTicketsGuestWantsToPurchase==5 || updatedNumberOfTicketsGuestWantsToPurchase==4 || updatedNumberOfTicketsGuestWantsToPurchase==3 || updatedNumberOfTicketsGuestWantsToPurchase==2){
                //printf("HERE WE ARE CHECKING IF THEY CAN EVEN BUY 1 TICKET:\n"); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
                updatedNumberOfTicketsGuestWantsToPurchase=1; // PART 4 CHECKING IF THEY CAN EVEN PURCHASE 1 TICKET IN CASE THE VALUE OF updateIS GOING TO GO LOWER THAN 5
                printf("DEBUG 1\n");
              }
              else{

                //while(updatedNumberOfTicketsGuestWantsToPurchase>5){

                  updatedNumberOfTicketsGuestWantsToPurchase = updatedNumberOfTicketsGuestWantsToPurchase-5;


              //  }
                printf("DEBUG 2\n");


              }

            }

          }
          else{
            //printf("CHECKING THE CASE WHERE THEY COULD BUY THE NUMBER OF TICKETS THEY WANTED %d TICKETS\n",theNumberOfTicketsTheGuestWantsToPurchase); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
            printf("DEBUG 3\n");
            //purchaseRideTicketsForGuest(&funFair,&allGuests[i],theNumberOfTicketsTheGuestWantsToPurchase);
          }




        }



      }






    }

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




    for(int j=0; j<MAX_GUESTS; j++){


      /*printf("\n");
      printf("BEFORE.....\n");
      printf("THE GUESTS AGE IS %d AND THEIR INDEX VALUE IN THE GUEST ARRAY IS %d\n",allGuests[j].age,j);
      printf("THE TOTAL AMOUNT OF MONEY ON GUEST IS $%.2f\n",allGuests[j].totalMoneyOnGuest);
      printf("THE GUESTS HEIGHT IN cm IS %d\n",allGuests[j].heightInCm);
      printf("THE TOTAL NUMBER OF TICKETS GUEST HAS IS %d\n",allGuests[j].totalNumberOfTicketsOnGuest);
      printf("THE GUEST HAS AN ALL DAY RIDE PASS VALUE OF %d\n",allGuests[j].allDayRidePassOnGuest);
      printf("THE TOTAL NUMBER OF RIDES THE GUEST RODE IS %d\n",allGuests[j].totalRidesGuestRode);
      printf("\n");*/ //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
      int repeatingRideProcess20Times=0;
      while(repeatingRideProcess20Times<20){

        if(allGuests[j].age<=12){
          //printf("CHECKING IF GUESTS LESS THAN THE AGE OF 12 CAN GO ON RIDE\n"); //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
          //printf("ALSO THIS REPEATING PROCESS 20 TIME COUNTER IS AT: %d\n",repeatingRideProcess20Times); //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
          int randomIndexValueForFirstFiveRidesInRideArray = initializeRandomValue(0,4);
          guestAttemptsToGoOnRide(&allGuests[j],&funFair.allRides[randomIndexValueForFirstFiveRidesInRideArray]);

        }
        else{
          //printf("CHECKING IF GUESTS OVER THE AGE OF 12 CAN GO ON RIDE\n"); //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
          //printf("ALSO THIS REPEATING PROCESS 20 TIME COUNTER IS AT: %d\n",repeatingRideProcess20Times); //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT

          int randomIndexValueForLastFiveRidesInRideArray = initializeRandomValue(5,9);
          guestAttemptsToGoOnRide(&allGuests[j],&funFair.allRides[randomIndexValueForLastFiveRidesInRideArray]);

        }
        repeatingRideProcess20Times++;

      }


      /*printf("\n");
      printf("AFTER.....\n");
      printf("THE GUESTS AGE IS %d AND THEIR INDEX VALUE IN THE GUEST ARRAY IS %d\n",allGuests[j].age,j);
      printf("THE TOTAL AMOUNT OF MONEY ON GUEST IS $%.2f\n",allGuests[j].totalMoneyOnGuest);
      printf("THE GUESTS HEIGHT IN cm IS %d\n",allGuests[j].heightInCm);
      printf("THE TOTAL NUMBER OF TICKETS GUEST HAS IS %d\n",allGuests[j].totalNumberOfTicketsOnGuest);
      printf("THE GUEST HAS AN ALL DAY RIDE PASS VALUE OF %d\n",allGuests[j].allDayRidePassOnGuest);
      printf("THE TOTAL NUMBER OF RIDES THE GUEST RODE IS %d\n",allGuests[j].totalRidesGuestRode);
      printf("\n");*/ //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT


    }

    /*for(int k=0; k<MAX_GUESTS; k++){

      printf("Guest #%3d,  Age:%4d,  Height:  %dcm,  Money:  $%6.2f,  Tickets:",k, allGuests[k].age, allGuests[k].heightInCm, allGuests[k].totalMoneyOnGuest);
      if(allGuests[k].allDayRidePassOnGuest==1){
        printf("PASS,");
      }
      else{

        printf("%4d,",allGuests[k].totalNumberOfTicketsOnGuest);

      }

      printf("  Rides:%4d\n",allGuests[k].totalRidesGuestRode);


    }*/

    printf("\n");
    printf("\n");

    printf("Here are the fair results:\n");
    printf("\n");

    int totalNumberOfRidePassesNotSold = STARTING_AVAILABLE_ALL_DAY_RIDE_PASSES - funFair.theTicketBooth.allDayRidePassesSold;
    int totalNumberOfRideTicketsNotSold = STARTING_AVAILABLE_TICKETS - funFair.theTicketBooth.rideTicketsSold;

    printf("$%6.2f has been earned. %d passes and %d tickets were not sold\n", funFair.theTicketBooth.totalMoneyMade, totalNumberOfRidePassesNotSold, totalNumberOfRideTicketsNotSold);

    printf("\n");
    printf("Here are the ride statistics: \n");
    printf("\n");

    for(int l=0; l<TOTAL_NUMBER_OF_RIDES_AT_FAIR; l++){

      printf("%14s allowed %3d guests on but turned away %3d guests\n",funFair.allRides[l].rideName,funFair.allRides[l].totalNumberOfRiders,funFair.allRides[l].numberOfGuestsDeniedForHeightRequirement);

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
    //printf("THE AGE FOUND FOR FIRST HALF OF GUEST IS %d\n",ageValue1 ); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
    return ageValue1;


  }
  else if((MAX_GUESTS*0.5 < indexValueInGuestArray)  && (indexValueInGuestArray < 0.75*MAX_GUESTS)){

    int ageValue2 = initializeRandomValue(5,12);
    //printf("THE AGE FOUND FOR THIRD QUARTER OF GUEST IS %d\n",ageValue2 ); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT

    return ageValue2;



  }

  else{

    int ageValue3 = initializeRandomValue(20,65);
    //printf("THE AGE FOUND FOR LAST QUARTER OF GUEST IS %d\n",ageValue3); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT

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

      //printf("SUCCESSFULLY ADMITTED THE GUEST WHO HAS A AGE RANGE OF >= 13 \n"); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
      theGuest->totalMoneyOnGuest-=PRICE_OF_ADMISSION_ABOVE_13;
      theFair->theTicketBooth.totalMoneyMade+=PRICE_OF_ADMISSION_ABOVE_13;

      return 1;

    }
    else if((theGuest->age > 6) && (theGuest->age < 13) && theGuest->totalMoneyOnGuest>=PRICE_OF_ADMISSION_FOR_6_TO_13){

      //printf("SUCCESSFULLY ADMITTED THE GUEST WHO HAS A AGE RANGE OF > 6 AND < 13 \n"); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
      theGuest->totalMoneyOnGuest-=PRICE_OF_ADMISSION_FOR_6_TO_13;
      theFair->theTicketBooth.totalMoneyMade+=PRICE_OF_ADMISSION_FOR_6_TO_13;


      return 1;


    }
    else if(theGuest->age <= 6 && theGuest->totalMoneyOnGuest>=PRICE_OF_ADMISSION_FOR_UNDER_6){

      //printf("SUCCESSFULLY ADMITTED THE GUEST WHO HAS A AGE RANGE OF < 6\n"); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
      theGuest->totalMoneyOnGuest-=PRICE_OF_ADMISSION_FOR_UNDER_6;
      theFair->theTicketBooth.totalMoneyMade+=PRICE_OF_ADMISSION_FOR_UNDER_6;

      return 1;

    }
    else{

      //printf("DID NOT ADMIT GUEST OF AGE %d BECAUSE THEY ONLY HAD $%.2f!\n",theGuest->age,theGuest->totalMoneyOnGuest); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT

      return 0;

    }

  }



  int purchaseRideTicketsForGuest(Fair* theFair,Guest* theGuest,int numberOfTicketsRequestedToBePurchased){


    int currentNumberOfTicketsAvailable = STARTING_AVAILABLE_TICKETS - theFair->theTicketBooth.rideTicketsSold;

    printf("THE CURRENT NUNBER OF TICKETS AVAILABLE IS %d AND THE NUMBER OF TICKETS REQUESTED IS %d\n",currentNumberOfTicketsAvailable,numberOfTicketsRequestedToBePurchased);

    if(currentNumberOfTicketsAvailable < numberOfTicketsRequestedToBePurchased){

      //printf("NOT ENOUGH TICKETS TO BE GIVEN TO THE GUEST BECAUSE THEY ARE ASKING FOR %d AND THERE ARE ONLY %d TICKETS AVAILABLE\n",numberOfTicketsRequestedToBePurchased,currentNumberOfTicketsAvailable); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
      return 0;

    }
    else{

      float totalPriceOfTicketPurchase = COST_OF_SINGLE_RIDE_TICKET * numberOfTicketsRequestedToBePurchased;

      if(totalPriceOfTicketPurchase <= theGuest->totalMoneyOnGuest){

        /*printf("\n");
        printf("PURCHASE OF %d RIDE TICKETS WAS SUCCESSFUL BECAUSE THE TOTAL PRICE WAS $%.2f AND THE GUEST HAD A TOTAL OF $%.2f! \n",numberOfTicketsRequestedToBePurchased,totalPriceOfTicketPurchase,theGuest->totalMoneyOnGuest);
        printf("\n");

        printf("ORIGINAL AMOUNT OF NUMBER OF TICKETS SOLD %d\n", theFair->theTicketBooth.rideTicketsSold);
        printf("ORIGINAL AMOUNT OF MONEY FAIR HAS IS $%.2f\n", theFair->theTicketBooth.totalMoneyMade);
        printf("ORIGINAL AMOUNT OF MONEY THE GUEST HAS IS $%.2f\n", theGuest->totalMoneyOnGuest);*/ //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT


        theFair->theTicketBooth.rideTicketsSold+=numberOfTicketsRequestedToBePurchased;
        theFair->theTicketBooth.totalMoneyMade += totalPriceOfTicketPurchase;

        theGuest->totalMoneyOnGuest-=totalPriceOfTicketPurchase;
        theGuest->totalNumberOfTicketsOnGuest += numberOfTicketsRequestedToBePurchased;

        /*printf("WE ARE CHECKING THE CURRENT VALUES OF EVERYTHING CHANGED AFTER BUYING RIDE TICKETS:\n");
        printf("THE TOTAL NUMBER OF RIDE TICKETS SOLD IS %d\n",theFair->theTicketBooth.rideTicketsSold);
        printf("THE TOTAL AMOUNT OF MONEY MADE FROM SELLING RIDE TICKETS IS $%.2f\n",theFair->theTicketBooth.totalMoneyMade);
        printf("THE CURRENT AMOUNT OF MONEY ON THE GUEST IS $%.2f\n",theGuest->totalMoneyOnGuest);*/ //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT


        return 1;


      }
      else{

        //printf("PURCHASE OF RIDE TICKETS WAS NOT SUCCESSFUL BECAUSE THE TOTAL PRICE WAS $%.2f AND THE GUEST HAD A TOTAL OF $%.2f! \n",totalPriceOfTicketPurchase,theGuest->totalMoneyOnGuest); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
        return 0;


      }



    }


  }


  int purchaseAllDayRidePassForGuest(Fair* theFair,Guest* theGuest){

    int currentNumberOfAllDayRidePassesAvailable = STARTING_AVAILABLE_ALL_DAY_RIDE_PASSES - theFair->theTicketBooth.allDayRidePassesSold;

    if(currentNumberOfAllDayRidePassesAvailable==0){

      //printf("THERE ARE NO ALL DAY RIDE PASSES AVAILABLE AS THE CURRENT NUMBER OF RIDE PASSES AVAILABLE IS %d\n",currentNumberOfAllDayRidePassesAvailable); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
      theGuest->allDayRidePassOnGuest=0;
      return 0;

    }
    else{

      if(theGuest->totalMoneyOnGuest >= COST_OF_ALL_DAY_RIDE_PASS){

        /*printf("\n");
        printf("PURCHASE OF ALL DAY RIDE PASS WAS SUCCESSFUL AS THE PRICE OF ALL DAY RIDE PASS IS $%.2f AND THE CURRENT AMOUNT OF MONEY ON THE GUEST IS $%.2f\n",COST_OF_ALL_DAY_RIDE_PASS,theGuest->totalMoneyOnGuest);
        printf("\n");

        printf("ORIGINAL AMOUNT OF ALL DAY RIDE PASSES SOLD %d\n", theFair->theTicketBooth.allDayRidePassesSold);
        printf("ORIGINAL AMOUNT OF MONEY FAIR HAS IS $%.2f\n", theFair->theTicketBooth.totalMoneyMade);
        printf("ORIGINAL AMOUNT OF MONEY THE GUEST HAS IS $%.2f\n", theGuest->totalMoneyOnGuest);*/ //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT

        theFair->theTicketBooth.allDayRidePassesSold++;
        theFair->theTicketBooth.totalMoneyMade+=COST_OF_ALL_DAY_RIDE_PASS;
        theGuest->totalMoneyOnGuest-=COST_OF_ALL_DAY_RIDE_PASS;
        theGuest->allDayRidePassOnGuest=1;


        /*printf("WE ARE CHECKING THE CURRENT VALUES OF EVERYTHING CHANGED AFTER BUYING AN ALL DAY RIDE PASS:\n");
        printf("THE TOTAL NUMBER OF ALL DAY RIDE PASSES SOLD IS %d\n",theFair->theTicketBooth.allDayRidePassesSold);
        printf("THE TOTAL AMOUNT OF MONEY MADE FROM SELLING ALL DAY RIDE PASSES IS $%.2f\n",theFair->theTicketBooth.totalMoneyMade);
        printf("THE CURRENT AMOUNT OF MONEY ON THE GUEST IS $%.2f\n",theGuest->totalMoneyOnGuest);*/ //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT

        return 1;


      }
      else{

        //printf("PURCHASE OF ALL DAY RIDE PASS WAS NOT SUCCESSFUL BECAUSE THE TOTAL PRICE WAS $%.2f AND THE GUEST HAD A TOTAL OF $%.2f! \n",COST_OF_ALL_DAY_RIDE_PASS,theGuest->totalMoneyOnGuest); WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
        theGuest->allDayRidePassOnGuest=0;

        return 0;

      }


    }


  }



  int guestAttemptsToGoOnRide(Guest* theGuest, Ride* theRide){

    if(theGuest->heightInCm >= theRide->heightRequirementInCm){
      //printf("\n"); //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
      //printf("THE GUEST HAS SATISFIED THE HEIGHT REQUIREMENT AS THEIR HEIGHT IS %d cm AND THE HEIGHT REQUIREMENT FOR THE RIDE IS %d\n",theGuest->heightInCm,theRide->heightRequirementInCm); //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT

      if(theGuest->allDayRidePassOnGuest==1){
        //printf("\n");

        //printf("THE GUESTS AGE IS %d YEARS OLD ",theGuest->age);
        //printf("THE GUEST SUCESSFULLY GOT ON THE RIDE AS THEIR ALL DAY RIDE PASS VALUE IS %d AND THE RIDE THEY RODE WAS CALLED %s\n",theGuest->allDayRidePassOnGuest,theRide->rideName); //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
        theRide->totalNumberOfRiders++;
        theGuest->totalRidesGuestRode++;


        return 1;
      }
      if(theGuest->totalNumberOfTicketsOnGuest>=theRide->numberOfTicketsRequired){
        //printf("\n");

        //printf("THE GUESTS AGE IS %d YEARS OLD ",theGuest->age);
        //printf("THE GUEST WAS ABLE TO GET ON THE RIDE AS THEY HAD A TOTAL OF %d TICKETS AND THE RIDE REQUIRED %d TICKETS AND THE RIDE THEY RODE WAS CALLED %s\n",theGuest->totalNumberOfTicketsOnGuest,theRide->numberOfTicketsRequired,theRide->rideName); //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
        theRide->totalNumberOfRiders++;
        theGuest->totalNumberOfTicketsOnGuest-=theRide->numberOfTicketsRequired;
        theGuest->totalRidesGuestRode++;
        return 1;
      }
      else{

        //DO WE NEED TO INCREMENT theRide->numberOfGuestsDeniedForHeightRequirement , even though this is handling the case where the guest passes height requirement, but does not have tickets or all day ride pass?????

        //printf("\n");
        //printf("THE GUEST COULD NOT GET ON THE RIDE AS THEIR ALL DAY RIDE PASS VALUE WAS %d ",theGuest->allDayRidePassOnGuest);
        //printf("THE NUMBER OF TICKETS THEY HAD WAS %d BUT THE RIDE REQUIRED %d TICKETS",theGuest->totalNumberOfTicketsOnGuest,theRide->numberOfTicketsRequired); //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT

        return 0;

      }


    }
    else{
      //printf("\n");

      //printf("THE GUEST COULD NOT GET ON THE RIDE AS THEIR HEIGHT IS %d cm AND THE RIDE REQUIRES A HEIGHT OF %d cm\n",theGuest->heightInCm,theRide->heightRequirementInCm); //WAS NOT COMMENTED BEFORE TO GET PREVIOUS OUTPUT
      theRide->numberOfGuestsDeniedForHeightRequirement++;
      return 0;

    }



  }
