/*------------------------------------------------------------------------------
| NuCTex	| main.c
| Author	| Benjamin A - Nullsrc
| Created	| 22 November, 2015
| Changed	| 7 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Initialize main game loop. Doesn't do much yet.
\-----------------------------------------------------------------------------*/

#include "io.h"
#include "gamef.h"
#include "math.h"

int main() {
	initRand();
	printMessage("Welcome to NuCTex 0.1a.1");
	gameLoop();

	return 0;
}
