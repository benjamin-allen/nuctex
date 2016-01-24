/*------------------------------------------------------------------------------
| NuCTex	| actor.c
| Author	| Benjamin A - Nullsrc
| Created	| 12 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Implement actors
\-----------------------------------------------------------------------------*/

#include "actor.h"

A_index AIndex = { 
	.actor[0] = {.name="Nullsrc", .health=100, .strength=10, .agility=10, .intelligence=10, .charisma=10, .actorPos=&LIndex.loc[0], .inv.item[0]=&IIndex.item[0],}
};
