/*------------------------------------------------------------------------------
| NuCTex	| math.h
| Author	| Benjamin A - Nullsrc
| Created	| 30 December, 2015
| Changed	| 1 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Declaration of mathematics functions used in the game
\-----------------------------------------------------------------------------*/
#ifndef NULLSRC_MATH_HEADER
#define NULLSRC_MATH_HEADER

// RNG functions
void randInit();
int rng(int, int);
int zrng(int);
int brng();

// Combat functions
int calcDamage(int);
int runAway(int, int);

#endif /* NULLSRC_MATH_HEADER */
