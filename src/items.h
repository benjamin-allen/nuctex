/*------------------------------------------------------------------------------
| NuCTex	| items.h
| Author	| Benjamin A - Nullsrc
| Created	| 17 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Declare item structures used in the code
\-----------------------------------------------------------------------------*/
#ifndef NULLSRC_ITEMS_HEADER
#define NULLSRC_ITEMS_HEADER

#include "flags.h"

#define MAX_INVENTORY_AMOUNT 20
#define MAX_CLOTHING_AMOUNT 5
#define ITEM_INDEX_LIMIT 100

/* The item is our basic unit of object. It contians it's name, a description,
   and several other statistical units */
typedef struct Item {
	char* name;
	char* description;
	int id;
	
	int strength;
	int agility;
	int intelligence;
	int charisma;

	int defense;

	Flag* flags[MAX_FLAG_AMOUNT];
} Item;

/* Actors do not posess individual items, but they do posess the following
   structs that allow themm to manipulate items */
/* The inventory is a container for items. All items should be placed in
   inventories prior to their use */
typedef struct Inventory {
	Item* item[MAX_INVENTORY_AMOUNT];
} Inventory;

/* Equipment is an inventory-like system that allows us to reference certain
   items outside of the inventory context, which allows for better manipulation
   of the items in an equipment and inventory context */
typedef struct Equipment {
	Item* weapon;
	Item* clothing[MAX_CLOTHING_AMOUNT];
	Item* accessory;
} Equipment;

typedef struct I_index {
	Item item[ITEM_INDEX_LIMIT];
} I_index;

Inventory sortInventory(Inventory);
int itemHasFlag(Item*, Flag*);

struct I_index IIndex;

#endif /* NULLSRC_ITEMS_HEADER */
