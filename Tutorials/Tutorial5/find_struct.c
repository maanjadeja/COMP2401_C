//file find_struct.c

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define MAX_EMPLOYEES  30
#define NAME_SIZE     16
#define NUM_NAMES 7

struct emp{
    char firstName[NAME_SIZE];
    char familyName[NAME_SIZE];
    float salary;
    float yearsWithCompany;
};


// This is a forward reference
void populateEmployee(struct emp *emp);
struct emp * findEmployee(struct emp **arr, int arraySize, char *familyName);



int main(int argc, char* argv[])
{
        struct emp empArr[MAX_EMPLOYEES];
        struct emp* empPtrArr[MAX_EMPLOYEES];

        int i;

	// initialize each element of empPtrArr to point to corresponding element of empArr.

        for (i = 0; i < MAX_EMPLOYEES; i++) {
		// ADD CODE


	}

	// populate the employee array
	for (i = 0; i < MAX_EMPLOYEES; i++) {
		// ADD CODE
    populateEmployee(empArr);


	}

	// print the family name
	for (i = 0; i < MAX_EMPLOYEES; i++) printf("%s\n", empPtrArr[i]->familyName);


	// add code to search for employee against the family name "Carp"
  char *theName = "Carp";
  findEmployee(*empPtrArr,MAX_EMPLOYEES,theName);

	// if found print the record
  for (int j = 0; j < MAX_EMPLOYEES; j++) printf("First Name: %s Family Name: %s Salary: %f Years With Company: %f\n", empPtrArr[j]->firstName, empPtrArr[j]->familyName, empPtrArr[j]->salary, empPtrArr[j]->yearsWithCompany);



	// add code to search for employee against the family name "King"
  char *theName = "King";
  findEmployee(*empPtrArr,MAX_EMPLOYEES,theName);

	// if found print the record
  for (int k = 0; k < MAX_EMPLOYEES; k++) printf("First Name: %s Family Name: %s Salary: %f Years With Company: %f\n", empPtrArr[k]->firstName, empPtrArr[k]->familyName, empPtrArr[k]->salary, empPtrArr[k]->yearsWithCompany);



    return 0;
}





/**************************************************************/
/* Purpose: compare the employee record with respect to family name

Input
emp - an employee record
familyName - the key for searching an employee

Output
None

Return
0 if the family name in the employee record does not match that of the given key
1 if the family name in the employee record matches that of the given key
*/

void cmpEmployee(struct emp *emp, char *familyName) //why is this a void, it should be an int to return 0/1

{

  if(strcmp(emp->familyName == familyName)==0){
    return 1;
  }
  else{
    return 0;
  }

	// add code
	// use the -> operator to access the fields
	// recall the precedence order between "*" and "->" operators


}


/**************************************************************/
/* populate an employee passed in by reference

 input/output
 emp - pointer to an emplyee to be initialized

 assumption:
 emp has been previously allocated
 */

void populateEmployee(struct emp *emp)
{
    int j;

    char *fn[NUM_NAMES] = {"John", "Jane", "David", "Dina", "Justin","Jennifer", "Don"};
    char *sn[NUM_NAMES] = {"Smith", "Johnson", "Mart", "Carp", "Farmer","Ouster","Door"};


    // get a random value and make sure that it is in the range of 0-30000
    emp->salary = rand() % 30000;
    emp->yearsWithCompany = rand() % 30;
    j = rand() % NUM_NAMES;
    strncpy(emp->firstName, fn[j],NAME_SIZE-1);
    j = rand() % NUM_NAMES;
    strncpy(emp->familyName, sn[j],sizeof(emp->familyName)-1);

}

struct emp * findEmployee(struct emp **arr, int arraySize, char *familyName){

  for(int i=0; i<arraySize; i++){

    if(*arr[i]->familyName == familyName){

      struct emp* foundEmployee = *arr[i];
      return foundEmployee;

    }
    else{
      return NULL;
    }

  }

}
