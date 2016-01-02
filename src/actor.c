/*------------------------------------------------------------------------------
| NuCTex	| actor.c
| Author	| Benjamin A - Nullsrc
| Created	| 12 December, 2015
| Changed	| 27 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Implement actors
\-----------------------------------------------------------------------------*/

#include "actor.h"

Actor player = {
	.name="Nullsrc",
	.health=100,
	.strength=10,
	.agility=10,
	.intelligence=10,
	.charisma=10,

	.actorPos=&nw
};

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
