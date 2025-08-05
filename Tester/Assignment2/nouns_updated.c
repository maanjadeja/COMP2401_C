
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv){

  char *wordBeforeNoun[13] = {"a", "A", "the", "his", "her", "their", "its", "another", "other", "no", "my", "your", "some"};
  char *pronouns[8] = {"I", "me", "he", "she", "it", "him", "they", "you"};
  char *pronounsIfFollowed[5] = {"another", "other", "some", "this", "her"};
  char *specialCase[1] = {"One"};
  int nounCounter;
  int pronounCounter;
  //int indexOfPossibleNouns[]; //check and save index of characters after word that appear before nown

  char *story1 =  "A dog and her pup lived on a farm, where there was a well. The mother of the dog told the pups, do not go near the well or play around it. One of the pups wondered "
                  "why they shouldn't go to the well and decided to explore it. He went to the well. Climbed up the wall and peeked inside. In there, he saw his reflection and thought it "
                  "was another dog. The pup saw that the other dog in the well (his reflection) was doing whatever he was doing, and got angry for imitating him. He decided to fight with the "
                  "dog and jumped into the well, only to find no dog there. He barked and barked and swam until the farmer came and rescued him. Was this a lesson? It sure was one.";


//1.identify and print out each word 1 word at a time, and then print out the size of the word - to make sure words are of right size and skip ". , !...."


  char savingWords[150][150];
  int rowIndex=0;
  int columnIndex=0;

  for(int i=0; i<strlen(story1); i++){

    if((char)story1[i] == ' ' || (char)story1[i] == '\0'){

      savingWords[rowIndex][columnIndex] = '\0';
      rowIndex++;
      columnIndex=0;

    }
    else if((char)story1[i] == '.' || (char)story1[i] == ',' ) //add seperate word for immediate ''
    {
           rowIndex++;
           columnIndex=0;
           savingWords[rowIndex][columnIndex] = (char)story1[i];
            columnIndex++;
           savingWords[rowIndex][columnIndex] = '\0';
    }
    else{

      savingWords[rowIndex][columnIndex] = (char)story1[i];
      columnIndex++;

    }

  }

  for(int k=0; k<rowIndex; k++){

    printf("%s\n",savingWords[k]);
  }
  
  printf("\n nouns \n");

  int noOfNouns=0;
  
  for (int j=0;j<sizeof(savingWords);j++)
  {
  for(int k=0; k<sizeof(*wordBeforeNoun); k++){

    if(strcmp(savingWords[j] , (char *)wordBeforeNoun[k])==0){

      printf("%s\n", savingWords[j +1 ]);
      
      noOfNouns++;
        break; //no need further check match with wordBeforeNoun
    } //if completed
  
  } //word before nown loop

  }//savings word loop





}

