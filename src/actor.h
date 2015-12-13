/*------------------------------------------------------------------------------
| NuCTex	| actor.h
| Author	| Benjamin A - Nullsrc
| Date		| 12 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Define actor struct
\-----------------------------------------------------------------------------*/

#include "location.h"

typedef struct Actor {
	char* name;
	int strength;
	int dexterity;
	int intelligence;
	int charisma;

	Location* actorPos;
}Actor;

Actor player;
