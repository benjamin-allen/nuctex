/*------------------------------------------------------------------------------
| NuCTex	| main.c
| Author	| Benjamin A - Nullsrc
| Created	| 22 November, 2015
| Changed	| 31 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Initialize main game loop. Doesn't do much yet.
\-----------------------------------------------------------------------------*/

#include "io.h"
#include "combat.h"

int main() {
	printMessage("Welcome to NuCTex pre-alpha!");
	combat(&player, &monster[1]);

	return 0;
}
