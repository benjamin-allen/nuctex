/*------------------------------------------------------------------------------
| NuCTex	| math.c
| Author	| Benjamin A - Nullsrc
| Created	| 30 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Implementation of various mathematical functions used in the game
\-----------------------------------------------------------------------------*/

#include "math.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* initRand() ---
   To be called in the main function and handle any necessary initialization for
   the RNG systems */
void initRand() {
	srand(time(NULL));
}

/* rng(int, int) ---
   Given a range with two integers as the lower and higher end of the range,
   return a number between the low and high ranges. Possible returns include the
   low and high number */
int rng(int low, int high) {
	high += 1;
	int temp = low;
	int addend = rand() % (high - low);
	temp += addend;
	return temp;
}

/* arng(int) ---
   Return a number between 0 and the int argument */
int arng(int range) {
	int temp = rand() % (range + 1);
	return temp;
}

/* brng() ---
   Return either 0 or 1 */
int brng() {
	int temp = rand() % 2;
	return temp;
}

/* crng(int, int) ---
   Given a fractional value in the form of a numerator and denominator, have
   a numerator/denominator chance to return 0. Otherwise, return the generated
   value */
int crng(int num, int den) {
	int temp = rand() % den;
	if(temp < num) {
		return 0;
	}
	else {
		return temp;
	}
}

/* calcDamage(int) ---
   Given a strength value, calculate damage with a semirandom spread */
int calcDamage(int strength) {
	int damageTotal = 0;
	damageTotal = rng(strength - (strength/4), strength + (strength/5));
	return damageTotal;
}

/* runAway(int, int) ---
   Given two agility values to compare, determine whether one creature has the
   ability to outrun the other */
int runAway(int escapingAgility, int chasingAgility) {
	if((escapingAgility + arng(escapingAgility/3)) > chasingAgility) {
		return 1;
	}
	else {
		return 0;
	}
}
