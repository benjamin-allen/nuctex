/*------------------------------------------------------------------------------
| NuCTex	| actor.c
| Author	| Benjamin A - Nullsrc
| Created	| 12 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Implement actors
\-----------------------------------------------------------------------------*/

#include "actor.h"

int getActorID(char* name, A_index index) {
	int i;
	for(i = 0; i < ACTOR_INDEX_LIMIT; i++) {
		if(index.actor[i].name) {
			if(checkOne(name, index.actor[i].name) == 0) {
				if(index.actor[i].id == i) {
					return i;
				}
				else {
					logError("ID expected not equivalent to actor's index location", __func__);
					return -1;
				}
			}
		}
	}
}

A_index AIndex = { 
	.actor[0] = {.id=0, .name="Nullsrc", .health=100, .strength=10, .agility=10, .intelligence=10, .charisma=10, .actorPos=&LIndex.loc[0], .inv.item[0]=&IIndex.item[0],},
	.actor[1] = {.id=1, .name="slime", .health=25, .strength=4, .agility=8, .intelligence=3, .charisma=10, .actorPos=&LIndex.loc[1],},
	.actor[2] = {.id=2, .name="Sean", .health=200, .strength=12, .agility=9, .intelligence=11, .charisma=8, .isNPC=1, .talkText="Heya. Name's Sean. You have a reason to be here?", .actorPos=&LIndex.loc[1], .inv.item[0]=&IIndex.item[0],}
};
