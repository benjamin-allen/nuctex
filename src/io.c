/*------------------------------------------------------------------------------
| NuCTex	| io.c
| Author	| Benjamin A - Nullsrc
| Created	| 22 November, 2015
| Changed	| 1 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Implement member functions of io.h
\-----------------------------------------------------------------------------*/

#include "io.h"
#include "gamef.h"
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

void callCommand(char* verb, char* noun) {
	// quit command
	if(checkOne(verb, "quit") == 0) {
		quit();
	}

	else if(checkOne(verb, "look") == 0) {
		if(checkThree(noun, "!n", "around", "room") == 0) {
			look(player.actorPos);
		}
		else if(checkOne(noun, "me") == 0) {
			printMessage("You try to look at yourself, but you cannot see");
			printMessage("inside your brain to view your stats.");
		}
	}

	else if(checkOne(verb, "go") == 0) {
		if(checkTwo(noun, "north", "n") == 0) {
			move(&player, 'n');
		}
		else if(checkTwo(noun, "south", "s") == 0) {
			move(&player, 's');
		}
		else if(checkTwo(noun, "east", "e") == 0) {
			move(&player, 'e');
		}
		else if(checkTwo(noun, "west", "w") == 0) {
			move(&player, 'w');
		}
		else {
			printMessage("You can't go that way!");
		}
	}
	else if(checkOne(verb, "kill") == 0) {
		int i = 0;
		while(i < MAX_MONSTERS) {
			if(checkOne(noun, monster[i].name) == 0 &&
			   player.actorPos == monster[i].actorPos) {
				combat(&player, &monster[i]);
			}
			else {
				printMessage("There is no such monster here");
			}
			i++;
		}
	}

	// default "no-match" response
	else {
		printMessage("Invalid command!");
	}
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
