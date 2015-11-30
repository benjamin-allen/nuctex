/*------------------------------------------------------------------------------
| NuCTex		| gamef.c
| Author	| Benjamin E Allen
| Date		| 24 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Impementation of game functions.
\-----------------------------------------------------------------------------*/

#include "io.h"
#include "location.h"

int gameLoop();
void quit();
void look(struct location);
void go(struct location);
void north();
void south();
void callCommand(char* input);

struct location locs[2][2] = {
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

void look(struct location locs) {
	printMessage(locs.description);
}

void go(struct location location) {
	look(locs[playery][playerx]);
}

void north() {
	playery --;
	go(locs[playery][playerx]);
}

void south() {
	playery ++;
	go(locs[playery][playerx]);
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

	// default "no-match" response
	else {
		printMessage("Invalid Command!");
	}
}
