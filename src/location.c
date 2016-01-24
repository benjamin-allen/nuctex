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

L_index LIndex = {
	.loc[0] = {.id=0, .description="If you can see this room, it is a bug.", .n=0, .s=0, .e=0, .w=0}
};
