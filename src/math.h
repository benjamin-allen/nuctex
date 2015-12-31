/*------------------------------------------------------------------------------
| NuCTex	| math.h
| Author	| Benjamin A - Nullsrc
| Created	| 30 December, 2015
| Changed	| 31 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Declaration of mathematics functions used in the game
\-----------------------------------------------------------------------------*/

// RNG functions
void randInit();
int rng(int, int);
int zrng(int);
int brng();

// Combat functions
int calcDamage(int);
int runAway(int, int);
