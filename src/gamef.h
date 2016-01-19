/*------------------------------------------------------------------------------
| NuCTex	| gamef.h
| Author	| Benjamin A - Nullsrc
| Created	| 24 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Prototype declarations for functions used in the game
\-----------------------------------------------------------------------------*/
#ifndef NULLSRC_GAMEF_HEADER
#define NULLSRC_GAMEF_HEADER

#include "actor.h"
// Game control
int gameLoop();

// Game Commands
void quit();	// 'quit'
void look(Location*);	// 'look'
void move(Actor*, char);

#endif /* NULLSRC_GAMEF_HEADER */
