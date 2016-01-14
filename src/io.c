/*------------------------------------------------------------------------------
| NuCTex	| io.c
| Author	| Benjamin A - Nullsrc
| Created	| 22 November, 2015
| Changed	| 7 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Implement member functions of io.h
\-----------------------------------------------------------------------------*/

#include "io.h"
#include <stdio.h>
#include <string.h>

#define ANSI_RED		"\x1b[31m"
#define ANSI_GREEN		"\x1b[32m"
#define ANSI_YELLOW		"\x1b[33m"
#define ANSI_BLUE		"\x1b[34m"
#define ANSI_MAGENTA	"\x1b[35m"
#define ANSI_CYAN		"\x1b[36m"
#define ANSI_RESET		"\x1b[0m"

char command[64]; 	// filewide char array to be used to command parsing

/* printMessage() ---
print the c-string passed. Can be called with printMessage("This is a string")
as well. */
void printMessage(char* message) {
	char tempText[2400];
	strcpy(tempText, message);
	int i = 0;
	int delim = 80;
	for(; tempText[i] != '\0' ; i++) {
		if(i == delim && i > 0) {
			if(tempText[i] == ' ') {
				tempText[i] = '\n';
				delim += 80;
			}
			else {
				int j = i;
				int k = 0;
				while(tempText[j] != ' ') {
					j--;
					k++;
				}
				tempText[j] = '\n';
				delim += (80-k);
			}
		}
	}
	printf("%s\n", tempText);
}

void printMessageC(char* message, char* color) {
	char tempText[2400];
	strcpy(tempText, message);
	int i = 0;
	int delim = 80;
	for(; tempText[i] != '\0' ; i++) {
		if(i == delim && i > 0) {
			if(tempText[i] == ' ') {
				tempText[i] = '\n';
				delim += 80;
			}
			else {
				int j = i;
				int k = 0;
				while(tempText[j] != ' ') {
					j--;
					k++;
				}
				tempText[j] = '\n';
				delim += (80-k);
			}
		}
	}
	printf("%s%s%s\n", color, tempText, ANSI_RESET);
}

/* printMonster(char*) ---
   Prints the name passed to it as a usable output to be used in the look
   command */
void printMonster(char* name) {
	printf("There is a %s here. ", name);
}

/* printDamage(int, char*) ---
   Given int damage and the name of the creature, print out how much
   damage a player has done to monster */
void printDamage(int damage, char* creatureName) {
	printf("You did %i damage to the %s!\n", damage, creatureName);
}

void printStats(int health) {
	printf("| %s%i%s HP |\n", ANSI_GREEN, health, ANSI_RESET);
}

/* getInput() ---
capture input from the command line. As a nice touch, waits for the user. */
char* getInput() {
	/* make sure pLine points to something that will
	   not go out of scope. Bad things happen if it does */
	char* pLine = command;	

	printf(ANSI_CYAN ">> " ANSI_RESET);
	/* retrieve input from stdin (user input to the
	   CLI) and save it to pLine. Input cannot be
	   longer than 64 bytes */
	fgets(pLine, 64, stdin);	
	
	/* remove the newline from the fgets input if there is input. Note that this
	   will leave the newline if no string is specified before the newline (i.e.
	   the string looks like "\n\0..." */
	strtok(pLine, "\n");

	return pLine;
};

/* parseInput(char*) ---
   Given a single string, split it into a verb and noun to be used in the
   callCommand function. If a null is found in the verb, return without
   attempting to parse the string, as any attempt to do so will cause
   segmentation faults. If there is no noun, set the noun string to equal "!n".
   If three words are sent, everything after the second space will be saved to
   an overflow variable and discarded upon the next game loop */
void parseInput(char* input) {
	char* v = strtok(input, " \n");
	if(v == NULL) {
		return;
	}
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

/* checkOne/Two/Three/Four(char*, ...) ---
   The check functions are a wrapper for strcmp systems, and are meant to be
   used in the place of multiple strcmp operations as a space and time-saving
   operation */
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


