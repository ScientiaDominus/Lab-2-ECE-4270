#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
//might use a global version of this instead of an array of character strings to get each of the elements of the binary string
//To be determined however, currently still working with a character array.
typedef struct {
    char opcode[10];
    char rd[10];
    char rs[10];
    char rt[10];
    char shamt[10];
    char funct[10];
    bool isR;
    bool isJ;
    bool isI;
} bits; 

bits data;

const char** readString(char* ); 
const char* instToBin(char *);
const char* regToBin(char *);
const char* immToBin(char *);
const char* tarToBin(char *); 
const char* stringToBin(char *);
int instRecognize(char *);
uint32_t binToHex(char* input);

