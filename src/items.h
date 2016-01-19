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
#define MAX_EQUIPMENT_AMOUNT 5

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
} Item;

typedef struct Inventory {
	Item* item[MAX_INVENTORY_AMOUNT];
} Inventory;

typedef struct Equipment {
	Item* item[MAX_EQUIPMENT_AMOUNT];
} Equipment;

Item item_null;
Item sword;

#endif /* NULLSRC_ITEMS_HEADER */
