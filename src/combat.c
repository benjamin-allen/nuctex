/*------------------------------------------------------------------------------
| NuCTex	| combat.c
| Author	| Benjamin A - Nullsrc
| Created	| 29 December, 2015
| Changed	| 1 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Implementation of combat systems. Menu selection for which
|			| creature will be fought is implemented in gamef.c
\-----------------------------------------------------------------------------*/

#include <stdio.h>
#include "combat.h"
#include "io.h"
#include "math.h"

void combat(Actor* player, Actor* creature) {
	printMessage("The monster stands before you menacingly.");
	
	while(player->health > 0 && hasRun == 0 && creature->health > 0) {
		int action = fightMenu();
		switch(action) {
			case 0: printMessage("Invalid input!"); break;
			case 1: attack(player, creature); break;
			case 2: run(player, creature); break;
			default: printMessage("OH GOD");
		}
	}
	if(player->health <= 0) {
		printMessage("You have died.");
	}
	else if(hasRun != 0) {
		printMessage("You manage to flee the fight.");
	}
	else if(creature->health <=0) {
		printMessage("You slay the monster.");
	}
}

int fightMenu() {
	printMessage("1: Attack | 2: Flee");
	char* choice = getInput();
	removeNewline(choice);
	if(checkOne(choice, "1") == 0) {
		return 1;
	}
	else if(checkOne(choice, "2") == 0) {
		return 2;
	}
	else {
		return 0;
	}
}

void attack(Actor* attacker, Actor* defender) {
	printMessage("You attempt to attack the monster!");
	int damage = calcDamage(attacker->strength);
	defender->health -= damage;
	printDamage(damage, defender->name);
}

void run(Actor* escaping, Actor* chasing) {
	hasRun = runAway(escaping->agility, chasing->agility);
}
