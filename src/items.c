/*------------------------------------------------------------------------------
| NuCTex	| items.c
| Author	| Benjamin A - Nullsrc
| Created	| 18 January, 2016
| Changed	| 18 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Define example items
\-----------------------------------------------------------------------------*/

#include "items.h"

Item sword = {
	.name = "sword",
	.description = "A short, sturdy blade, favored for it's ease-of-use and versatility",
	.id = 1,
	.size = 1.0,
	.weight = 1.0,

	.strength = 5,
	.agility = -1,
	.intelligence = 0,
	.charisma = 0,
};
