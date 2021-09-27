#include "assembler.h"
#include "mu-mips.h"
/* This function reads the string returned for each line within the file. It converts the instruction string into 
all of a MIPS instructions parts. This is achieved by parsing each portion of the string into seperate strings. It may
be worth looking into making this function recursive for calls on a single string and returning each part of the string in one call.
*/
const char* readString(char* input)
{

} 
/* This function reads in each line of the input file and feeds it to the readString function which will in turn 
feed the input lines to teh other functions implemented in this program. It will return a single string that
is the maximum character length of a MIPS isntruction 
*/
const char* readLine(FILE* fp)
{
    
}
/*This instruction takes the first part of the instrcuction (the beginning of the string until a space is reached)
and using this information formulates the opcode and/or funct.
*/
const char* instToBin(char* input)
{

}
/* This function converts each part of the string that represents a register into its corresponding binary value.
It takes in the text representation of a MIPS instruction and operates on this data to return the proper binary
*/
const char* regToBin(char* input)
{

}
/*This function converts the hexadecimal immediate value into a binary representation and returns that as a string.
This will only be used in certain instructions (i.e. immediate or I-type instructions)
*/
const char* immToBin(char* input)
{

}
/*this will convert the target address used in j-type instructions to a binary string that can be concatenated 
onto the end of the rest of the binary string.
*/
const char* tarToBin(char* input)
{

}