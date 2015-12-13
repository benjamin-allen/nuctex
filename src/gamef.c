/*------------------------------------------------------------------------------
| NuCTex	| gamef.c
| Author	| Benjamin A - Nullsrc
| Date		| 24 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Impementation of game functions.
\-----------------------------------------------------------------------------*/

#include "io.h"
#include "actor.h"
#include <string.h>
void callCommand(char* input);
int game_isQuit = 0;	/* file-wide game-quitting variable. This will not go
						out of scope for the main game loop */

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
	int exits = 0;
	printMessage(room->description);
	/* the following chunk of if statments increment the exit integer to act as
	a bitwise number for the purposes of printing exits */
	if(room->n != 0) {
		exits = exits + 1;
	}
	if(room->s !=0) {
		exits = exits + 2;
	}
	if(room->e != 0) {
		exits = exits + 4;
	}
	if(room->w != 0) {
		exits = exits + 8;
	}

	/* this switch statement prints the exits when given an integer. If an
	improper number is given, the statement will default to printing no
	exits */
	switch(exits) {
		case 1   : printMessage("Exits: North");break;
		case 2   : printMessage("Exits: South");break;
		case 3   : printMessage("Exits: North, South");break;
		case 4   : printMessage("Exits: East");break;
		case 5   : printMessage("Exits: North, East");break;
		case 6   : printMessage("Exits: South, East");break;
		case 7   : printMessage("Exits: North, South, East");break;
		case 8   : printMessage("Exits: West");break;
		case 9   : printMessage("Exits: North, West");break;
		case 10  : printMessage("Exits: South, West");break;
		case 11  : printMessage("Exits: North, South, West");break;
		case 12  : printMessage("Exits: East, West");break;
		case 13  : printMessage("Exits: North, East, West");break;
		case 14  : printMessage("Exits: South, East, West");break;
		case 15  : printMessage("Exits: North, South, East, West");break;
		case 0   : printMessage("This place has no exits.");break;
		default  : printMessage("Invalid number of exits. Debugging required.");
			break;
	}
}

Location* move(Location* pos, char nsew) {
	switch(nsew) {
		case 'n': pos = pos->n; 
			look(pos);
			return pos;
			break;
		case 's': pos = pos->s; 
			look(pos);
			return pos;
			break;
		case 'e': pos = pos->e;
			look(pos);
			return pos;
			break;
		case 'w': pos = pos->w;
			look(pos);
			return pos;
			break;
		default : printMessage("There's nowhere to go");
			break;
	}
}


void callCommand(char* input) {
	// quit command
	if(strcmp(input, "quit") == 0) {	// strcmp returns 0 on truth
		quit();
	}

	else if(strcmp(input, "look") == 0) {
		look(player.actorPos);
	}

	else if(strcmp(input, "north") == 0) {
		player.actorPos = move(player.actorPos, 'n');
	}

	else if(strcmp(input, "south") == 0) {
		player.actorPos = move(player.actorPos, 's');
	}
	
	else if(strcmp(input, "east") == 0) {
		player.actorPos = move(player.actorPos, 'e');
	}
	
	else if(strcmp(input, "west") == 0) {
		player.actorPos = move(player.actorPos, 'w');
	}

	// default "no-match" response
	else {
		printMessage("Invalid Command!");
	}
}


