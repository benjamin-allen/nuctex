/*------------------------------------------------------------------------------
| NuCTex		| gamef.h
| Author	| Benjamin E Allen
| Date		| 24 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Prototype declarations for functions used in the game
\-----------------------------------------------------------------------------*/

#include "location.h"

// Game control
int gameLoop();
void go(struct location *);
void callComand(char*);

// Game Commands
void quit();	// 'quit'
void look();	// 'look'
void north();	// 'north'
void south();	// 'south'
void east();
void west();
