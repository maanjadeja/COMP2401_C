#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 50
#define MAX_STORY_WORDS 500

void capitalizeLetters(char *);


int main(int argc, char **argv){

  char *wordBeforeNoun[] = {"a", "A", "the", "The", "his", "His", "her", "Her", "their", "Their", "its", "Its", "another", "Another", "other", "Other", "no", "No", "my", "My", "your", "Your", "some", "Some",};
  char *pronouns[] = {"I", "me", "Me", "he", "He", "she", "She", "it", "It", "him", "Him", "they", "They", "you", "You"};
  char *pronounsIfFollowed[] = {"another", "other", "some", "this", "her"};
  char *specialCase[] = {"One","one"};
  int nounCounter=0;
  int pronounCounter=0;
  //int indexOfPossibleNouns[]; //check and save index of characters after word that appear before nown

  char *story1 =  "A dog and her pup lived on a farm, where there was a well. The mother of the dog told the pups, do not go near the well or play around it. One of the pups wondered "
                  "why they shouldn't go to the well and decided to explore it. He went to the well. Climbed up the wall and peeked inside. In there, he saw his reflection and thought it "
                  "was another dog. The pup saw that the other dog in the well (his reflection) was doing whatever he was doing, and got angry for imitating him. He decided to fight with the "
                  "dog and jumped into the well, only to find no dog there. He barked and barked and swam until the farmer came and rescued him. Was this a lesson? It sure was one.";

  /*char *story1 = "One day, a man was walking by a road when he heard a cat meowing from the bushes nearby. The cat was "
                 "stuck and needed some help getting out. When the man reached out, the cat got scared and scratched the "
                 "man. The man screamed loudly but didn’t back down. He tried again and again, even as the cat continued "
                 "to scratch his hands. Another passerby saw this and said, Just let it be! The cat will find a way to "
                 "come out later. The man did not listen but tried until he helped the cat. Once he let the cat free, he "
                 "told him The cat is an animal, and its instincts make him scratch and attack. I am a human and my "
                 "instincts make me compassionate and kind. I also felt that this cat is cute.";*/



//1.identify and print out each word 1 word at a time, and then print out the size of the word - to make sure words are of right size and skip ". , !...."


  char savingWords[MAX_STORY_WORDS][MAX_WORD_SIZE];
  int numWordsInStory=0;
  int numCharsInWord=0;

  for(int i=0; i<strlen(story1); i++){

    if((char)story1[i] == ' ' || (char)story1[i] == '\0'  ){

      savingWords[numWordsInStory][numCharsInWord] = '\0';
      numWordsInStory++; //to proceed to the next word
      numCharsInWord=0; //set index to 0 to place from beginning of every row

    }
    else if((char)story1[i] == '(') 
    {
           numWordsInStory++;//numWordsInStory
           numCharsInWord=0;//numCharsInWord
           savingWords[numWordsInStory][numCharsInWord] = (char)story1[i];
          numCharsInWord++;//numCharsInWord
           savingWords[numWordsInStory][numCharsInWord] = '\0';
           numWordsInStory++;//numWordsInStory will increase from here
            numCharsInWord=0; //reset pointer to 0
    }
    else if((char)story1[i] == '.' || (char)story1[i] == ',' || (char)story1[i] == '?' || (char)story1[i] == ')' ){

           numWordsInStory++;//numWordsInStory
           numCharsInWord=0;//numCharsInWord
           savingWords[numWordsInStory][numCharsInWord] = (char)story1[i];
           numCharsInWord++;//numCharsInWord
           savingWords[numWordsInStory][numCharsInWord] = '\0';

    }
    else{

      savingWords[numWordsInStory][numCharsInWord] = (char)story1[i];
      numCharsInWord++;

    }

  }

  for(int k=0; k<numWordsInStory; k++){

    //for(int z=0; z<numCharsInWord; z++){

      //printf("%c\n",(savingWords[k][z]));

      printf("%s\n",(char *)savingWords[k] );


    //}

  }


  for(int m=0; m<numWordsInStory; m++){

    for (int n=0;  n<sizeof(wordBeforeNoun) / sizeof(char *); n++) {
      //check for words before noun
      if(strcmp((char *)(savingWords[m]), wordBeforeNoun[n]) == 0 ){

        nounCounter++;
        //strcat((char *)(savingWords[m]), "[");
        char addingLessThanSigns[MAX_WORD_SIZE];

        strcat(addingLessThanSigns,"<");

        capitalizeLetters(savingWords[m+1]);
        // for(int z=0; z<strlen(savingWords[m+1]); z++){ //THIS IS ONLY CAPITALIZING THE FIRST LETTER OF THE NOUNS

        //   savingWords[m+1][z] = savingWords[m+1][z]-32;

        // }
        strcat(addingLessThanSigns,(char *)(savingWords[m+1]));
        //char *capitalWord = capitalizeLetters((savingWords[m+1]));
        //strcat(addingLessThanSigns,capitalWord);

        strcat(addingLessThanSigns,">");



        printf("SAVING WORDS: %s\n",(char *)(savingWords[m]));
        printf("\n");
        printf("WORD BEFORE NOUN: %s\n",wordBeforeNoun[n]);
        printf("\n");
        printf("THE NOUN: %s\n",(char *)(savingWords[m+1]));
        printf("\n");
        strcpy(savingWords[m+1],addingLessThanSigns);
        printf("THE NOUN WITH BRACKETS: %s\n",addingLessThanSigns);
        
        printf("\n");
        addingLessThanSigns[0]='\0';






      }

    }
    for (int o=0;  o<sizeof(pronouns) / sizeof(char *); o++) {
      //check for pronouns
      if(strcmp((char *)(savingWords[m]), pronouns[o]) == 0 ){

        pronounCounter++;

        char addingSquareBrackets[MAX_WORD_SIZE];

        strcat(addingSquareBrackets,"[");

      
        capitalizeLetters(savingWords[m]);
        // for(int w=0; w<strlen(savingWords[m]); w++){

        //   savingWords[m][w] = savingWords[m][w]-32; //THIS IS CAUSING ERRORS IN CAPITALIZATION OF WORDS THAT BEGIN A SENTENCE

        // }

        strcat(addingSquareBrackets,(char *)(savingWords[m]));

        //if((char *)(savingWords[m+1][strlen(savingWords[m+1])]) == ',' || (char *)(savingWords[m+1][strlen(savingWords[m+1])]) == '.' || (char *)(savingWords[m+1][strlen(savingWords[m+1])]) == '?' )
        strcat(addingSquareBrackets,"]");

        printf("SAVING WORDS: %s\n",(char *)(savingWords[m]));
        printf("\n");
        printf("THE PRONOUN: %s\n",pronouns[o]);
        printf("\n");
        printf("THE pronoun: %s\n",(char *)(savingWords[m+1]));
        printf("\n");
        strcpy(savingWords[m],addingSquareBrackets);
        printf("THE PRONOUN WITH BRACKETS: %s\n",addingSquareBrackets);
        printf("\n");
        addingSquareBrackets[0]='\0';


      }

    }

    for (int p=0;  p<sizeof(pronounsIfFollowed) / sizeof(char *); p++) {
      //check for pronouns if followed
      if((strcmp(savingWords[m],pronounsIfFollowed[p])==0) && ((strcmp(savingWords[m+1],"a")==0) || (strcmp(savingWords[m+1],"and")==0) || (strcmp(savingWords[m+1],".")==0) || (strcmp(savingWords[m+1],",")==0))){

        printf("ENTERED PRONOUN CHECKER\n");
        pronounCounter++;

        char addingSquareBrackets2[MAX_WORD_SIZE];
        
        capitalizeLetters(savingWords[m]);

        strcat(addingSquareBrackets2,"[");
        strcat(addingSquareBrackets2,(char *)(savingWords[m]));
        //if((char *)(savingWords[m+1][strlen(savingWords[m+1])]) == ',' || (char *)(savingWords[m+1][strlen(savingWords[m+1])]) == '.' || (char *)(savingWords[m+1][strlen(savingWords[m+1])]) == '?' )
        strcat(addingSquareBrackets2,"]");

        printf("SAVING WORDS: %s\n",(char *)(savingWords[m]));
        printf("\n");
        printf("THE PRONOUN: %s\n",pronouns[p]);
        printf("\n");
        printf("THE pronoun: %s\n",(char *)(savingWords[m+1]));
        printf("\n");
        strcpy(savingWords[m],addingSquareBrackets2);
        printf("THE PRONOUN WITH BRACKETS: %s\n",addingSquareBrackets2);
        printf("\n");
        addingSquareBrackets2[0]='\0';


      }

      else if((strcmp(savingWords[m],pronounsIfFollowed[p])==0) && ((strcmp(savingWords[m+1],"a")!=0) || (strcmp(savingWords[m+1],"and")!=0) || (strcmp(savingWords[m+1],".")!=0) || (strcmp(savingWords[m+1],",")!=0))){
        //if not followed by above cases its a noun
        
        printf("\n not followed so nown %s \n",savingWords[m]);
        nounCounter++; //THIS IS CAUSING ERRORS IN THE SUM OF THE NUMBER OF NOUNS PRESENT
        //jay: just counter is increased , we need to captilize , add <> to it
        //jay: extra count 2 are comming from here 1st :her in "a dog and her pups". 2nd dog from "the other dog in the"
      }
      else{
        continue;
      }


    }

    for (int q=0;  q<sizeof(specialCase) / sizeof(char *); q++) {
      //check for special case
      if((strcmp(savingWords[m],specialCase[q])==0) && ((strcmp(savingWords[m+1],"of")==0))){

        pronounCounter++;

        char addingSquareBrackets3[MAX_WORD_SIZE];

        capitalizeLetters(savingWords[m]); //it was missing , added

        strcat(addingSquareBrackets3,"[");
        strcat(addingSquareBrackets3,(char *)(savingWords[m])); 
        //if((char *)(savingWords[m+1][strlen(savingWords[m+1])]) == ',' || (char *)(savingWords[m+1][strlen(savingWords[m+1])]) == '.' || (char *)(savingWords[m+1][strlen(savingWords[m+1])]) == '?' )
        strcat(addingSquareBrackets3,"]");

        printf("SAVING WORDS: %s\n",(char *)(savingWords[m]));
        printf("\n");
        printf("THE PRONOUN: %s\n",specialCase[q]);
        printf("\n");
        printf("THE pronoun: %s\n",(char *)(savingWords[m+1]));
        printf("\n");
        strcpy(savingWords[m],addingSquareBrackets3);
        printf("THE PRONOUN WITH BRACKETS: %s\n",addingSquareBrackets3);
        printf("\n");
        addingSquareBrackets3[0]='\0';



      }
      else if((strcmp(savingWords[m],specialCase[q])==0) && ((strcmp(savingWords[m+1],".")==0) || (strcmp(savingWords[m+1],",")==0))){

        nounCounter++;
        char addingLessThanSigns2[MAX_WORD_SIZE];

        strcat(addingLessThanSigns2,"<");

        capitalizeLetters(savingWords[m]);
        // for(int t=0; t<strlen(savingWords[m]); t++){ //THIS IS ONLY CAPITALIZING THE FIRST LETTER OF THE NOUNS

        //   savingWords[m][t] = savingWords[m][t]-32;

        // }
        strcat(addingLessThanSigns2,(char *)(savingWords[m]));
        //if((char *)(savingWords[m+1][strlen(savingWords[m+1])]) == ',' || (char *)(savingWords[m+1][strlen(savingWords[m+1])]) == '.' || (char *)(savingWords[m+1][strlen(savingWords[m+1])]) == '?' )
        strcat(addingLessThanSigns2,">");

        printf("SAVING WORDS: %s\n",(char *)(savingWords[m]));
        printf("\n");
        printf("THE NOUN: %s\n",specialCase[q]);
        printf("\n");
        printf("THE noun: %s\n",(char *)(savingWords[m+1]));
        printf("\n");
        strcpy(savingWords[m],addingLessThanSigns2);
        printf("THE noun WITH BRACKETS: %s\n",addingLessThanSigns2);
        printf("\n");
        addingLessThanSigns2[0]='\0';


      }
      else if((strcmp(savingWords[m],specialCase[q])==0) && ((strcmp(savingWords[m+1],".")!=0) && (strcmp(savingWords[m+1],",")!=0) && (strcmp(savingWords[m+1],"of")!=0))){
        //if one is not a noun or a pronoun, word after it is a noun.
        nounCounter++;
        char addingLessThanSigns3[MAX_WORD_SIZE];

        strcat(addingLessThanSigns3,"<");
   // printf("\n capatlizing2 %s \n",savingWords[m+1]);
        capitalizeLetters(savingWords[m+1]);
        // for(int r=0; r<strlen(savingWords[m+1]); r++){ //THIS IS ONLY CAPITALIZING THE FIRST LETTER OF THE NOUNS

        //   savingWords[m+1][r] = savingWords[m+1][r]-32;

        // }
        strcat(addingLessThanSigns3,(char *)(savingWords[m+1]));
        //if((char *)(savingWords[m+1][strlen(savingWords[m+1])]) == ',' || (char *)(savingWords[m+1][strlen(savingWords[m+1])]) == '.' || (char *)(savingWords[m+1][strlen(savingWords[m+1])]) == '?' )
        strcat(addingLessThanSigns3,">");
        printf("THE NOUN IN THE SPEC: %s\n",savingWords[m+1]);
        printf("\n");
        strcpy(savingWords[m+1],addingLessThanSigns3);
        addingLessThanSigns3[0]='\0';




      }
      else{
       // printf("END OF CHECKING!\n");
      }

    }

  }


/*OVERALL LOGIC FOR CHECKING

for(,,,){

  for(wordBeforeNoun){

  }
  for(){

  }
  for(){

}

}

*/

  printf("\n");
  printf("The story had %d nouns and %d pronouns as follows: \n", nounCounter, pronounCounter);
  printf("\n");

    for(int k=0; k<=numWordsInStory; k++){

      if((strcmp(savingWords[k+1],".")==0)){ // here we handled the case of making sure there was no space between the word and punctuation

        printf("%s",(char *)(savingWords[k]));


      }
      else if((strcmp(savingWords[k+1],",")==0)){
        printf("%s",(char *)(savingWords[k]));

      }
      else if((strcmp(savingWords[k+1],"?")==0)){
        printf("%s",(char *)(savingWords[k]));

      }
      else{

        printf("%s ",(char *)(savingWords[k]));


      }

    }
    printf("\n");




}




void capitalizeLetters(char *wordToCapitalize){


    const char OFFSET = 'a' - 'A';
    while (*wordToCapitalize)
    {
        *wordToCapitalize = (*wordToCapitalize >= 'a' && *wordToCapitalize <= 'z') ? *wordToCapitalize -= OFFSET : *wordToCapitalize;
        wordToCapitalize++;
    }
}


