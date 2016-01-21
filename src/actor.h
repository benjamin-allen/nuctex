/*------------------------------------------------------------------------------
| NuCTex	| actor.h
| Author	| Benjamin A - Nullsrc
| Created	| 12 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Define actor struct
\-----------------------------------------------------------------------------*/
#ifndef NULLSRC_ACTOR_HEADER
#define NULLSRC_ACTOR_HEADER

#include "location.h"
#include "items.h"
// This declaration must be modified whenever any new monsters are added
#define MAX_MONSTERS 2

typedef struct Actor {
	// name stores the string by which the actor is known to the engine
	char* name;
	int health;
	int strength;
	int agility;
	int intelligence;
	int charisma;

	/* The inventory and equipment structures provide a convenient way to access
	   individual items whilst being sure that they are accessible to a
	   player */
	Inventory inv;
	Equipment eqp;

	/* The location pointer is used to store the reference to the location at
	   which the actor resides. It's useful for several functions */
	Location* actorPos;
}Actor;

// Declaration of the actors used in the engine
Actor player;
Actor monster[MAX_MONSTERS];

#endif /* NULLSRC_ACTOR_HEADER */
