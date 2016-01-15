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
	printMessageC("Welcome to NuCTex 0.1a.1. This is a lot of text that is longer than 80 characters long because it takes a lot of space to type. This is some filler text to test even more of the stuff that the code is supposed to do but might not correctly because I'm not a terribly good coder", ANSI_YELLOW);
	gameLoop();

	return 0;
}
