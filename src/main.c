/*------------------------------------------------------------------------------
| NuCTex	| main.c
| Author	| Benjamin A - Nullsrc
| Date		| 22 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Initialize main game loop. Doesn't do much yet.
\-----------------------------------------------------------------------------*/

#include "io.h"
#include "gamef.h"

int main() {
	printMessage("Welcome to NuCTex pre-alpha!");
	gameLoop();

	return 0;
}
