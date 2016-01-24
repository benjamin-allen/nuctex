/*------------------------------------------------------------------------------
| NuCTex	| main.c
| Author	| Benjamin A - Nullsrc
| Created	| 22 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Initialize main game loop. Doesn't do much yet.
\-----------------------------------------------------------------------------*/

#include "io.h"
#include "gamef.h"
#include "math.h"

int main() {
	// Initialize the pseudo-RNG
	initRand();
	// Print the welcome message
	printMessageC("Welcome to NuCTex 0.1c!", ANSI_YELLOW);
	gameLoop();

	return 0;
}
