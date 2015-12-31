/*------------------------------------------------------------------------------
| NuCTex	| combat.h
| Author	| Benjamin A - Nullsrc
| Created	| 29 December, 2015
| Changed	| 29 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Declaration of combat systems
\-----------------------------------------------------------------------------*/

#include "actor.h"

// Main combat functions
void combat(Actor*, Actor*);
int inputAction();
int hasRun = 0;

// Combat actions
void attack(Actor*, Actor*);
void run(Actor*, Actor*);
