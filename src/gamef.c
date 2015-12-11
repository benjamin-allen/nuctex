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
Location southRoom;
Location northRoom;
Location northmostRoom;
Location southmostRoom;
Location southRoom = { .description="The South Room", .north=&northRoom, .south=&southmostRoom};
Location northRoom = { .description="The North Room", .north=&northmostRoom, .south=&southRoom};
Location northmostRoom = { .description="The Northmost Room", .north=0, .south=&northRoom};
Location southmostRoom = { .description="The Southmost Room", .north=&southRoom, .south=0};

int game_isQuit = 0;	// file-wide game-quitting variable. This will not go
						// out of scope for the main game loop
struct Location *pos = &northRoom;

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

void look(Location* room) {
	printMessage(room->description);
}

void go(Location* room) {
	look(room);
}

void north() {
	pos = pos->north;
}

void south() {
	pos = pos->south;
}


void callCommand(char* input) {
	// quit command
	if(strcmp(input, "quit") == 0) {	// strcmp returns 0 on truth. I hate it
		quit();							// but that's how it is.
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

	// default "no-match" response
	else {
		printMessage("Invalid Command!");
	}
}


