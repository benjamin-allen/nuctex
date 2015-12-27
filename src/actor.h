/*------------------------------------------------------------------------------
| NuCTex	| actor.h
| Author	| Benjamin A - Nullsrc
| Created	| 12 December, 2015
| Changed	| 27 December, 2015
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
Actor monster[2];
