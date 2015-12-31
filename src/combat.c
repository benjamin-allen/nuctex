/*------------------------------------------------------------------------------
| NuCTex	| combat.c
| Author	| Benjamin A - Nullsrc
| Created	| 29 December, 2015
| Changed	| 29 December, 2015
|-------------------------------------------------------------------------------
| Overview	| Implementation of combat systems. Menu selection for which
|			| creature will be fought is implemented in gamef.c
\-----------------------------------------------------------------------------*/

#include <stdio.h>
#include "combat.h"
#include "io.h"
#include "math.h"

void combat(Actor* player, Actor* creature) {
	while(player->health > 0 && hasRun == 0 && creature->health > 0) {
		int action = inputAction();
		switch(action) {
			case 1: attack(player, creature);
				break;
			case 2: run(player, creature);
				if(hasRun == 0) {
					printMessage("You try to flee, but can't...");
				}
				break;
			default: break;
		}
	}
	if(player->health <= 0) {
		printMessage("You have died.");
	}
	else if(hasRun != 0) {
		printMessage("You manage to flee the fight.");
	}
	else if(creature->health <=0) {
		printMessage("You slay the monster");
	}
}

int inputAction() {
	printMessage("What would you like to do?");
	printMessage("1: Attack");
	printMessage("2: Run");
	char input;
	scanf(" %c", &input);
	switch(input) {
		case '1': return 1;
		case '2': return 2;
		default : printMessage("Invalid input!");
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
