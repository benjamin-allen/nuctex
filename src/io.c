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
		printf("Invalid command!");
		return;
	}

	if(n == NULL) {
		n = "!n";
	}

	callCommand(v, n);
}

void callCommand(char* verb, char* noun) {
	// quit command
	if(strcmp(verb, "quit") == 0) {	// strcmp returns 0 on truth
		quit();
	}

	else if(strcmp(verb, "look") == 0) {
		if(strcmp(noun, "around") == 0 || strcmp(noun, "room") == 0) {
			look(player.actorPos);
		}
		else if(strcmp(noun, "me") == 0) {
			printMessage("You try to look at yourself, but you cannot see");
			printMessage("inside your brain to view your stats.");
		}
	}

	else if(strcmp(verb, "go") == 0) {
		if(strcmp(noun, "north") == 0 || strcmp(noun, "n") == 0) {
			move(&player, 'n');
		}
		else if(strcmp(noun, "south") == 0 || strcmp(noun, "s") == 0) {
			move(&player, 's');
		}
		else if(strcmp(noun, "east") == 0 || strcmp(noun, "e") == 0) {
			move(&player, 'e');
		}
		else if(strcmp(noun, "west") == 0 || strcmp(noun, "w") == 0) {
			move(&player, 'w');
		}
		else {
			printMessage("You can't go that way!");
		}
	}

	// default "no-match" response
	else {
		printMessage("Invalid Command!");
	}
}
