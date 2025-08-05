#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50    //Defining constant of maximum number of characters in a word for 2d array savingWords
#define MAX_STORY_WORDS 500 //Defining constant of maximum number of words in a story for 2d array savingWords

void capitalizeLetters(char *); //Declaring the function we will use to capitalize the letters of the nouns and pronouns we find


int main(int argc, char **argv){

  char *wordBeforeNoun[] = {"a", "A", "the", "The", "his", "His", "her", "Her", "their", "Their", "its", "Its", "another", "Another", "other", "Other", "no", "No", "my", "My", "your", "Your", "some", "Some",};   //Array to store all words that come before a noun
  char *pronouns[] = {"I", "me", "Me", "he", "He", "she", "She", "it", "It", "him", "Him", "they", "They", "you", "You"};                                                                                           //Array to store all words that are pronouns
  char *pronounsIfFollowed[] = {"another", "Another", "other", "Other", "some", "Some", "this", "This", "her", "Her"};                                                                                              //Array to store all words that are pronouns if they are followed by a period, a comma, the word "a", or the word "and"
  char *specialCase[] = {"One","one"};                                                                                                                                                                              //Array to store the special case of the word "one", where its consiedered a pronoun if the word "of" comes after it or it is considered a noun if it is followed by a period or a comma
  int nounCounter=0;                                                                                                                                                                                                //Variable used to store the number of nouns in the story
  int pronounCounter=0;                                                                                                                                                                                             //Variable used to store the number of pronouns in the story

  //Variable story1 used to store the whole story from the assignment specification
  char *story1 =  "A dog and her pup lived on a farm, where there was a well. The mother of the dog told the pups, do not go near the well or play around it. One of the pups wondered "
                  "why they shouldn't go to the well and decided to explore it. He went to the well. Climbed up the wall and peeked inside. In there, he saw his reflection and thought it "
                  "was another dog. The pup saw that the other dog in the well (his reflection) was doing whatever he was doing, and got angry for imitating him. He decided to fight with the "
                  "dog and jumped into the well, only to find no dog there. He barked and barked and swam until the farmer came and rescued him. Was this a lesson? It sure was one.";

  char *story2 = "One day, a man was walking by a road when he heard a cat meowing from the bushes nearby. The cat was "
                 "stuck and needed some help getting out. When the man reached out, the cat got scared and scratched the "
                 "man. The man screamed loudly but didn’t back down. He tried again and again, even as the cat continued "
                 "to scratch his hands. Another passerby saw this and said, Just let it be! The cat will find a way to "
                 "come out later. The man did not listen but tried until he helped the cat. Once he let the cat free, he "
                 "told him The cat is an animal, and its instincts make him scratch and attack. I am a human and my "
                 "instincts make me compassionate and kind. I also felt that this cat is cute.";

 char *story3 =   "One day, a crab and his mother were on the beach, spending some time together. "
                  "The crab gets up to move, but it can only walk sideways. His mother scolds him for "
                  "walking sideways and asks him to walk forward by pointing his toes out front. The crab "
                  "responds, I would like to walk forward, but I do not know how to. Hearing this, his "
                  "mom gets up to show him how, but even she is unable to bend her knees forward. She "
                  "realizes that she was being unfair, apologizes sheepishly, and sits back in the sand. "


  char savingWords[MAX_STORY_WORDS][MAX_WORD_SIZE]; //Variable used to store all the words and characters seperately from the story
  int numWordsInStory=0;                            //Variable used to keep track of index of words in the 2d array
  int numCharsInWord=0;                             //Variable used to keep track of index of characters of words in the 2d array

  for(int i=0; i<strlen(story1); i++){

    if((char)story1[i] == '('){
      //Here we are we are handling the case where we are storing the opening bracket ('(') into our array to keep the words inside brackets on their own

      savingWords[numWordsInStory][numCharsInWord++] = (char)story1[i];
      savingWords[numWordsInStory][numCharsInWord] = '\0';
      numWordsInStory++;
      numCharsInWord = 0;

    }
    else if((char)story1[i] == ')'){
      //Here we are we are handling the case where we are storing the closing bracket (')') into our array to keep the words inside brackets on their own

      savingWords[numWordsInStory][numCharsInWord] = '\0';
      numWordsInStory++;
      numCharsInWord=0;
      savingWords[numWordsInStory][numCharsInWord++] = ')';
      savingWords[numWordsInStory][numCharsInWord] = '\0';

      numWordsInStory++;
      numCharsInWord = 0;

    }

    else if((char)story1[i] == ' ' || (char)story1[i] == '\0'){
      //Here we are we are handling the case where we make sure to not store the space characters (' ') or the null terminating character ('\0') to our 2d array

      if(numCharsInWord!=0){

        savingWords[numWordsInStory][numCharsInWord] = '\0';
        numWordsInStory++;
        numCharsInWord=0;

      }


    }
    else if((char)story1[i] == '.' || (char)story1[i] == ',' || (char)story1[i] == '?' ){
      //Here we are we are handling the case where we are storing the punctuation of ['?', ',', '.'] as seperate words in our 2d array to keep the words on their own

           numWordsInStory++;
           numCharsInWord=0;
           savingWords[numWordsInStory][numCharsInWord] = (char)story1[i];
           numCharsInWord++;
           savingWords[numWordsInStory][numCharsInWord] = '\0';

    }
    else{
      //Here we are handling the case where we are storing the individual words from the story to the 2d array savingWords[][]

      savingWords[numWordsInStory][numCharsInWord] = (char)story1[i];
      numCharsInWord++;

    }

  }

  //Here we are printing the original story the way it is to the terminal
  for(int k=0; k<=numWordsInStory; k++){

    if((strcmp(savingWords[k+1],".")==0)){

      printf("%s",(char *)(savingWords[k]));


    }
    else if((strcmp(savingWords[k+1],",")==0)){
      printf("%s",(char *)(savingWords[k]));

    }
    else if((strcmp(savingWords[k+1],"?")==0)){
      printf("%s",(char *)(savingWords[k]));

    }
    else if((strcmp(savingWords[k+1],"(")==0)){
      printf("%s",(char *)(savingWords[k]));

    }
    else if((strcmp(savingWords[k+1],")")==0)){
      printf("%s",(char *)(savingWords[k]));

    }
    else{

      printf("%s ",(char *)(savingWords[k]));


    }

  }
  printf("\n");


  for(int m=0; m<numWordsInStory; m++){

    for (int n=0;  n<sizeof(wordBeforeNoun) / sizeof(char *); n++) {

      if(strcmp((char *)(savingWords[m]), wordBeforeNoun[n]) == 0 ){
        //Here we check the case where the words {"a", "A", "the", "The", "his", "His", "her", "Her", "their", "Their", "its", "Its", "another", "Another", "other", "Other", "no", "No", "my", "My", "your", "Your", "some", "Some",} are present and then incrementing the noun counter and finally declaring the next word after the given words as a noun

        nounCounter++;
        char addingLessThanSigns[MAX_WORD_SIZE];

        strcat(addingLessThanSigns,"<");

        capitalizeLetters(savingWords[m+1]);

        strcat(addingLessThanSigns,(char *)(savingWords[m+1]));

        strcat(addingLessThanSigns,">");

        strcpy(savingWords[m+1],addingLessThanSigns);

        addingLessThanSigns[0]='\0';

      }


    }
    for (int o=0;  o<sizeof(pronouns) / sizeof(char *); o++) {

      if(strcmp((char *)(savingWords[m]), pronouns[o]) == 0 ){
        //Here we are checking for the case where the words {"I", "me", "Me", "he", "He", "she", "She", "it", "It", "him", "Him", "they", "They", "you", "You"} are present in the story and then incrementing the pronoun counter
        pronounCounter++;

        char addingSquareBrackets[MAX_WORD_SIZE];

        strcat(addingSquareBrackets,"[");

        capitalizeLetters(savingWords[m]);

        strcat(addingSquareBrackets,(char *)(savingWords[m]));

        strcat(addingSquareBrackets,"]");

        strcpy(savingWords[m],addingSquareBrackets);

        addingSquareBrackets[0]='\0';


      }

    }

    for (int p=0;  p<sizeof(pronounsIfFollowed) / sizeof(char *); p++) {

      if((strcmp(savingWords[m],pronounsIfFollowed[p])==0) && ((strcmp(savingWords[m+1],"a")==0) || (strcmp(savingWords[m+1],"and")==0) || (strcmp(savingWords[m+1],".")==0) || (strcmp(savingWords[m+1],",")==0))){
        //Here we are checking the case where the words {"another", "Another", "other", "Other", "some", "Some", "this", "This", "her", "Her"} are pronouns as long as they are followed by a period, a comma, the word "a" or the word "and" and then incrementing the pronoun counter
        pronounCounter++;

        char addingSquareBrackets2[MAX_WORD_SIZE];

        capitalizeLetters(savingWords[m]);


        strcat(addingSquareBrackets2,"[");
        strcat(addingSquareBrackets2,(char *)(savingWords[m]));
        strcat(addingSquareBrackets2,"]");

        strcpy(savingWords[m],addingSquareBrackets2);

        addingSquareBrackets2[0]='\0';


      }

      else if((strcmp(savingWords[m],pronounsIfFollowed[p])==0) && ((strcmp(savingWords[m+1],"a")!=0) || (strcmp(savingWords[m+1],"and")!=0) || (strcmp(savingWords[m+1],".")!=0) || (strcmp(savingWords[m+1],",")!=0))){
        //Here we check the case where the words {"another", "Another", "other", "Other", "some", "Some", "this", "This", "her", "Her"} are followed by nouns as long as they are not followed by a period, a comma, the word "a" or the word "and" and then incrementing the noun counter
        nounCounter++;


      }
      else{

      }


    }

    for (int q=0;  q<sizeof(specialCase) / sizeof(char *); q++) {
      //Here we check the case where the word "one" is a pronoun as long as it is followed by the word "of" and then incrementing the pronoun counter
      if((strcmp(savingWords[m],specialCase[q])==0) && ((strcmp(savingWords[m+1],"of")==0))){

        pronounCounter++;

        char addingSquareBrackets3[MAX_WORD_SIZE];

        capitalizeLetters(savingWords[m]);


        strcat(addingSquareBrackets3,"[");
        strcat(addingSquareBrackets3,(char *)(savingWords[m]));
        strcat(addingSquareBrackets3,"]");

        strcpy(savingWords[m],addingSquareBrackets3);

        addingSquareBrackets3[0]='\0';



      }
      else if((strcmp(savingWords[m],specialCase[q])==0) && ((strcmp(savingWords[m+1],".")==0) || (strcmp(savingWords[m+1],",")==0))){
        //Here we check the case where the word "one" is a noun as long as it is followed by a period or a comma and then incrementing the noun counter
        nounCounter++;
        char addingLessThanSigns2[MAX_WORD_SIZE];

        strcat(addingLessThanSigns2,"<");

        capitalizeLetters(savingWords[m]);

        strcat(addingLessThanSigns2,(char *)(savingWords[m]));
        strcat(addingLessThanSigns2,">");

        strcpy(savingWords[m],addingLessThanSigns2);

        addingLessThanSigns2[0]='\0';


      }
      else if((strcmp(savingWords[m],specialCase[q])==0) && ((strcmp(savingWords[m+1],".")!=0) && (strcmp(savingWords[m+1],",")!=0) && (strcmp(savingWords[m+1],"of")!=0))){
        //Here we check the case where the word after one is a noun as long as the word "one" is not followed by the word "of" or a period or a comma and then incrementing the pronoun counter
        nounCounter++;
        char addingLessThanSigns3[MAX_WORD_SIZE];

        strcat(addingLessThanSigns3,"<");

        capitalizeLetters(savingWords[m+1]);

        strcat(addingLessThanSigns3,(char *)(savingWords[m+1]));
        strcat(addingLessThanSigns3,">");

        strcpy(savingWords[m+1],addingLessThanSigns3);
        addingLessThanSigns3[0]='\0';

      }
      else{

      }

    }

  }


  //Printing the story with all the brackets for the nouns and pronouns after checking
  printf("\n");
  printf("The story had %d nouns and %d pronouns as follows: \n", nounCounter, pronounCounter);
  printf("\n");

    for(int k=0; k<=numWordsInStory; k++){

      if((strcmp(savingWords[k+1],".")==0)){

        printf("%s",(char *)(savingWords[k]));


      }
      else if((strcmp(savingWords[k+1],",")==0)){
        printf("%s",(char *)(savingWords[k]));

      }
      else if((strcmp(savingWords[k+1],"?")==0)){
        printf("%s",(char *)(savingWords[k]));

      }
      else if((strcmp(savingWords[k+1],"(")==0)){
        printf("%s",(char *)(savingWords[k]));

      }
      else if((strcmp(savingWords[k+1],")")==0)){
        printf("%s",(char *)(savingWords[k]));

      }
      else{

        printf("%s ",(char *)(savingWords[k]));


      }

    }
    printf("\n");




}



//Function called capitalizeLetters in order to capitalize all the letters of a word that gets passed into the parameters
void capitalizeLetters(char *wordToCapitalize){


  for(int i=0; i<strlen(wordToCapitalize); i++){

    wordToCapitalize[i] = toupper(wordToCapitalize[i]);

  }

}
