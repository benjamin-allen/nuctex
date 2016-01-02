/*------------------------------------------------------------------------------
| NuCTex	| actor.h
| Author	| Benjamin A - Nullsrc
| Created	| 12 December, 2015
| Changed	| 27 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Define actor struct
\-----------------------------------------------------------------------------*/

#include "location.h"
#define MAX_MONSTERS 2

typedef struct Actor {
	char* name;
	int health;
	int strength;
	int agility;
	int intelligence;
	int charisma;

	Location* actorPos;
}Actor;

Actor player;
Actor monster[MAX_MONSTERS];
