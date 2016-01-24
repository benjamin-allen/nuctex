/*------------------------------------------------------------------------------
| NuCTex	| gamef.c
| Author	| Benjamin A - Nullsrc
| Created	| 24 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Impementation of game functions.
\-----------------------------------------------------------------------------*/

#include "io.h"
#include "combat.h"
#include "items.h"

int game_isQuit = 0;	/* file-wide game-quitting variable. This will not go
						out of scope for the main game loop */

/* gameLoop() ---
main game loop. Add things as needed */
int gameLoop() {
	while(game_isQuit != 1) {
		parseInput(getInput());
	}
	return 0;
}



/* quit() ---
change the game-quitting variable to 1 to quit the game */
void quit() {
	game_isQuit = 1;
	printMessage("Quitting NuCTex");
}


/* look(Location*) ---
print the description of a given location. Usually used in conjuction with
the move functions. */
void look(Location* room) {
	printMessageC("================================================================================", ANSI_MAGENTA);
	int exits = 0;
	printMessage(room->description);
	/* the following chunk of if statments increment the exit integer to act as
	a bitwise number for the purposes of printing exits */
	if(room->n != NOWHERE) {
		exits = exits + 1;
	}
	if(room->s != NOWHERE) {
		exits = exits + 2;
	}
	if(room->e != 0 NOWHERE) {
		exits = exits + 4;
	}
	if(room->w != 0 NOWHERE) {
		exits = exits + 8;
	}

	/* This switch statement prints the exits when given an integer. If an
	improper number is given, the statement will default to printing no
	exits */
	switch(exits) {
		case 1   : printMessage("Exits: North");break;
		case 2   : printMessage("Exits: South");break;
		case 3   : printMessage("Exits: North, South");break;
		case 4   : printMessage("Exits: East");break;
		case 5   : printMessage("Exits: North, East");break;
		case 6   : printMessage("Exits: South, East");break;
		case 7   : printMessage("Exits: North, South, East");break;
		case 8   : printMessage("Exits: West");break;
		case 9   : printMessage("Exits: North, West");break;
		case 10  : printMessage("Exits: South, West");break;
		case 11  : printMessage("Exits: North, South, West");break;
		case 12  : printMessage("Exits: East, West");break;
		case 13  : printMessage("Exits: North, East, West");break;
		case 14  : printMessage("Exits: South, East, West");break;
		case 15  : printMessage("Exits: North, South, East, West");break;
		case 0   : printMessage("This place has no exits.");break;
		default  : printMessage("Invalid number of exits. Debugging required.");
			break;
	}
	int i = 0;
	int isMonsterHere = 0;

	// The following code calls a check against all monsers for their position
	while(i < MAX_MONSTERS) {
		if(monster[i].actorPos == player.actorPos &&
			monster[i].actorPos == room) {
			printMonster(monster[i].name);
			isMonsterHere=1;
		}
		i++;
	}
	if(isMonsterHere == 1) {
		printMessage("");
	}
	printMessageC("================================================================================", ANSI_MAGENTA);
}

/* move(Actor*, char) ---
   Move the creature specified north, south, east, or west based on the char
   passed */
void move(Actor* creature, char nsew) {
	switch(nsew) {
		case 'n':
			/* Conditional check for whether there's actually something at the
			   desired location. Only passes if there is */
			if(creature->actorPos->n != NOWHERE) {
				creature->actorPos = &LIndex.loc[creature->actorPos->n]; 
				look(creature->actorPos);
			}
			else {
				printMessageC("You can't go that way!", ANSI_RED);
			}
			break;
		case 's':
			if(creature->actorPos->s != NOWHERE) {
				creature->actorPos = &LIndex.loc[creature->actorPos->s];
				look(creature->actorPos);
			}
			else {
				printMessageC("You can't go that way!", ANSI_RED);
			}
			break;
		case 'e':
			if(creature->actorPos->e != NOWHERE) {
				creature->actorPos = &LIndex.loc[creature->actorPos->e];
				look(creature->actorPos);
			}
			else {
				printMessageC("You can't go that way!", ANSI_RED);
			}
			break;
		case 'w':
			if(creature->actorPos->w != NOWHERE) {
				creature->actorPos = &LIndex.loc[creature->actorPos->w];
				look(creature->actorPos);
			}
			else {
				printMessageC("You can't go that way!", ANSI_RED);
			}
			break;
		default : printMessage("There's nowhere to go");
			break;
	}
}

/* drop(char*, Actor*) ---
   Given the name of an item to search for, iterate through the item list and
   identify an item of that name. If that item exists, drop it */
void drop(char* itemName, Actor* actor) {
	int i;
	for(i = 0; i < MAX_INVENTORY_AMOUNT; i++) {
		// Only run comparisons on non-null memory values
		if(actor->inv.item[i]) {
			// If the item name matches the name given to drop()
			if(checkOne(actor->inv.item[i]->name, itemName) == 0) {
				/* Iterate through the location's inventory until a null pointer
				   is found */
				int j = 0;
				while(actor->actorPos->inv.item[j]) {
					j++;
				}
				// Set the location's null pointer to point to the item...
				actor->actorPos->inv.item[j] = actor->inv.item[i];
				// ...and set the inventory pointer that was taken from to null
				actor->inv.item[i] = 0;
			}
		}
	}
}

/* pickUp(char*, Actor*) ---
   Given the name of an item to search for, iterate through the location's item
   list and identify an item of that name. If that item exists, pick it up */
void pickUp(char* itemName, Actor* actor) {
	int i;
	// See drop() for an explanation of the search process
	for(i = 0; i < MAX_INVENTORY_AMOUNT; i++) {
		if(actor->actorPos->inv.item[i]) {
			if(checkOne(actor->actorPos->inv.item[i]->name, itemName) == 0) {
				int j = 0;
				while(actor->inv.item[j]) {
					j++;
				}
				// Set the actor's pointer to point to the item...
				actor->inv.item[j] = actor->actorPos->inv.item[i];
				// ...and set the location inventory's item to point to null
				actor->actorPos->inv.item[i] = 0;
			}
		}
	}
}

/* wield(char*, Actor*) ---
   Given the name of an item to search for, iterate through the Actor's
   inventory and identify an item of that name. If that item exists, equip it */
void wield(char* itemName, Actor* actor) {
	int i;
	for(i = 0; i < MAX_INVENTORY_AMOUNT; i++) {
		if(actor->inv.item[i]) {
			if(checkOne(actor->inv.item[i]->name, itemName) == 0) {
				// If there is no weapon currently equipped
				if(!actor->eqp.weapon) {
					// Set the actor's weapon to point to the inventory item... 
					actor->eqp.weapon = actor->inv.item[i];
					// Set the inventory pointer that was taken from to null.
					actor->inv.item[i] = 0;
				}
				// If there is a weapon currently equipped
				else {
					/* Create a temporary pointer to store the address of
					   the inventory item */
					Item* temp = actor->inv.item[i];
					/* Set the inventory pointer to point the currently equipped
					   weapon */
					actor->inv.item[i] = actor->eqp.weapon;
					// Set the weapon to the temporary pointer
					actor->eqp.weapon = temp;
				}
			}
		}
	}
}

/* callCommand(char*, char*) ---
   Run a series of string comparisons on verb and noun to determine the proper
   function to call. Should be called after parsing user input into a verb and
   a noun */
void callCommand(char* verb, char* noun) {
	// Quit is never called with a noun argument
	if(checkOne(verb, "quit") == 0) {
		quit();
	}

	// Parsing for the look command
	else if(checkOne(verb, "look") == 0) {
		if(checkThree(noun, "!n", "around", "room") == 0) {
			look(player.actorPos);
		}
		else if(checkOne(noun, "me") == 0) {
			printStats(player.health);
		}
		else if(checkOne(noun, "items") == 0) {
			printInventory(player.actorPos->inv, 0);
		}
	}

	// Parsing for the items command
	else if(checkTwo(verb, "items", "inventory") == 0) {
		printInventory(player.inv, player.name);
		printEquipment(player.eqp, player.name);
	}

	// Parsing for the describe command
	else if(checkOne(verb, "describe") == 0) {
		int i;
		for(i = 0; i < MAX_INVENTORY_AMOUNT; i++) {
			if(player.inv.item[i]) {
				if(checkOne(noun, player.inv.item[i]->name) == 0) {
					describeItem(player.inv.item[i]);
				}
			}
		}
	}

	// Parsing for the go command
	else if(checkOne(verb, "go") == 0) {
		if(checkTwo(noun, "north", "n") == 0) {
			move(&player, 'n');
		}
		else if(checkTwo(noun, "south", "s") == 0) {
			move(&player, 's');
		}
		else if(checkTwo(noun, "east", "e") == 0) {
			move(&player, 'e');
		}
		else if(checkTwo(noun, "west", "w") == 0) {
			move(&player, 'w');
		}
		else {
			printMessage("You can't go that way!");
		}
	}

	// Parsing for the drop command
	else if(checkOne(verb, "drop") == 0) {
		drop(noun, &player);
		player.inv = sortInventory(player.inv);
	}
	
	// Parsing for the get command
	else if(checkOne(verb, "get") == 0) {
		pickUp(noun, &player);
		player.inv = sortInventory(player.inv);
	}

	// Parsing for the wield command
	else if(checkOne(verb, "wield") == 0) {
		wield(noun, &player);
		player.inv = sortInventory(player.inv);
	}

	else if(checkOne(verb, "sort") == 0) {
		player.inv = sortInventory(player.inv);
	}

	// Parsing for the kill command
	else if(checkOne(verb, "kill") == 0) {
		int i = 0;
		while(i < MAX_MONSTERS) {
			if(checkOne(noun, monster[i].name) == 0) {
				if(player.actorPos == monster[i].actorPos) {
					game_isQuit = combat(&player, &monster[i]);
				}
			}
			i++;
		}
	}

	// Default "no-match" response
	else {
		printMessage("Invalid input");
	}
}
