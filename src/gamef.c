/*------------------------------------------------------------------------------
| NuCTex	| gamef.c
| Author	| Benjamin E Allen
| Date		| 24 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Impementation of game functions.
\-----------------------------------------------------------------------------*/

#include "io.h"
#include "location.h"
void callCommand(char* input);
int game_isQuit = 0;	// file-wide game-quitting variable. This will not go out of scope for the main game loop

/* gameLoop() ---
main game loop. Add things as needed */
int gameLoop() {
	while(game_isQuit != 1) {
		callCommand(getInput());
	}
	return 0;
}



/* quit() ---
change the game-quitting variable to 1 to quit the game */
void quit() {
	game_isQuit = 1;
	printMessage("Quitting NuCTex");
}


/* look(Location*) ---
print the description of a given location. Usually used in conjuction with
the move functions. */
void look(Location* room) {
	printMessage(room->description);
}

void north() {
	// check if the room has nothing north of it
	if(pos->n == 0) {
		printMessage("You cannot go that way.");
	}
	
	// if that check passes, move north
	else {
		pos = pos->n;
		look(pos);
	}
}

void south() {
	// check if the room has nothing south of it
	if(pos->s == 0) {
		printMessage("You cannot go that way.");
	}

	// if that check passes, move south
	else {
		pos = pos->s;
		look(pos);
	}
}

void east() {
	// check if the room has nothing east of it
	if(pos->e == 0) {
		printMessage("You cannot go that way.");
	}

	// if that check passes, move east
	else {
		pos = pos->e;
		look(pos);
	}
}

void west() {
	// check if the room has nothing west of it
	if(pos->w == 0) {
		printMessage("You cannot go that way.");
	}

	// if that check passes, move west
	else {
		pos = pos->w;
		look(pos);
	}
}


void callCommand(char* input) {
	// quit command
	if(strcmp(input, "quit") == 0) {	// strcmp returns 0 on truth
		quit();
	}

	else if(strcmp(input, "look") == 0) {
		look(pos);
	}

	else if(strcmp(input, "north") == 0) {
		north();
	}

	else if(strcmp(input, "south") == 0) {
		south();
	}
	
	else if(strcmp(input, "east") == 0) {
		east();
	}
	
	else if(strcmp(input, "west") == 0) {
		west();
	}

	// default "no-match" response
	else {
		printMessage("Invalid Command!");
	}
}


