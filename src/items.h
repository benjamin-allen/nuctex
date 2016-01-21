/*------------------------------------------------------------------------------
| NuCTex	| items.h
| Author	| Benjamin A - Nullsrc
| Created	| 17 January, 2016
| Changed	| 18 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Declare item structures used in the code
\-----------------------------------------------------------------------------*/
#ifndef NULLSRC_ITEMS_HEADER
#define NULLSRC_ITEMS_HEADER

#define MAX_INVENTORY_AMOUNT 20
#define MAX_CLOTHING_AMOUNT 5

/* The item is our basic unit of object. It contians it's name, a description,
   and several other statistical units */
typedef struct Item {
	char* name;
	char* description;
	int id;
	float size;
	float weight;

	int strength;
	int agility;
	int intelligence;
	int charisma;

	int defense;
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

Item item_null;
Item sword;

#endif /* NULLSRC_ITEMS_HEADER */
