/*------------------------------------------------------------------------------
| NuCTex	| combat.h
| Author	| Benjamin A - Nullsrc
| Created	| 29 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Declaration of combat systems
\-----------------------------------------------------------------------------*/
#ifndef NULLSRC_COMBAT_HEADER
#define NULLSRC_COMBAT_HEADER

#include "actor.h"

// Main combat functions
int combat(Actor*, Actor*);
int fightMenu();
int hasRun;

// Combat actions
void attack(Actor*, Actor*, int);
void run(Actor*, Actor*);

// Monster functions
void monsterAct(int, Actor*, Actor*);

#endif /* NULLSRC_COMBAT_HEADER */
