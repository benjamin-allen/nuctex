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
void north(int*, struct location*);
void south(int*, struct location*);
void callCommand(char* input);


int game_isQuit = 0;	// file-wide game-quitting variable. This will not go
						// out of scope for the main game loop

int playerPos = 0;

struct location locs[2] = {
	{"Metal walls enclose the armature and casing of a giant generator.", "start"},
	{"To the south lies a door to a room, from which a faint hum can be heard.", "hall"}
};

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
	look(locs[playerPos]);
}

void north(int* pos,struct location locs[]) {
	(*pos)++;
	go(locs[*pos]);
}

void south(int* pos,struct location locs[]) {
	(*pos)--;
	go(locs[*pos]);
}



void callCommand(char* input) {
	int* pPlayerPos;
	pPlayerPos = &playerPos;

	// quit command
	if(strcmp(input, "quit") == 0) {	// strcmp returns 0 on truth. I hate it
		quit();							// but that's how it is.
	}

	else if(strcmp(input, "look") == 0) {
		look(locs[playerPos]);
	}

	else if(strcmp(input, "north") == 0) {
		north(pPlayerPos, locs);
	}

	else if(strcmp(input, "south") == 0) {
		south(pPlayerPos, locs);
	}

	// default "no-match" response
	else {
		printMessage("Invalid Command!");
	}
}
