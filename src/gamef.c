/*------------------------------------------------------------------------------
| NuCTE		| gamef.c
| Author	| Benjamin E Allen
| Date		| 24 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Impementation of game functions.
\-----------------------------------------------------------------------------*/

#include "io.h"
#include "command.h"

int game_isQuit = 0;

void quit() {
	game_isQuit = 1;
	printMessage("Quitting NuCTE");
}

int gameLoop() {
	while(game_isQuit != 1) {
		callCommand(getInput());
	}
	return 0;
}
