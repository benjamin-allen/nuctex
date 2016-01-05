/*------------------------------------------------------------------------------
| NuCTex	| main.c
| Author	| Benjamin A - Nullsrc
| Created	| 22 November, 2015
| Changed	| 1 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Initialize main game loop. Doesn't do much yet.
\-----------------------------------------------------------------------------*/

#include "io.h"
#include "combat.h"

int main() {
	initRand();
	printMessage("Welcome to NuCTex pre-alpha!");
	gameLoop();

	return 0;
}
