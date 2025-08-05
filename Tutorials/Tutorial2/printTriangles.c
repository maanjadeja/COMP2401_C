/* File is printTriangles.c

Purpose: file is for tutorial 2 to explore recursion


Revision:
a. Initial code - Doron Nussbaum 14/9/2018
b. Revision to remove unused prototypes and change return types
c. Revision to remove use of ptr in printTriangleRecursiveCountStars
*/

/************************************************************************/

// INCLUDE FILES

#include "stdio.h"
#include "stdlib.h"


/************************************************************************/
// FUNCTION PROTOTYPES

void printTriangleRecursive(unsigned int numRows);
void printTriangleRecursiveUpsidedown(unsigned int numRows);
int  printTriangleRecursiveCountStars(unsigned int numRows);

/************************************************************************/


int main()
{

  unsigned int numRows=7;
	int numStars;
  int j;

  printf("TESTING COUNT STARS %d:\n",printTriangleRecursiveCountStars(10));
  



	printf("printing a triangle with %d rows \n",numRows);
	printTriangleRecursive(numRows);

	printf("\nprinting a triangle upside down with %d rows \n\n",numRows);
	printTriangleRecursiveUpsidedown(numRows);

	printf("\nprinting a triangle with %d rows and counting the number of stars\n\n",numRows);
	printf("the number of printf * should be %d \n", (1+numRows)*numRows/2);
	numStars = printTriangleRecursiveCountStars(numRows);
	printf("\nthe number of * returned by the function is %d\n\n",numStars);

	return(0);
}


/***********************************************************************************/
/* Purpose: prints a triangle using '*'

input:
numRows - the number of rows that the triangle should have

output:
none

return:
none

*/


void printTriangleRecursive(unsigned int numRows)
{
	// add code
  if(numRows==0){
    return;

  }
  else{

    printTriangleRecursive(numRows-1);
    for(int i=0; i<numRows; i++){

      printf("*");

    }
    printf("\n");


  }

    //return;
}

void printTriangleRecursiveUpsidedown(unsigned int numRows)
{
	// add code
  if(numRows==0){
    return;

  }
  else{


    for(int i=numRows; i>0; i--){

      printf("*");

    }
    printf("\n");
    printTriangleRecursiveUpsidedown(numRows-1);




  }

    //return;
}


/***********************************************************************************/
/* Purpose: prints a triangle using '*' and computes how many '*' were printed

input:
numRows - the number of rows that the triangle should have

output:
none

return: the number of stars that were printed
*/


int printTriangleRecursiveCountStars(unsigned int numRows)
{

  if(numRows==0){
    return 0;

  }
  else{

    for(int i=0; i<numRows; i++){

      printf("*");

    }
    printf("\n");
    return(printTriangleRecursiveCountStars(numRows-1)+numRows);



  }



	// add code


}




/***********************************************************************************/
/* Purpose: prints a triangle using '*' with the base as the first row

input:
numRows - the number of rows that the triangle should have

output:
none

return:
none

*/


/*void printTriangleRecursiveUpsidedown(unsigned int numRows)
{


	// add code


	return;
}*/
