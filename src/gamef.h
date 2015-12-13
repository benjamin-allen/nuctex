/*------------------------------------------------------------------------------
| NuCTex	| gamef.h
| Author	| Benjamin A - Nullsrc
| Date		| 24 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Prototype declarations for functions used in the game
\-----------------------------------------------------------------------------*/

#include "location.h"

// Game control
int gameLoop();
void callComand(char*);

// Game Commands
void quit();	// 'quit'
void look(Location*);	// 'look'
void north(Location*);	// 'north'
void south(Location*);	// 'south'
void east(Location*);	// 'east
void west(Location*);	// 'west
