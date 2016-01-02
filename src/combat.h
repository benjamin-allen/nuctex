/*------------------------------------------------------------------------------
| NuCTex	| combat.h
| Author	| Benjamin A - Nullsrc
| Created	| 29 December, 2015
| Changed	| 1 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Declaration of combat systems
\-----------------------------------------------------------------------------*/
#ifndef NULLSRC_COMBAT_HEADER
#define NULLSRC_COMBAT_HEADER

#include "actor.h"

// Main combat functions
void combat(Actor*, Actor*);
int fightMenu();
int hasRun;

// Combat actions
void attack(Actor*, Actor*);
void run(Actor*, Actor*);

#endif /* NULLSRC_COMBAT_HEADER */
