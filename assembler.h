#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
    char** tokens;
} strings;

strings info;

//might use a global version of this instead of an array of character strings to get each of the elements of the binary string
//To be determined however, currently still working with a character array.
typedef struct {
    char* opcode;
    char* rd;
    char* rs;
    char* rt;
    char* shamt;
    char* funct;
    char* imm;
    char* target;
    bool isR;
    bool isJ;
    bool isI;
    bool isB;
    bool isMem;
    bool syscalled;
} bits; 

bits data;

void readString(char* ); 
void instToBin(char *);
const char* regToBin(char *);
void immToBin(char *);
const char* tarToBin(char *); 
//const char* stringToBin(char *);
const char* stringToBin();
int instRecognize(char *);
uint32_t binToHex(char* input);
void initialize();
char* StringPadRight(char* input);

