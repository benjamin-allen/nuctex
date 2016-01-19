/*------------------------------------------------------------------------------
| NuCTex	| actor.c
| Author	| Benjamin A - Nullsrc
| Created	| 12 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Implement actors
\-----------------------------------------------------------------------------*/

#include "actor.h"

/* This object contains the information for the player character. Expect this to
   expand in future updates, but things are very basic for the alpha */
Actor player = {
	.name="Nullsrc",
	.health=100,
	.strength=10,
	.agility=10,
	.intelligence=10,
	.charisma=10,

	.actorPos=&nw
};

/* This array of monsters contains all of the monsters in the game. MAX_MONSTERS
   is declared in actor.h as it is used in multiple files */
Actor monster[MAX_MONSTERS] = {
	{
		.name="Grue",
		.health=25,
		.strength=20,
		.agility=5,
		.intelligence=3,
		.charisma=2,

		.actorPos=&ne
	},
	{
		.name="Slime",
		.health=25,
		.strength=5,
		.agility=10,
		.intelligence=5,
		.charisma=5,

		.actorPos=&se
	}
};
