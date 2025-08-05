#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>

//Declaring constant variables
#define TOTAL_WEEKS 63            //Variable used to store the total number of weeks
#define ITERATIONS_TO_SMOOTH 5    //Variable used to store the number of iterations to smooth for average histogram


int main(int argc, char **argv){

  //Variable declaration
  int   totalCases;                 //Variable to store the total number of cases in weekly cases
  float numAverageCases;            //Variable to store the average cases per week
  int   worstWeek;                  //Variable to store the week with the highest number of cases
  float starValue;                  //Variable to use to store the value of number of cases in order to print stars in the histogram
  float averageBetweenWeeks;        //Variable to store the average value we calculated at the beginning of the array, the middle of the array and end of the array
  float averageStarValue;           //Variable to use to store the value of number of cases in order to print stars in the histogram
  int   numWaves;                   //Variable to store the number of waves in the averaged histogram

  //Declaring given weekly cases array in specification
  short int weeklyCases[] = {9, 20, 104, 223, 223, 268, 281, 363, 149, 134, 105, 64,
  56, 35, 22, 29, 29, 40, 74, 200, 129, 76, 63, 128, 118, 127, 234, 323, 454, 645,
  721, 609, 501, 571, 394, 396, 253, 281, 291, 315, 281, 364, 668, 987, 909, 644,
  408, 348, 289, 384, 362, 390, 461, 550, 709, 1216, 1543, 2199, 1600, 1160, 854,
  683, 552};

  //Creating an array of same size to store the "averaged weekly cases", but initially setting it equivalent to the main weekly cases array
  short int averagedWeeklyCases[TOTAL_WEEKS];

  for(int w=0; w<=TOTAL_WEEKS; w++){

    averagedWeeklyCases[w] = weeklyCases[w];

  }

  //Calculating the total cases from all weekly cases
  for(int i=0; i<=TOTAL_WEEKS; i++){

    totalCases += weeklyCases[i];

  }

  //Calculating the average of all weekly cases per week
  numAverageCases = (float)totalCases/(float)TOTAL_WEEKS;

  //Searching for the week with the highest number of cases
  worstWeek = 0;
  for(int i=0; i<=TOTAL_WEEKS; i++){

    if(worstWeek < weeklyCases[i]){

      worstWeek = weeklyCases[i];

    }

    else{

      continue;

    }

  }

  //Presenting all calculated data to the user according to LC_NUMERIC format
  setlocale(LC_NUMERIC, "");
  printf("There were %'d cases in total over the %'d weeks.\n",totalCases,TOTAL_WEEKS);
  printf("The average is %.1f cases per week.\n",numAverageCases);
  printf("The worst week had %d cases.\n",worstWeek);

  printf("\n");

  //Presenting the histogram that represents the weekly cases
  printf("Here is the weekly cases histogram: \n");

  for(int i=0; i<=TOTAL_WEEKS-1; i++){

    starValue = (weeklyCases[i]*50)/worstWeek;

    printf("Week %2d:  ",i);

    for(int j=0; j<starValue+1; j++){

      if(j >= 50){//Handling the case where the number of stars would exceed 50

        for(int u=j; u<50; u++){

          printf("*");

        }

      }

      else{//Handling the case where the number of stars are less than 50

        printf("*");

      }

    }

    printf("\n");

  }

  //Calculating the "averaged weekly cases" and storing them into the averagedWeeklyCases array
  for(int x=0; x<ITERATIONS_TO_SMOOTH; x++){

    for(int p=0; p<=TOTAL_WEEKS-1; p++){

      if(p==0){ //Handling the beginning of the array

        averageBetweenWeeks = ((float)averagedWeeklyCases[p]+(float)averagedWeeklyCases[p+1])/2;
        averagedWeeklyCases[p]=averageBetweenWeeks;

      }

      else if(p==TOTAL_WEEKS-1){//Handling the middle of the array

        averageBetweenWeeks = ((float)averagedWeeklyCases[p]+(float)averagedWeeklyCases[p-1])/2;
        averagedWeeklyCases[p]=averageBetweenWeeks;

      }

      else{//Handling the end of the array

        averageBetweenWeeks = ((float)averagedWeeklyCases[p-1]+(float)averagedWeeklyCases[p]+(float)averagedWeeklyCases[p+1])/3;
        averagedWeeklyCases[p]=averageBetweenWeeks;

      }

    }

  }

  printf("\n");
  printf("\n");
  printf("Here is the weekly cases histogram after averaging:\n");

  //Presenting the histogram for the averaged weekly cases
  for(int z=0; z<=TOTAL_WEEKS-1; z++){

    averageStarValue = (averagedWeeklyCases[z]*50)/worstWeek;

    printf("Week %2d:  ",z);

    for(int a=0; a<averageStarValue+1; a++){

      if(a >= 50){//Handling the case where the number of stars would exceed 50

        for(int q=a; q<50; q++){

          printf("*");

        }

      }

      else{//Handling the case where the number of stars are less than 50

        printf("*");

      }

    }

    printf("\n");

  }

  //Calculating the number of waves throughout the averaged weekly cases
  for(int u=1; u<=TOTAL_WEEKS-1; u++){

    if(averagedWeeklyCases[u-1]<averagedWeeklyCases[u] && averagedWeeklyCases[u]>=averagedWeeklyCases[u+1]){ //Finding location of a wave

      numWaves++;

    }

  }

  //Presenting the number of waves
  printf("\n");
  printf("The number of waves during the %d weeks was %d.\n",TOTAL_WEEKS, numWaves);


  return(0);
}
