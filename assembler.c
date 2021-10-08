#include "assembler.h"
#include "mu-mips.h"
/* This function reads the string returned for each line within the file. It converts the instruction string into 
all of a MIPS instructions parts. This is achieved by parsing each portion of the string into seperate strings. It may
be worth looking into making this function recursive for calls on a single string and returning each part of the string in one call.
*/
const char** readString(char* input)
{
    char** masterArray = NULL; 
    char* token;
    masterArray = malloc(sizeof(char *)* 6);
    for(int i = 0; i < 6; i++)
    {
        masterArray[i] = malloc(sizeof(char)*10);
        if(masterArray[i] == NULL)
        {
            perror("Memory cannot accomodate any more allocations of this size!\n****Exiting now****");
            exit(EXIT_FAILURE);
        }
    }
    token = strtok(input, " ");
    for(int i = 0; token != NULL; i++)
    {
        strcpy(masterArray[i], token);
    }
    return masterArray;
}
/*This function takes the instruction string generated elsewhere and returns a corresponging integer for ease of use in instrcution recognition logic
*/
int instRecognize(char *inst)
{
    if(strcmp(inst, "j") == 0 || strcmp(inst, "J") == 0)
    {
        data.isJ = true;
        data.isR = false;
        data.isI = false;
        return 2;
    }
    else if(strcmp(inst, "jal") == 0 || strcmp(inst, "JAL") == 0)
    {
        data.isJ = true;
        data.isR = false;
        data.isI = false;
        return 3;
    }
    else if(strcmp(inst, "addi") == 0 || strcmp(inst, "ADDI") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 8;
    }
    else if(strcmp(inst, "addiu") == 0 || strcmp(inst, "ADDIU") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 9;
    }
    else if(strcmp(inst, "andi") == 0 || strcmp(inst, "ANDI") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 12;
    }
    else if(strcmp(inst, "ori") == 0 || strcmp(inst, "ORI") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 13;
    }
    else if(strcmp(inst, "xori") == 0 || strcmp(inst, "XORI") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 14;
    }
    else if(strcmp(inst, "slti") == 0 || strcmp(inst, "SLTI") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 10;
    }
    else if(strcmp(inst, "lw") == 0 || strcmp(inst, "LW") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 35;
    }
    else if(strcmp(inst, "lb") == 0 || strcmp(inst, "LB") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 16;
    }
    else if(strcmp(inst, "lh") == 0 || strcmp(inst, "LH") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 17;
    }
    else if(strcmp(inst, "lui") == 0 || strcmp(inst, "LUI") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 15;
    }
    else if(strcmp(inst, "sw") == 0 || strcmp(inst, "SW") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 43;
    }
    else if(strcmp(inst, "sb") == 0 || strcmp(inst, "SB") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 40;
    }
    else if(strcmp(inst, "sh") == 0 || strcmp(inst, "SH") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 41;
    }
    else if(strcmp(inst, "beq") == 0 || strcmp(inst, "BEQ") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 4;
    }
    else if(strcmp(inst, "bne") == 0 || strcmp(inst, "BNE") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 5;
    }
    else if(strcmp(inst, "blez") == 0 || strcmp(inst, "BLEZ") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 6;
    }
    else if(strcmp(inst, "bgtz") == 0 || strcmp(inst, "BGTZ") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        return 7;
    }
    else
    {
        data.isI = false;
        data.isR = false;
        data.isJ = false;
        return 1000;
    }    
}
/*This instruction takes the first part of the instrcuction (the beginning of the string until a space is reached)
and using this information formulates the opcode and/or funct.
*/
const char* instToBin(char* input)
{
    switch(instRecognize(input))
    {
        //j-type instructions
        case 2:
        {
            if(data.isJ == true)
                strcpy(data.opcode, "000010");
            else if(data.isR == true)
            {
                strcpy(data.funct, "000010");
                strcpy(data.opcode, "000000");
            }

        }
        case 3:
        {
            if(data.isJ == true)
                strcpy(data.opcode, "000011");
            else if(data.isR == true)
            {
                strcpy(data.funct, "000011");
                strcpy(data.opcode, "000000");
            }
        }
        //i-type instructions
        case 4: 
        {
            //Logic needed for cases where I and R type instructions share an opcode and funct
            if(data.isI == true)
                strcpy(data.opcode, "000100");
        }
        case 5: 
        {
            if(data.isI == true)
                strcpy(data.opcode, "000101");
        }
        case 6:
        {
            if(data.isI == true)
                strcpy(data.opcode, "000110");
        }
        case 7: 
        {
            if(data.isI == true)
                strcpy(data.opcode, "000111");
        }
        case 8:
        {
            if(data.isI == true)
                strcpy(data.opcode, "001000");
            else if(data.isR == true)
            {
                strcpy(data.funct, "001000");
                strcpy(data.opcode, "000000");
            }
        }
        case 9:
        {
            if(data.isI == true)
                strcpy(data.opcode, "001001");
            else if(data.isR == true)
            {
                strcpy(data.funct, "001001");
                strcpy(data.opcode, "000000");
            }
        }
        case 10:
        {
            if(data.isI == true)
                strcpy(data.opcode, "001010");
        }
        case 12:
        {
            if(data.isI == true)
                strcpy(data.opcode, "001100");
        }
        case 13:
        {
            if(data.isI == true)
                strcpy(data.opcode, "001101");
        }
        case 14:
        {
            if(data.isI == true)
                strcpy(data.opcode, "001110");
        }
        case 15:
        {
            if(data.isI == true)
                strcpy(data.opcode, "001111");
        }
        case 16:
        {
            if(data.isI == true)
                strcpy(data.opcode, "010000");
        }
        case 17:
        {
            if(data.isI == true)
                strcpy(data.opcode, "010001");
        }
        case 35:
        {
            if(data.isI == true)
                strcpy(data.opcode, "100011");
        }
        case 40:
        {
            if(data.isI == true)
                strcpy(data.opcode, "101000");
        }
        case 41:
        {
            if(data.isI == true)
                strcpy(data.opcode, "101001");
        }
        case 43:
        {
            if(data.isI == true)
                strcpy(data.opcode, "101011");
        }
    }
}
/* This function converts each part of the string that represents a register into its corresponding binary value.
It takes in the text representation of a MIPS instruction and operates on this data to return the proper binary
*/
const char* regToBin(char* input)
{
     if(input == "$zero"){
        return "00000"
    }


     if(input == "$at"){
        return "00001"
    }

    //v registers
     if(input == "$v0"){
        return "00010"
    }

     if(input == "$v1"){
        return "00011"
    }

    //a registers
     if(input == "$a0"){
        return "00100"
    }

     if(input == "$a1"){
        return "00101"
    }

     if(input == "$a2"){
        return "00110"
    }

     if(input == "$a3"){
        return "00111"
    }

    //t registers
    if(input == "$t0"){
        return "01000"
    }

     if(input == "$t1"){
        return "01001"
    }

     if(input == "$t2"){
        return "01010"
    }

     if(input == "$t3"){
        return "01011"
    }

     if(input == "$t4"){
        return "01100"
    }

     if(input == "$t5"){
        return "01101"
    }

     if(input == "$t6"){
        return "01110"
    }
     if(input == "$t7"){
        return "01111"
    }
    

    //s registers
     if(input == "$s0"){
        return "10000"
    }

     if(input == "$s1"){
        return "10001"
    }

     if(input == "$s2"){
        return "10010"
    }

     if(input == "$s3"){
        return "10011"
    }

     if(input == "$s4"){
        return "10100"
    }

     if(input == "$s5"){
        return "10101"
    }

     if(input == "$s6"){
        return "10110"
    }

     if(input == "$s7"){
        return "10111"
    }
    
     //t registers
     if(input == "$t8"){
        return "11000"
    }

    if(input == "$t9"){
        return "11001"
    }

    //k registers
    if(input == "$k0"){
        return "11010"
    }

    if(input == "$k1"){
        return "11011"
    }

    if(input == "$gp"){
        return "11100"
    }

    if(input == "$sp"){
        return "11101"
    }

    if(input == "$fp"){
        return "11110"
    }

    if(input == "$ra"){
        return "11111"
    }


}


/*This function converts the hexadecimal or Decimal immediate value into a binary representation and returns that as a string.
This will only be used in certain instructions (i.e. immediate or I-type instructions)
*/
const char* immToBin(char* input)
{
    char *hex= "0x";
    char* binString= (char *)malloc(17*sizeof(char));
    //If first two characters of both strings are "0x", then handle as Hex Instruction
    if(strncmp(input, hex, 2) == 0){
        for(i = 2; i < 6; i++) //convert the hex into binary values
	{
		switch (input[i]) //check the character and convert to a 4-bit binary representation.
		{
			case '0':
				strcat(binString, "0000");
				break;
			case '1':
				strcat(binString, "0001");
				break;
			case '2':
				strcat(binString, "0010");
				break;
			case '3':
				strcat(binString, "0011");
				break;
			case '4':
				strcat(binString, "0100");
				break;
			case '5': 
				strcat(binString, "0101");
				break;
			case '6':
				strcat(binString, "0110");
				break;
			case '7':
				strcat(binString, "0111");
				break;
			case '8':
				strcat(binString, "1000");
				break;
			case '9': 
				strcat(binString, "1001");
				break;
			case 'A':
				strcat(binString, "1010");
				break;
			case 'B':
				strcat(binString, "1011");
				break;
			case 'C':
				strcat(binString, "1100");
				break;
			case 'D':
				strcat(binString, "1101");
				break;
			case 'E':
				strcat(binString, "1110");
				break;
			case 'F':
				strcat(binString, "1111");
				break;
		}
	}
	return binString;


    }

    else{ //Else handle as Decimal
            int Dec=0;
            Dec = atoi(input); //Converts string value to int
            int binaryNum[16];
            int binaryNum2[16];

            int i = 0;
            while (Dec > 0) {
 
                // storing remainder in binary array
                 binaryNum[i] = Dec % 2;
                Dec = Dec / 2;
                i++;
             }
            
            int k=0;
            // Indexes through array in reverse order then stores in new int array
            for (int j = i - 1; j >= 0; j--){
                binaryNum2[k]= binaryNum[j];
                if(binaryNum2[k] == 1){ //Converts int to string value
                strcat(binString, "1");
                }
                

                else{

                    strcat(binString, "0");
                }
            }
    

            return binString;

      }

}
/*this will convert the target address used in j-type instructions to a binary string that can be concatenated 
onto the end of the rest of the binary string.
*/
const char* tarToBin(char* input)
{

}
/*This function will concatenate all the strings generated by the other functions into one long string that can 
transform all of them into one readable binary string that can be converted into a hexadecimal number. 
*/
const char* stringToBin(char* input)
{

}
/*This function will convert the final string product of the string to bin function into a hexadecimal number. 
It is possible for this function to convert any binary string of any length into a hexadecimal so long as it
can fit within a 32-bit hexadecimal.
*/
uint32_t binToHex(char* input)
{

}
int main(int argc,char* argv[])
{
    FILE* fp;
    char* progFile = NULL;
    progFile = malloc(strlen(argv[1])*sizeof(char));
    progFile = argv[1];
    fp = fopen(progFile, "r");
    
    
    //needs to read from the file line by line to convert each line into a hex code that can be printed into a file. 
    int i = 0;
    while()
    {
        
    }
}