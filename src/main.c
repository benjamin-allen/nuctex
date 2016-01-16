/*------------------------------------------------------------------------------
| NuCTex	| main.c
| Author	| Benjamin A - Nullsrc
| Created	| 22 November, 2015
| Changed	| 13 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Initialize main game loop. Doesn't do much yet.
\-----------------------------------------------------------------------------*/

#include "io.h"
#include "gamef.h"
#include "math.h"

int main() {
	initRand();
	printMessageC("Welcome to NuCTex 0.1b.1!", ANSI_YELLOW);
	gameLoop();

	return 0;
}
