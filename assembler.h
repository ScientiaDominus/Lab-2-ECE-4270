#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
    char tokens[6][10];
} strings;

strings info;

//might use a global version of this instead of an array of character strings to get each of the elements of the binary string
//To be determined however, currently still working with a character array.
typedef struct {
    char opcode[6];
    char rd[5];
    char rs[5];
    char rt[5];
    char shamt[5];
    char funct[6];
    char imm[16];
    bool isR;
    bool isJ;
    bool isI;
    bool isB;
} bits; 

bits data;

const char** readString(char* ); 
void instToBin(char *);
const char* regToBin(char *);
const char* immToBin(char *);
const char* tarToBin(char *); 
//const char* stringToBin(char *);
void stringToBin();
int instRecognize(char *);
uint32_t binToHex(char* input);

