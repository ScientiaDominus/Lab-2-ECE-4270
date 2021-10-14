#include "assembler.h"
//#include "mu-mips.h"
/* This function reads the string returned for each line within the file. It converts the instruction string into 
all of a MIPS instructions parts. This is achieved by parsing each portion of the string into seperate strings. It may
be worth looking into making this function recursive for calls on a single string and returning each part of the string in one call.
*/
//const char** readString(char* input)
void readString(char* input)
{ 
    //char** masterArray = NULL; 
    /*masterArray = malloc(sizeof(char *)* 6);
    for(int i = 0; i < 6; i++)
    {
        masterArray[i] = malloc(sizeof(char)*10);
        if(masterArray[i] == NULL)
        {
            perror("Memory cannot accomodate any more allocations of this size!\n****Exiting now****");
            exit(EXIT_FAILURE);
        }
    }*/
    int i = 0;
    char* token;
    token = strtok(input, " ");
    while(token != NULL)
    {
        strcpy(info.tokens[i], token);
        token = strtok(NULL, " ");
        i++;
    }
    for(int i = 0; i < 6; i++)
    {
        printf("%s", info.tokens[i]);
    }
    printf("\n");
    //return masterArray;
}
/*This function takes the instruction string generated elsewhere and returns a corresponging integer for ease of use in instrcution recognition logic
*/
int instRecognize(char *inst)
{
    data.isI = false;
    data.isR = false;
    data.isJ = false;
    data.isB = false;
    data.isMem = false;
    data.syscalled = false;
    if(strcmp(inst, "j") == 0 || strcmp(inst, "J") == 0)
    {
        data.isJ = true;
        data.isR = false;
        data.isI = false;
        data.isMem = false;
        return 2;
    }
    else if(strcmp(inst, "sll") == 0 || strcmp(inst, "SLL") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 0;
    }
    else if(strcmp(inst, "bltz") == 0 || strcmp(inst, "BLTZ") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 1;
    }
    else if(strcmp(inst, "bgez") == 0 || strcmp(inst, "BGEZ") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 1;
    }
    else if(strcmp(inst, "srl") == 0 || strcmp(inst, "SRL") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 2;
    }
    else if(strcmp(inst, "sra") == 0 || strcmp(inst, "SRA") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 3;
    }
    else if(strcmp(inst, "jal") == 0 || strcmp(inst, "JAL") == 0)
    {
        data.isJ = true;
        data.isR = false;
        data.isI = false;
        data.isMem = false;
        return 3;
    }
    else if(strcmp(inst, "addi") == 0 || strcmp(inst, "ADDI") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = false;
        return 8;
    }
    else if(strcmp(inst, "jr") == 0 || strcmp(inst, "JR") == 0)
    {
        data.isJ = true;
        data.isR = false;
        data.isI = false;
        data.isMem = false;
        return 8;
    }
    else if(strcmp(inst, "jalr") == 0 || strcmp(inst, "JALR") == 0)
    {
        data.isJ = true;
        data.isR = false;
        data.isI = false;
        data.isMem = false;
        return 9;
    }
    else if(strcmp(inst, "addiu") == 0 || strcmp(inst, "ADDIU") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = false;
        return 9;
    }
    else if(strcmp(inst, "andi") == 0 || strcmp(inst, "ANDI") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = false;
        return 12;
    }
    else if(strcmp(inst, "ori") == 0 || strcmp(inst, "ORI") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = false;
        return 13;
    }
    else if(strcmp(inst, "xori") == 0 || strcmp(inst, "XORI") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = false;
        return 14;
    }
    else if(strcmp(inst, "mfhi") == 0 || strcmp(inst, "MFHI") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 16;
    }
    else if(strcmp(inst, "mthi") == 0 || strcmp(inst, "MTHI") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 17;
    }
    else if(strcmp(inst, "mflo") == 0 || strcmp(inst, "MFLO") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 18;
    }
    else if(strcmp(inst, "mtlo") == 0 || strcmp(inst, "MTLO") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 19;
    }
    else if(strcmp(inst, "slti") == 0 || strcmp(inst, "SLTI") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = false;
        return 10;
    }
    else if(strcmp(inst, "mult") == 0 || strcmp(inst, "MULT") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 24;
    }
    else if(strcmp(inst, "multu") == 0 || strcmp(inst, "MULTU") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 25;
    }
    else if(strcmp(inst, "div") == 0 || strcmp(inst, "DIV") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 26;
    }
    else if(strcmp(inst, "divu") == 0 || strcmp(inst, "DIVU") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 27;
    }
    else if(strcmp(inst, "add") == 0 || strcmp(inst, "ADD") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 32;
    }
    else if(strcmp(inst, "addu") == 0 || strcmp(inst, "ADDU") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 33;
    }
    else if(strcmp(inst, "sub") == 0 || strcmp(inst, "SUB") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 34;
    }
    else if(strcmp(inst, "subu") == 0 || strcmp(inst, "SUBU") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 35;
    }
    else if(strcmp(inst, "and") == 0 || strcmp(inst, "AND") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 36;
    }
    else if(strcmp(inst, "or") == 0 || strcmp(inst, "OR") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 37;
    }
    else if(strcmp(inst, "xor") == 0 || strcmp(inst, "XOR") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 38;
    }
    else if(strcmp(inst, "nor") == 0 || strcmp(inst, "NOR") == 0)
    {
        data.isJ = false;
        data.isR = true;
        data.isI = false;
        data.isMem = false;
        return 39;
    }
    else if(strcmp(inst, "lw") == 0 || strcmp(inst, "LW") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = true;
        return 35;
    }
    else if(strcmp(inst, "lb") == 0 || strcmp(inst, "LB") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = true;
        return 16;
    }
    else if(strcmp(inst, "lh") == 0 || strcmp(inst, "LH") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = true;
        return 17;
    }
    else if(strcmp(inst, "lui") == 0 || strcmp(inst, "LUI") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = false;
        return 15;
    }
    else if(strcmp(inst, "sw") == 0 || strcmp(inst, "SW") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = true;
        return 43;
    }
    else if(strcmp(inst, "sb") == 0 || strcmp(inst, "SB") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = true;
        return 40;
    }
    else if(strcmp(inst, "sh") == 0 || strcmp(inst, "SH") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = true;
        return 41;
    }
    else if(strcmp(inst, "slt") == 0 || strcmp(inst, "SLT") == 0)
    {
        data.isI = false;
        data.isR = true;
        data.isJ = false;
        data.isMem = false;
        return 42;
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
        data.isMem = false;
        return 5;
    }
    else if(strcmp(inst, "blez") == 0 || strcmp(inst, "BLEZ") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = false;
        return 6;
    }
    else if(strcmp(inst, "bgtz") == 0 || strcmp(inst, "BGTZ") == 0)
    {
        data.isI = true;
        data.isR = false;
        data.isJ = false;
        data.isMem = false;
        return 7;
    }
    else if(strcmp(inst, "syscall") == 0 || strcmp(inst, "SYSCALL") == 0)
    {
        data.isI = false;
        data.isR = false;
        data.isJ = false;
        data.isMem = false;
        data.syscalled = true;
        return 100;
    }
    else
    {
        data.isI = false;
        data.isR = false;
        data.isJ = false;
        data.isMem = false;
        return 1000;
    }    
}
/*This instruction takes the first part of the instruction (the beginning of the string until a space is reached)
and using this information formulates the opcode and/or funct.
*/
void instToBin(char* input)
{
    switch(instRecognize(input))
    {
        //SLL
        case 0:
        {
            if(data.isR == true)
            {
                strcpy(data.opcode, "000000");
                strcpy(data.funct, "000000");
                break;
            }
        }
        case 1:
        {
            if(data.isR == true)
            {
                strcpy(data.opcode, "000001");
                strcpy(data.rt, "00001");
                break;
            }
        }
        //j-type instructions
        case 2:
        {
            if(data.isJ == true)
            {
                strcpy(data.opcode, "000010");
                break;
            }
            else if(data.isR == true)
            {
                strcpy(data.funct, "000010");
                strcpy(data.opcode, "000000");
                break;
            }

        }
        case 3:
        {
            if(data.isJ == true)
            {
                strcpy(data.opcode, "000011");
                break;
            }
            else if(data.isR == true)
            {
                strcpy(data.funct, "000011");
                strcpy(data.opcode, "000000");
                break;
            }
        }
        //i-type instructions
        case 4: 
        {
            //Logic needed for cases where I and R type instructions share an opcode and funct
            if(data.isI == true)
            {
                strcpy(data.opcode, "000100");
                break;
            }
        }
        case 5: 
        {
            if(data.isI == true)
            {
                strcpy(data.opcode, "000101");
                break;
            }
        }
        case 6:
        {
            if(data.isI == true)
                {strcpy(data.opcode, "000110");
                break;}
        }
        case 7: 
        {
            if(data.isI == true)
            {
                strcpy(data.opcode, "000111");
                break;
            }
        }
        case 8:
        {
            if(data.isI == true)
                {strcpy(data.opcode, "001000");
                break;}
            else if(data.isR == true)
            {
                strcpy(data.funct, "001000");
                strcpy(data.opcode, "000000");
                break;
            }
        }
        case 9:
        {
            if(data.isI == true)
                {strcpy(data.opcode, "001001");
                break;}
            else if(data.isR == true)
            {
                strcpy(data.funct, "001001");
                strcpy(data.opcode, "000000");
                break;
            }
        }
        case 10:
        {
            if(data.isI == true)
                {strcpy(data.opcode, "001010");
                break;}
        }
        case 12:
        {
            if(data.isI == true)
                {strcpy(data.opcode, "001100");
                break;}
            else if(data.isR == true)
            {
                strcpy(data.funct, "001100");
                strcpy(data.opcode, "000000");
                break;
            }
        }
        case 13:
        {
            if(data.isI == true)
            {
                strcpy(data.opcode, "001101");
                break;
            }
        }
        case 14:
        {
            if(data.isI == true)
            {    strcpy(data.opcode, "001110");
                break;}
        }
        case 15:
        {
            if(data.isI == true)
            {    strcpy(data.opcode, "001111");
                break;}
        }
        case 16:
        {
            if(data.isI == true)
            {    strcpy(data.funct, "010000");
                break;}
        }
        case 17:
        {
            if(data.isI == true)
            {    strcpy(data.funct, "010001");
                break;}
        }
        case 18:
        {
            if(data.isR == true)
            {
                strcpy(data.funct, "010010");
                strcpy(data.opcode, "000000");
                break;
            }
        }
        case 19:
        {
            if(data.isR == true)
            {
                strcpy(data.funct, "010011");
                strcpy(data.opcode, "000000");
                break;
            }
        }
        case 24:
        {
            if(data.isR == true)
            {    
                strcpy(data.funct, "011000");
                strcpy(data.opcode, "000000");
                break;
            }
        }
        case 25:
        {
            if(data.isR == true)
            {    strcpy(data.funct, "011001");
                strcpy(data.opcode, "000000");
                break;}
        }
        case 26:
        {
            if(data.isR == true)
            {    strcpy(data.funct, "011010");
                strcpy(data.opcode, "000000");
                break;}
        }
        case 27:
        {
            if(data.isR == true)
            {    strcpy(data.funct, "011011");
                strcpy(data.opcode, "000000");
                break;}
        }
        case 32:
        {
            if(data.isI == true)
            {
                strcpy(data.opcode, "100000");
                break;
            }
            else if(data.isR == true)
            {
                strcpy(data.opcode, "000000");
                strcpy(data.funct, "100000");
                break;
            }
        }
        case 33:
        {
            if(data.isI == true)
            {
                strcpy(data.opcode, "100001");
                break;
            }
            else if(data.isR == true)
            {
                strcpy(data.opcode, "000000");
                strcpy(data.funct, "100001");
                break;
            }
        }
        case 34:
        {
            if(data.isR == true)
            {
                strcpy(data.opcode, "000000");
                strcpy(data.funct, "100010");
                break;
            }
        }
        case 35:
        {
            if(data.isI == true)
                {strcpy(data.opcode, "100011");
                break;}
            else if(data.isR == true)
            {
                strcpy(data.opcode, "000000");
                strcpy(data.funct, "");
                break;
            }
        }
        case 36:
        {
            if(data.isR == true)
            {
                strcpy(data.opcode, "000000");
                strcpy(data.funct, "100100");
                break;
            }
        }
        case 37:
        {
            if(data.isR == true)
            {
                strcpy(data.opcode, "000000");
                strcpy(data.funct, "100101");
                break;
            }
        }
        case 38:
        {
            if(data.isR == true){
                strcpy(data.opcode, "000000");
                strcpy(data.funct, "100110");
                break;
            }
        }
        case 39:
        {
            if(data.isR == true)
            {
                strcpy(data.opcode, "000000");
                strcpy(data.funct, "100111");
                break;
            }
        }
        case 40:
        {
            if(data.isI == true)
                {strcpy(data.opcode, "101000");
                break;}
        }
        case 41:
        {
            if(data.isI == true)
                {strcpy(data.opcode, "101001");
                break;}
        }
        case 42:
        {
            if(data.isR == true)
            {
                strcpy(data.opcode, "000000");
                strcpy(data.funct, "101010");
                break;
            }
        }
        case 43:
        {
            if(data.isI == true)
                {strcpy(data.opcode, "101011");
                break;}
        }
        case 100:
        {
            strcpy(data.opcode, "000000");
            strcpy(data.rd, "00000");
            strcpy(data.rs, "00000");
            strcpy(data.rt, "00000");
            strcpy(data.shamt, "00000");
            strcpy(data.funct, "001100");
            data.syscalled = true;
            break;
        }
    }
    printf("INSTTOBIN call: opcode is %s\n", data.opcode);
    printf("INSTTOBIN call: funct is %s\n", data.funct);
}
/* This function converts each part of the string that represents a register into its corresponding binary value.
It takes in the text representation of a MIPS instruction and operates on this data to return the proper binary
*/
const char* regToBin(char* input)
{
     if((strcmp(input,"$zero,") == 0) || (strcmp(input,"$zero") == 0) || (strcmp(input,"$zero\n") == 0)){
        return "00000";
    }


     if(strcmp(input, "$at,") == 0 || strcmp(input,"$at") == 0 || strcmp(input,"$at\n") == 0){
        return "00001";
    }

    //v registers
     if(strcmp(input, "$v0,") == 0 || strcmp(input, "$v0,") == 0 || strcmp(input, "$v0\n") == 0){
        return "00010";
    }

     if(strcmp(input, "$v1,") == 0 || strcmp(input, "$v1") == 0 || strcmp(input, "$v1\n") == 0){
        return "00011";
    }

    //a registers
     if(strcmp(input, "$a0,") == 0 || strcmp(input, "$a0") == 0 || strcmp(input, "$a0\n") == 0){
        return "00100";
    }

     if(strcmp(input, "$a1,") == 0 || strcmp(input, "$a1") == 0 || strcmp(input, "$a1\n") == 0){
        return "00101";
    }

     if(strcmp(input, "$a2,") == 0 || strcmp(input, "$a2") == 0 || strcmp(input, "$a2\n") == 0){
        return "00110";
    }

     if(strcmp(input, "$a3,") == 0 || strcmp(input, "$a3") == 0 || strcmp(input, "$a3\n") == 0){
        return "00111";
    }

    //t registers
    if(strcmp(input, "$t0,") == 0 || strcmp(input, "$t0") == 0 || strcmp(input, "$t0\n") == 0){
        return "01000";
    }

     if(strcmp(input, "$t1,") == 0 || strcmp(input, "$t1") == 0 || strcmp(input, "$t1\n") == 0){
        return "01001";
    }

     if(strcmp(input, "$t2,") == 0 || strcmp(input, "$t2") == 0 || strcmp(input, "$t2\n") == 0){
        return "01010";
    }

     if(strcmp(input, "$t3,") == 0 || strcmp(input, "$t3") == 0 || strcmp(input, "$t3\n") == 0){
        return "01011";
    }

     if(strcmp(input, "$t4,") == 0 || strcmp(input, "$t4") == 0 || strcmp(input, "$t4\n") == 0){
        return "01100";
    }

     if(strcmp(input, "$t5,") == 0 || strcmp(input, "$t5") == 0 || strcmp(input, "$t5\n") == 0){
        return "01101";
    }

     if(strcmp(input, "$t6,") == 0 || strcmp(input, "$t6") == 0 || strcmp(input, "$t6\n") == 0){
        return "01110";
    }
     if(strcmp(input, "$t7,") == 0 || strcmp(input, "$t7") == 0 || strcmp(input, "$t7\n") == 0){
        return "01111";
    }
    

    //s registers
     if(strcmp(input, "$s0,") == 0 || strcmp(input, "$s0") == 0 || strcmp(input, "$s0\n") == 0){
        return "10000";
    }

     if(strcmp(input, "$s1,") == 0 || strcmp(input, "$s1") == 0 || strcmp(input, "$s1\n") == 0){
        return "10001";
    }

     if(strcmp(input, "$s2,") == 0 || strcmp(input, "$s2") == 0 || strcmp(input, "$s2\n") == 0){
        return "10010";
    }

     if(strcmp(input, "$s3,") == 0 || strcmp(input, "$s3") == 0 || strcmp(input, "$s3\n") == 0){
        return "10011";
    }

     if(strcmp(input, "$s4,") == 0 || strcmp(input, "$s4") == 0 || strcmp(input, "$s4\n") == 0){
        return "10100";
    }

     if(strcmp(input, "$s5,") == 0 || strcmp(input, "$s5") == 0 || strcmp(input, "$s5\n") == 0){
        return "10101";
    }

     if(strcmp(input, "$s6,") == 0 || strcmp(input, "$s6") == 0 || strcmp(input, "$s6\n") == 0){
        return "10110";
    }

     if(strcmp(input, "$s7,") == 0 || strcmp(input, "$s7") == 0 || strcmp(input, "$s7\n") == 0){
        return "10111";
    }
    
     //t registers
     if(strcmp(input, "$t8,") == 0 || strcmp(input, "$t8") == 0 || strcmp(input, "$t8\n") == 0){
        return "11000";
    }

    if(strcmp(input, "$t9,") == 0 || strcmp(input, "$t9") == 0 || strcmp(input, "$t9\n") == 0){
        return "11001";
    }

    //k registers
    if(strcmp(input, "$k0,") == 0 || strcmp(input, "$k0") == 0 || strcmp(input, "$k0\n") == 0){
        return "11010";
    }

    if(strcmp(input, "$k1,") == 0 || strcmp(input, "$k1") == 0 || strcmp(input, "$k1\n") == 0){
        return "11011";
    }

    if(strcmp(input, "$gp,") == 0 || strcmp(input, "$gp") == 0 || strcmp(input, "$gp\n") == 0){
        return "11100";
    }

    if(strcmp(input, "$sp,") == 0 || strcmp(input, "$sp") == 0 || strcmp(input, "$sp\n") == 0){
        return "11101";
    }

    if(strcmp(input, "$fp,") == 0 || strcmp(input, "$fp") == 0 || strcmp(input, "$fp\n") == 0){
        return "11110";
    }

    if(strcmp(input, "$ra,") == 0 || strcmp(input, "$ra") == 0 || strcmp(input, "$ra\n") == 0){
        return "11111";
    }
    return "00000";

}


/*This function converts the hexadecimal or Decimal immediate value into a binary representation and returns that as a string.
This will only be used in certain instructions (i.e. immediate or I-type instructions)
*/
void immToBin(char* input)
{
    char *hex= "0x";
    char* binString= malloc(17*sizeof(char));
    int i = 2;
    int j = 6;
    //If first two characters of both strings are "0x", then handle as Hex Instruction
    if(strncmp(input, hex, 2) == 0)
    {
        if(input[strlen(input)] == ')')
        {
            j = strlen(input) - 5;
        }
        for(i = j; i > 2; i--) //convert the hex into binary values
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
                case '\0':
                    strcat(binString, "0000");
                    break;
                default:
                    strcat(binString, "0000");
                    break;
            }
            if(input[i] == '(')
            {
                strncpy(data.rs, &input[strlen(input)-3], 3);
            }
        }
        strcpy(data.imm, binString);
        free(binString);
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
            strcpy(data.imm, binString);
      }

}
/*this will convert the target address used in j-type instructions to a binary string that can be concatenated 
onto the end of the rest of the binary string.
*/
const char* tarToBin(char* input)
{
    char *hex= "0x";
    char* binString= (char *)malloc(27*sizeof(char));
    //If first two characters of both strings are "0x", then handle as Hex Instruction
    if(strncmp(input, hex, 2) == 0){
    for(int i = 2; i < 14; i++) //convert the hex into binary values
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
    printf("TARTOBIN call: %s\n", binString);
	return binString;
    }
    else
    { 
        printf("TARTOBIN call: %s\n", binString);
        return binString;
    }
}
/*This function will concatenate all the strings generated by the other functions into one long string that can 
transform all of them into one readable binary string that can be converted into a hexadecimal number. 
*/
//const char* stringToBin(char* input)
const char* stringToBin()
{
    char* binary = malloc(33*sizeof(char));
    instToBin(info.tokens[0]);
    if(data.isR == true)
    {
        strcpy(data.rd, regToBin(info.tokens[1]));
        strcpy(data.rs, regToBin(info.tokens[2]));
        strcpy(data.rt, regToBin(info.tokens[3]));
        strcpy(data.shamt, regToBin(info.tokens[4]));
        strcat(binary, data.opcode);
        strcat(binary, data.rs);
        strcat(binary, data.rt);
        strcat(binary, data.rd);
        strcat(binary, data.shamt);
        strcat(binary, data.funct);
        strcpy(binary, (char *)StringPadRight(binary));
        printf("STRINGTOBIN R-type call: %s\n", binary);
        return binary;
    }
    else if(data.isI == true)
    {
        strcpy(data.rt, regToBin(info.tokens[1]));
        strcpy(data.rs, regToBin(info.tokens[2]));
        immToBin(info.tokens[3]);
        strcat(binary, data.opcode);
        strcat(binary, data.rs);
        strcat(binary, data.rt);
        strcat(binary, data.imm);
        strcpy(binary, (char *)StringPadRight(binary));
        printf("STRINGTOBIN I-type call: %s\n", binary);
        return binary;
    }
    else if(data.isMem == true)
    {
        strcpy(data.rt, regToBin(info.tokens[1]));
        //strcpy(data.rs, regToBin(info.tokens[2]));
        immToBin(info.tokens[2]);
        strcat(binary, data.opcode);
        strcat(binary, data.rs);
        strcat(binary, data.rt);
        strcat(binary, data.imm);
        strcpy(binary, (char *)StringPadRight(binary));
        printf("STRINGTOBIN I-type call: %s\n", binary);
        return binary;
    }
    else if(data.isJ == true)
    {
        strcpy(data.target, tarToBin(info.tokens[1]));
        strcat(binary, data.opcode);
        strcat(binary, data.target);
        strcpy(binary, (char *)StringPadRight(binary));
        printf("STRINGTOBIN J-type call: %s\n", binary);
        return binary;
    }
    else if(data.syscalled == true)
    {
        strcat(binary, data.opcode);
        strcat(binary, data.rs);
        strcat(binary, data.rt);
        strcat(binary, data.rd);
        strcat(binary, data.shamt);
        strcat(binary, data.funct);
        strcpy(binary, (char *)StringPadRight(binary));
        printf("STRINGTOBIN SYSCALL call: %s\n", binary);
        return binary;
    }
    return binary;
}
/*This function will convert the final string product of the string to bin function into a hexadecimal number. 
It is possible for this function to convert any binary string of any length into a hexadecimal so long as it
can fit within a 32-bit hexadecimal.
*/
uint32_t binToHex(char* input)
{
    uint32_t result = 0;
    int size = 0;
    size = strlen(input);
	for(int i = size - 1; i >= 0; i--) //iterate through each character of the string
	{
		if(input[i] == '1')
		{
			result += pow(2, ((size - 1)-i)); //add the value of each place raised to the proper value. i.e. the first digit is added as 2 raised to the 0th power and the third digit is added as 2 raised to the 2nd power
		}
	}
    printf("binToHex Call: %08X\n", result);
	return result;
}
void initialize()
{
    data.opcode = malloc(7*sizeof(char));
    data.rd = malloc(6*sizeof(char));
    data.rs = malloc(6*sizeof(char));
    data.rt = malloc(6*sizeof(char));
    data.shamt = malloc(6*sizeof(char));
    data.funct = malloc(7*sizeof(char));
    data.imm = malloc(17*sizeof(char));
    data.target = malloc(27*sizeof(char));
    data.isR = false;
    data.isI = false;
    data.isJ = false;
    data.isB = false;
    data.syscalled = false;
    info.tokens = malloc(6*sizeof(char*));
    for(int i = 0; i < 6; i++)
    {
        info.tokens[i] = malloc(10*sizeof(char));
    }
}
char* StringPadRight(char* input)
{
    int len = 32;
    if(len >= strlen(input))
    {
        return input;
    }
    for(int i = 0; i < len; i++)
    {
        strcat(input, "0");
    }
    return input;
}
int main(int argc,char* argv[])
{
    FILE* fp;
    FILE* writefile;
    char* progFile = NULL;
    progFile = malloc(strlen(argv[1])*sizeof(char)); //make sure the 
    progFile = argv[1];
    fp = fopen(progFile, "r");
    writefile = fopen("output.txt", "w"); //create the file for output 
    char* inString = malloc(24*sizeof(char));
    char* binString;
    initialize();
    //needs to read from the file line by line to convert each line into a hex code that can be printed into a file. 
    printf("****Begin file read****\n");
    while(fgets(inString, 24, fp))
    {
        puts(inString);
        readString(inString);
        binString = (char *)stringToBin();
        fprintf(writefile, "%08X\n", (uint32_t)(binToHex((char *)binString)));
        free(binString);
    }
    free(inString);
    fclose(fp);
    fclose(writefile);
}