/*------------------------------------------------------------------------------
| NuCTE		| gamef.c
| Author	| Benjamin E Allen
| Date		| 24 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Impementation of game functions.
\-----------------------------------------------------------------------------*/

#include "io.h"
#include "command.h"

int game_isQuit = 0;	// file-wide game-quitting variable. This will not go
						// out of scope for the main game loop

// quit() ---
// change the game-quitting variable to 1 to quit the game
void quit() {
	game_isQuit = 1;
	printMessage("Quitting NuCTE");
}

// gameLoop() ---
// main game loop. Add things as needed
int gameLoop() {
	while(game_isQuit != 1) {
		callCommand(getInput());
	}
	return 0;
}
