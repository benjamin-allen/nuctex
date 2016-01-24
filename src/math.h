/*------------------------------------------------------------------------------
| NuCTex	| math.h
| Author	| Benjamin A - Nullsrc
| Created	| 30 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Declaration of mathematics functions used in the game
\-----------------------------------------------------------------------------*/
#ifndef NULLSRC_MATH_HEADER
#define NULLSRC_MATH_HEADER

#include "items.h"

// RNG functions
void initRand();
int rng(int, int);
int arng(int);
int brng();
int crng(int, int);

// Combat functions
int calcDamage(int);
int runAway(int, int);
int getAggregateDefense(Equipment);

#endif /* NULLSRC_MATH_HEADER */
