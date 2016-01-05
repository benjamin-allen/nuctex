/*------------------------------------------------------------------------------
| NuCTex	| math.c
| Author	| Benjamin A - Nullsrc
| Created	| 30 December, 2015
| Changed	| 4 January, 2015
|-------------------------------------------------------------------------------
| Overview	| Implementation of various mathematical functions used in the game
\-----------------------------------------------------------------------------*/

#include "math.h"
#include <stdio.h>
#include <stdlib.h>

void initRand() {
	srand(time(NULL));
}

int rng(int low, int high) {
	high += 1;
	int temp = low;
	int addend = rand() % (high - low);
	temp += addend;
	return temp;
}

int arng(int range) {
	int temp = rand() % (range + 1);
	return temp;
}

int brng() {
	int temp = rand() % 2;
	return temp;
}

int crng(int num, int den) {
	int temp = rand() % den;
	if(temp < num) {
		return 0;
	}
	else {
		return temp;
	}
}

int calcDamage(int strength) {
	int damageTotal = 0;
	damageTotal = rng(strength - (strength/4), strength + (strength/5));
	return damageTotal;
}

int runAway(int escapingAgility, int chasingAgility) {
	if((escapingAgility + arng(escapingAgility/3)) > chasingAgility) {
		return 1;
	}
	else {
		return 0;
	}
}
