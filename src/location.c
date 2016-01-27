/*------------------------------------------------------------------------------
| NuCTex	| location.c
| Author	| Benjamin A - Nullsrc
| Created	| 25 November, 2015
|-------------------------------------------------------------------------------
| Overview	| All of the game's location definitions go here.
|-------------------------------------------------------------------------------
| CRITICAL	| Every location in this file must be prototyped in location.h
\-----------------------------------------------------------------------------*/
#include "location.h"

int getLocID(char* name, L_index index) {
	int i;
	for(i = 0; i < LOCATION_INDEX_LIMIT; i++) {
		if(index.loc[i].name) {
			if(checkOne(name, index.loc[i].name) == 0) {
				if(index.loc[i].id == i) {
					return i;
				}
				else {
					printMessage("ID expected not equivalent to locations's index position");
					return -1;
				}
			}
		}
	}
}

L_index LIndex = {
	.loc[0] = {.id=0, .name="dead", .description="If you can see this room, it is a bug.", .n=1, .s=NOWHERE, .e=NOWHERE, .w=NOWHERE},
	.loc[1] = {.id=1, .name="room2", .description="This is another room.", .n=NOWHERE, .s=0, .e=NOWHERE, .w=NOWHERE}
};
