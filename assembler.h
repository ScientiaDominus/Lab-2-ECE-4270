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
    char opcode[7];
    char rd[6];
    char rs[6];
    char rt[6];
    char shamt[6];
    char funct[7];
    char imm[17];
    char target[27];
    bool isR;
    bool isJ;
    bool isI;
    bool isB;
} bits; 

bits data;

void readString(char* ); 
void instToBin(char *);
const char* regToBin(char *);
const char* immToBin(char *);
const char* tarToBin(char *); 
//const char* stringToBin(char *);
const char* stringToBin();
int instRecognize(char *);
uint32_t binToHex(char* input);

