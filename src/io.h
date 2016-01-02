/*------------------------------------------------------------------------------
| NuCTex	| io.h
| Author	| Benjamin A - Nullsrc
| Created	| 22 November, 2015
| Changed	| 1 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Prototype declarations for the input functions
\-----------------------------------------------------------------------------*/


// Input Functions
char* getInput();
char* removeNewline(char*);

// Output Functions
void printMessage(char*);
void printMonster(char*);
void printDamage(int, char*);

// Parser Functions
void parseInput(char*);

// String Comparison Functions
int checkOne(char*, char*);
int checkTwo(char*, char*, char*);
int checkThree(char*, char*, char*, char*);
int checkFour(char*, char*, char*, char*, char*);
