/*------------------------------------------------------------------------------
| NuCTex	| io.c
| Author	| Benjamin A - Nullsrc
| Created	| 22 November, 2015
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
	if(!message) {
		logError("Message expected in call; received NULL", __func__);
	}
	else {
		/* Create an array of characters that can store 30 lines, at minimum. Use
		   strcpy to copy the passed string to the array for modification */
		char tempText[2400];
		strcpy(tempText, message);
		int i = 0;
		
		/* Delim represents the number of characters that the line needs to be
		   wrapped at */
		int delim = 80;
		for(; tempText[i] != '\0' ; i++) {
			/* The code inside the if executes when i has reached the delim value.
			   This will be 80 on the first loop and it's value is variable on
			   subsequent loops */
			if(i == delim && i > 0) {
				/* This statement is used if the character at the delimiting point
				   is a space */
				if(tempText[i] == ' ') {
					tempText[i] = '\n';
					delim += 80;
				}
				/* If the character at this delimiting point is not a space, this
				   statement executes */
				else {
					int j = i;
					int k = 0;
					/* The while loop reverse traverses the array until it finds a
					   space to wrap at */
					while(tempText[j] != ' ') {
						j--;
						k++;
					}
					/* Once the loop has found a space, it is replaced with a
					   newline, and the number of characters it has to traverse
					   backwards is subtracted from the addition of 80 to delim */
					tempText[j] = '\n';
					delim += (80-k);
				}
			}
		}
		printf("%s\n", tempText);
	}
}

/* printMessageC(char*, char*) ---
   Operates in a similar manner to printMessage, but supports colorized text.
   Using the #define-ed ANSI color codes in io.h is advised, although other
   values could be given as well */
void printMessageC(char* message, char* color) {
	if(!message) {
		logError("Message expected in call; received NULL", __func__);
	}
	else if(!color) {
		logError("Color expected in call; received NULL", __func__);
	}
	else {
		/* printMessageC follows the same delimiting process as printMessage. See
		   above for documentation on the delimiting process */
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
}

/* printMonster(char*) ---
   Prints the name passed to it as a usable output to be used in the look
   command */
void printMonster(char* name) {
	if(!name) {
		logError("Name expected in call; received NULL", __func__);
	}
	else {
		printf("There is a %s here. ", name);
	}
}

/* printDamage(int, char*) ---
   Given int damage and the name of the creature, print out how much
   damage a player has done to monster */
void printDamage(int damage, char* creatureName) {
	if(!creatureName) {
		logError("Name expected in call; received NULL", __func__);
	}
	else {
		printf("You did %i damage to the %s!\n", damage, creatureName);
	}
}

/* printStats(int) ---
   Prints a players stats, given a series of integers */
void printStats(int health) {
	if(health < 0) {
		logError("Negative value given for health", __func__);
	}
	else {
		printf("| %s%i%s HP |\n", ANSI_GREEN, health, ANSI_RESET);
	}
}

/* printInventory(Inventory, char*) ---
   Prints a given inventory, and it's owner */
void printInventory(Inventory inv, char* owner) {
	int i;
	/* If the name of the inventory's owner is known and passed */
	if(owner) {
		printf("%s's possessions:\n", owner);
		/* This for loop iterates through until it hits the #define'd limit for
		   the max number of items in an inventory, checking each element first
		   for existance and then for its name if it does exist */
		for(i = 0; i < MAX_INVENTORY_AMOUNT; i++) {
			if(inv.item[i]) {
				printf("%s%i - %s%s%s\n", ANSI_YELLOW, i, ANSI_CYAN, inv.item[i]->name, ANSI_RESET);
			}
		}
	}
	/* If the name is not given, scan the inventory and assume it's a room. This
	   requires that any such use of room-scanning have the room's inventory
	   passed as an argument. This is usually done in the style of a call that
	   looks like 'printInventory(player->actorPos->inv, 0)' */
	else {
		printf("You scan the room for items...\n");
		for(i = 0; i < MAX_INVENTORY_AMOUNT; i++) {
			if(inv.item[i]) {
				printf("%s%s%s\n", ANSI_CYAN, inv.item[i]->name, ANSI_RESET);
			}
		}
	}
}

/* printEquipment(Equipment, char*) ---
   Given an actor's equipment and name, print out all elements of that actor's
   equipment, if they exist */
void printEquipment(Equipment eqp, char* owner) {
	int i;
	/* printEquipment uses the same style of check-print-iterate that
	   printInventory does. The primary difference is that several independent
	   if statements are called to check the different pointers of equipment */
	if(owner) {
		printf("%s's equipment:\n", owner);
		if(eqp.weapon) {
			printf("%s%s%s\n", ANSI_CYAN, eqp.weapon->name, ANSI_RESET);
		}
		for(i = 0; i < MAX_CLOTHING_AMOUNT; i++) {
			if(eqp.clothing[i]) {
				printf("%s%s%s\n", ANSI_CYAN, eqp.clothing[i]->name, ANSI_RESET);
			}
		}
		if(eqp.accessory) {
			printf("%s%s%s\n", ANSI_CYAN, eqp.accessory->name, ANSI_RESET);
		}
	}
}

/* describeItem(Item*) ---
   When passed the pointer to an item, print out the corresponding information
   that is associated with that item's definition */
void describeItem(Item* item) {
	// print the item's name and description
	printf("%s%s - %s%s%s\n",
	       ANSI_CYAN, item->name, ANSI_YELLOW, item->description, ANSI_RESET);
	// print the item's various stat modifiers, if they exist
	if(item->strength != 0) printf("Strength: %i\n", item->strength);
	if(item->agility != 0) printf("Agility: %i\n", item->agility);
	if(item->intelligence != 0) printf("Intelligence: %i\n", item->intelligence);
	if(item->charisma != 0) printf("Charisma: %i\n", item->charisma);

	if(itemHasFlag(item, &sharp) == 1) printf("|-This item is very sharp-|\n");
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
	if(!v) {
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

void logError(char* errdesc, const char* caller) {
	FILE *file = fopen("./dat/debug.log", "a");
	if(!file) {
		printf("ERROR: Could not open dat/debug.log in append mode");
	}
	else {
		fprintf(file, "ERROR: %s\n", errdesc);
		fprintf(file, "In function %s\n\n", caller);
		fclose(file);
		printf("An error occurred and has been logged.");
		printf(" Check dat/debug.log for more details.\n");
		printf("Your previous command may have been voided due to the error.\n");
	}
}

void logStart() {
	FILE *file = fopen("./dat/events.log", "a");
	if(!file) {
		logError("Could not open dat/events.log in append mode", __func__);
	}
	else {
		fprintf(file, "---\n");
		fprintf(file, "NuCTex started\n");
	}
}

/* checkOne/Two/Three/Four(char*, ...) ---
   The check functions are a wrapper for strcmp systems, and are meant to be
   used in the place of multiple strcmp operations as a space and time-saving
   operation */
int checkOne(char* toCheck, char* match) {
	if(!match || !toCheck) {
		logError("String passed equivalent to NULL", __func__);
		return -1;
	}
	if(strcmp(toCheck, match) == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int checkTwo(char* toCheck, char* match, char* matchTwo) {
	if(!match || !toCheck || !matchTwo) {
		logError("String passed equivalent to NULL", __func__);
		return -1;
	}
	if(strcmp(toCheck, match) == 0 || strcmp(toCheck, matchTwo) == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int checkThree(char* toCheck, char* match, char* matchTwo, char* matchThree) {
	if(!match || !toCheck || !matchTwo || !matchThree) {
		logError("String passed equivalent to NULL", __func__);
		return -1;
	}
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
	if(!match || !toCheck || !matchTwo || !matchThree || !matchFour) {
		logError("String passed equivalent to NULL", __func__);
		return -1;
	}
	if(strcmp(toCheck, match) ==0 || strcmp(toCheck, matchTwo) == 0 ||
	   strcmp(toCheck, matchThree) == 0 || strcmp(toCheck, matchFour) == 0) {
		return 0;
	}
	else {
		return 1;
	}
}


