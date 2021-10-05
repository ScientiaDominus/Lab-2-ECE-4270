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
            strcpy(data.opcode, "000010");
        }
        case 3:
        {
            strcpy(data.opcode, "000011");
        }
        //i-type instructions
        case 4: 
        {
            //Logic needed for cases where I and R type instructions share an opcode and funct
            strcpy(data.opcode, "000100");
        }
        case 5: 
        {
            strcpy(data.opcode, "000101");
        }
        case 6:
        {
            strcpy(data.opcode, "000110");
        }
        case 7: 
        {
            strcpy(data.opcode, "000111");
        }
        case 8:
        {
            strcpy(data.opcode, "001000");
        }
        case 9:
        {
            strcpy(data.opcode, "001001");
        }
        case 10:
        {
            strcpy(data.opcode, "001010");
        }
        case 12:
        {
            strcpy(data.opcode, "001100");
        }
        case 13:
        {
            strcpy(data.opcode, "001101");
        }
        case 14:
        {
            strcpy(data.opcode, "001110");
        }
        case 15:
        {
            strcpy(data.opcode, "001111");
        }
        case 16:
        {
            strcpy(data.opcode, "010000");
        }
        case 17:
        {
            strcpy(data.opcode, "010001");
        }
        case 35:
        {
            strcpy(data.opcode, "100011");
        }
        case 40:
        {
            strcpy(data.opcode, "101000");
        }
        case 41:
        {
            strcpy(data.opcode, "101001");
        }
        case 43:
        {
            strcpy(data.opcode, "101011");
        }

    }
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