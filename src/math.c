/*------------------------------------------------------------------------------
| NuCTex	| math.c
| Author	| Benjamin A - Nullsrc
| Created	| 30 December, 2015
| Changed	| 30 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Implementation of various mathematical functions used in the game
\-----------------------------------------------------------------------------*/

#include "math.h"

int calcDamage(int strength) {
	int damageTotal = 0;
	damageTotal = strength;
	return damageTotal;
}

int runAway(int escapingAgility, int chasingAgility) {
	if(escapingAgility > chasingAgility) {
		return 1;
	}
	else {
		return 0;
	}
}
