/*------------------------------------------------------------------------------
| NuCTex	| io.c
| Author	| Benjamin A - Nullsrc
| Created	| 22 November, 2015
| Changed	| 1 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Implement member functions of io.h
\-----------------------------------------------------------------------------*/

#include "io.h"
#include <stdio.h>
#include <string.h>

char command[64]; 	// filewide char array to be used to command parsing

/* printMessage() ---
print the c-string passed. Can be called with printMessage("This is a string")
as well. */
void printMessage(char* message) {
	printf("%s\n", message);	// append a newline char before printing
}

void printMonster(char* name) {
	printf("There is a %s here. ", name);
}

void printDamage(int damage, char* creatureName) {
	printf("You did %i damage to the %s!\n", damage, creatureName);
}

/* removeNewline() ---
remove the extraneous newline char from the fgets output. */
char* removeNewline(char* line) {
	char* nlpos;	// temporary pointer to traverse the array

	/* IF the comparison between pos and a character (in this case, newline) 
	does not return false, change that character to a null. */
	if((nlpos=strchr(line, '\n')) != NULL) {
		*nlpos = '\0';
	}
}

/* getInput() ---
capture input from the command line. As a nice touch, waits for the user. */
char* getInput() {
	char* pLine = command;	/* make sure pLine points to something that will
							not go out of scope. Bad things happen if it does */

	fgets(pLine, 64, stdin);	/* retrieve input from stdin (user input to the
								CLI) and save it to pLine. Input cannot be
								longer than 64 bytes */

	removeNewline(pLine);	/* remove the extraneous newline saved by fgets.
							This makes various parsing actions far easier. */

	return pLine;
};


void parseInput(char* input) {
	char* v = strtok(input, " \n");
	char* n = strtok(NULL, " \n");
	char* overflow = strtok(NULL, " \n");

	if(overflow != NULL) {
		printMessage("Invalid command!");
		return;
	}

	if(n == NULL) {
		n = "!n";
	}

	callCommand(v, n);
}

int checkOne(char* toCheck, char* match) {
	if(strcmp(toCheck, match) == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int checkTwo(char* toCheck, char* match, char* matchTwo) {
	if(strcmp(toCheck, match) == 0 || strcmp(toCheck, matchTwo) == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int checkThree(char* toCheck, char* match, char* matchTwo, char* matchThree) {
	if(strcmp(toCheck, match) == 0 || strcmp(toCheck, matchTwo) == 0 ||
	   strcmp(toCheck, matchThree) == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int checkFour(char* toCheck, char* match, char* matchTwo, char* matchThree,
          char* matchFour) {
	if(strcmp(toCheck, match) ==0 || strcmp(toCheck, matchTwo) == 0 ||
	   strcmp(toCheck, matchThree) == 0 || strcmp(toCheck, matchFour) == 0) {
		return 0;
	}
	else {
		return 1;
	}
}
