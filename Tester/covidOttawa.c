#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>

int main(int argc, char **argv)
{

  short int weeklyCases[] = {9, 20, 104, 223, 223, 268, 281, 363, 149, 134, 105, 64,
  56, 35, 22, 29, 29, 40, 74, 200, 129, 76, 63, 128, 118, 127, 234, 323, 454, 645,
  721, 609, 501, 571, 394, 396, 253, 281, 291, 315, 281, 364, 668, 987, 909, 644,
  408, 348, 289, 384, 362, 390, 461, 550, 709, 1216, 1543, 2199, 1600, 1160, 854,
  683, 552};

  short int weeklyCases2[] = {9, 20, 104, 223, 223, 268, 281, 363, 149, 134, 105, 64,
  56, 35, 22, 29, 29, 40, 74, 200, 129, 76, 63, 128, 118, 127, 234, 323, 454, 645,
  721, 609, 501, 571, 394, 396, 253, 281, 291, 315, 281, 364, 668, 987, 909, 644,
  408, 348, 289, 384, 362, 390, 461, 550, 709, 1216, 1543, 2199, 1600, 1160, 854,
  683, 552};

  const int totalWeeks = 63;
  int totalCases;
  float averageCases;
  int worstWeek;
  float starValue;
  const int iterationsToSmooth = 5;
  float averageBetweenWeeks;
  float worstAverageWeek = 1780.67;
  float averageStarValue;



  for(int i=0; i<=totalWeeks; i++){
    totalCases+=weeklyCases[i];
  }

  averageCases = (float)totalCases/(float)totalWeeks;

  for(int i=0; i<=totalWeeks; i++){
    if(worstWeek < weeklyCases[i]){
      worstWeek = weeklyCases[i];
    }
    else{
      continue;
    }
  }

  setlocale(LC_NUMERIC, "");
  printf("There were %'d cases in total over the %'d weeks.\n",totalCases,totalWeeks);
  printf("The average is %.1f cases per week.\n",averageCases);
  printf("The worst week had %d cases.\n",worstWeek);

  printf("\n");

  printf("Here is the weekly cases histogram: \n");

  for(int i=0; i<=totalWeeks-1; i++){

    starValue = (weeklyCases[i]*50)/worstWeek;

    printf("Week %2d:  ",i);

    for(int j=0; j<starValue+1; j++){

      printf("*");


    }
    printf("\n");

  }



  /////TA WORK:

  for(int x=0; x<iterationsToSmooth-1; x++){

    for(int p=0; p<=totalWeeks-1; p++){

      if(p==0){

        averageBetweenWeeks = ((float)weeklyCases[p]+(float)weeklyCases[p+1])/2;
        weeklyCases2[p]=averageBetweenWeeks;


      }
      else if(p==totalWeeks-1){

        averageBetweenWeeks = ((float)weeklyCases[p]+(float)weeklyCases[p-1])/2;
        weeklyCases2[p]=averageBetweenWeeks;

      }
      else{

        averageBetweenWeeks = ((float)weeklyCases[p-1]+(float)weeklyCases[p]+(float)weeklyCases[p+1])/3;
        weeklyCases2[p]=averageBetweenWeeks;


      }

      //We have to save the updated list we change to the average values to continue the iteration stuff!!!! THATS THE ERROR

      memcpy(weeklyCases2, weeklyCases, sizeof(weeklyCases));
      //weeklyCases = weeklyCases2;

    }


    //iterationsToSmooth--;

  }

  printf("\n");
  printf("\n");
  printf("Here is the weekly cases histogram after averaging:\n");

  for(int z=0; z<=totalWeeks-1; z++){

    //printf("INDEX: %d VALUE: %d\n",z,weeklyCases2[z]);

    averageStarValue = (weeklyCases[z]*32)/weeklyCases[57];

    float factor = (weeklyCases[57])/32;


    //factor = ceil(factor);



    //ceil(factor*);

    //ceil(averageStarValue);

    printf("Week %2d:  ",z);

    /*for(int a=0; a<round(weeklyCases[z]/factor); a++){

      printf("*");


    }*/
    printf("\n");

  }









  return(0);
}
