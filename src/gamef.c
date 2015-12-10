/*------------------------------------------------------------------------------
| NuCTex		| gamef.c
| Author	| Benjamin E Allen
| Date		| 24 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Impementation of game functions.
\-----------------------------------------------------------------------------*/

#include "io.h"
#include "location.h"
void callCommand(char* input);

Location locs[2][2] = {
	{"The northwest room", "The northeast room"},
	{"The southwest room", "The southeast room"}
};



int game_isQuit = 0;	// file-wide game-quitting variable. This will not go
						// out of scope for the main game loop
int playerx = 0, playery = 0;

// gameLoop() ---
// main game loop. Add things as needed
int gameLoop() {
	while(game_isQuit != 1) {
		callCommand(getInput());
	}
	return 0;
}



// quit() ---
// change the game-quitting variable to 1 to quit the game
void quit() {
	game_isQuit = 1;
	printMessage("Quitting NuCTex");
}

void look(Location locs) {
	printMessage(locs.description);
}

void go(Location location) {
	look(locs[playerx][playery]);
}

void north() {
	playerx --;
	go(locs[playerx][playery]);
}

void south() {
	playerx ++;
	go(locs[playerx][playery]);
}

void east() {
	playery ++;
	go(locs[playerx][playery]);
}

void west() {
	playery --;
	go(locs[playerx][playery]);
}

void callCommand(char* input) {
	// quit command
	if(strcmp(input, "quit") == 0) {	// strcmp returns 0 on truth. I hate it
		quit();							// but that's how it is.
	}

	else if(strcmp(input, "look") == 0) {
		look(locs[playery][playerx]);
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


