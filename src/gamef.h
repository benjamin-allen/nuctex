/*------------------------------------------------------------------------------
| NuCTex	| gamef.h
| Author	| Benjamin A - Nullsrc
| Date		| 24 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Prototype declarations for functions used in the game
\-----------------------------------------------------------------------------*/

#include "actor.h"
// Game control
int gameLoop();
void callComand(char*);

// Game Commands
void quit();	// 'quit'
void look(Location*);	// 'look'
void move(Actor*, char);
