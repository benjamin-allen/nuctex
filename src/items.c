/*------------------------------------------------------------------------------
| NuCTex	| items.c
| Author	| Benjamin A - Nullsrc
| Created	| 18 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Define example items
\-----------------------------------------------------------------------------*/

#include "items.h"
#include <stdio.h>

/* sortInventory(Inventory) ---
   Passed an inventory, will reorder its elements so that the first available
   spaces are used, and returns that inventory. Must be called with
   inv = sortInventory(inv) to have any effect */
Inventory sortInventory(Inventory inv) {
	int i = 0;
	int j = 0;
	// totalItems is used to keep track of how many items have been reordered
	int totalItems = 0;
	// Create a temporary inventory to hold the new, sorted list of items
	Inventory temp;
	for(i = 0; i < MAX_INVENTORY_AMOUNT; i++) {
		// If the inventory points to an item
		if(inv.item[i]) {
			// Set the element of temp to be that item
			temp.item[j] = inv.item[i];
			// Iterate j and totalItems;
			j++;
			totalItems++;
		}
	}
	/* Once the previous loop has been run, if there are any remaining spaces,
	   nullify their values so that there cannot be pointers with disallowed
	   addresses */
	for(i = totalItems; i < MAX_INVENTORY_AMOUNT; i++) {
		temp.item[i] = 0;
	}
	return temp;
}

int itemHasFlag(Item* toCheck, Flag* checkFor) {
	int i;
	for(i = 0; i < MAX_FLAG_AMOUNT; i++) {
		if(toCheck->flags[i]->id == checkFor->id) {
			return 1;
		}
	}
	return 0;
}

int getItemID(char* name, I_index index) {
	int i;
	for(i = 0; i < ITEM_INDEX_LIMIT; i++) {
		if(index.item[i].name) {
			if(checkOne(name, index.item[i].name) == 0) {
				if(index.item[i].id == i) {
					return i;
				}
				else {
					logError("ID expected not equivalent to items's index position", __func__);
					return -1;
				}
			}
		}
	}
}

I_index IIndex = {
	.item[0] = {.name="sword", .description="a sword", .id=0, .strength=5, .agility=-1, .intelligence=0, .charisma=0, .defense=2}
};
