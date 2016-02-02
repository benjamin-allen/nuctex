/*------------------------------------------------------------------------------
| NuCTex	| io.h
| Author	| Benjamin A - Nullsrc
| Created	| 22 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Prototype declarations for the input functions
|-------------------------------------------------------------------------------
| CRITICAL	| Though callCommand() is declared here, it is defined in gamef.c
\-----------------------------------------------------------------------------*/
#ifndef NULLSRC_IO_HEADER
#define NULLSRC_IO_HEADER

#include "items.h"

#define ANSI_RED		"\x1b[31m"
#define ANSI_GREEN		"\x1b[32m"
#define ANSI_YELLOW		"\x1b[33m"
#define ANSI_BLUE		"\x1b[34m"
#define ANSI_MAGENTA	"\x1b[35m"
#define ANSI_CYAN		"\x1b[36m"
#define ANSI_RESET		"\x1b[0m"

// Input Functions
char* getInput();
char* removeNewline(char*);

// Output Functions
void printMessage(char*);
void printMessageC(char*, char*);
void printMonster(char*);
void printDamage(int, char*);
void printStats(int);
void printInventory(Inventory, char*);
void printEquipment(Equipment, char*);
void describeItem(Item*);

// Error Handling functions
void logError(char*, const char*);
void logStart();

// Parser Functions
void parseInput(char*);
void callCommand(char*, char*); //Defined in gamef.c

// String Comparison Functions
int checkOne(char*, char*);
int checkTwo(char*, char*, char*);
int checkThree(char*, char*, char*, char*);
int checkFour(char*, char*, char*, char*, char*);

#endif /* NULLSRC_IO_HEADER */
