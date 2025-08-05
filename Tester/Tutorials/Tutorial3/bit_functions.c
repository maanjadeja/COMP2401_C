
/* file is bit_functions.c
Purpose: helper functions for bit manipulation

*/

#include "bit_functions.h"




/*
Purpose: checks if bit in position bitNum of the character c is set to 1
input:
c - a character
bitNum - the bit position

return
1 if the bits is set
0 is the bit is not set

*/
int isBitSet(unsigned char c, int bitNum)
{ /*unsigned char answer;
	answer = answer<<1;
	if((answer & c)==true){
		return 1;
	}
	else{
		return 0;
	}*/
	c = (c & (1 << bitNum)) >> bitNum;

}


/***************************************************************/


/*
Purpose: sets bit in position bitNum of the character c to 1
input:
c - a character
bitNum - the bit position

return
the modified character

*/
unsigned char setBit(unsigned char c, int bitNum)
{
	c = (c|(1<<bitNum));
	return c;
}


/***************************************************************/

/*
Purpose: clears bit in position bitNum of the character c
input:
c - a character upon
bitNum - the bit position

return
the modified character

*/

unsigned char clearBit(unsigned char c, int bitNum)
{/*unsigned char answer;
	answer = c<<1;
	answer = c|answer;
	return answer;*/
	c = (c & (1 << bitNum)) >> bitNum;

}


/***************************************************************/

/*
Purpose: prints the bits of the the character using an iterative method
input:
c - a character that its bits must be printed

return
none

*/

void printBitsIterative(unsigned char c)
{ int bitvalue = 1|0;

	for (int i=0; i<8; i++){
		if(isBitSet(c,bitvalue)){
			printf("1") //Incomplete
		}
	}

}

/***************************************************************/


/*
Purpose: prints the bits of the the character using recurive method
input:
c - a character that its bits must be printed

return
none

*/

void printBitsRecursive(unsigned char c)
{

}
