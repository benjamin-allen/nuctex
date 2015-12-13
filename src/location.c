/*------------------------------------------------------------------------------
| NuCTex	| location.c
| Author	| Benjamin A - Nullsrc
|-------------------------------------------------------------------------------
| Overview	| All of the game's location definitions go here.
|-------------------------------------------------------------------------------
| CRITICAL	| Every location in this file must be prototyped in location.h
\-----------------------------------------------------------------------------*/
#include "location.h"

// all location initializations go here
Location nw = { .description="The Northwest Room", .n=0, .s=&sw, .e=&ne, .w=0};
Location ne = { .description="The Northeast Room", .n=0, .s=&se, .e=0, .w=&nw};
Location sw = { .description="The Southwest Room", .n=&nw, .s=0, .e=&se, .w=0};
Location se = { .description="The Southeast Room", .n=&ne, .s=0, .e=0, .w=&sw};
