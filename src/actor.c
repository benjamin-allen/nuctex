/*------------------------------------------------------------------------------
| NuCTex	| actor.c
| Author	| Benjamin A - Nullsrc
| Date		| 12 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Implement actors
\-----------------------------------------------------------------------------*/

#include "actor.h"

Actor player = {
	.name="Nullsrc",
	.strength=10,
	.dexterity=10,
	.intelligence=10,
	.charisma=10,

	.actorPos=&nw
};

Actor monster[2] = {
	{
		.name="Grue",
		.strength=20,
		.dexterity=5,
		.intelligence=3,
		.charisma=2,

		.actorPos=&ne
	},
	{
		.name="Slime",
		.strength=5,
		.dexterity=10,
		.intelligence=5,
		.charisma=5,

		.actorPos=&se
	}
};
