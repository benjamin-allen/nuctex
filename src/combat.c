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

void combat(Actor* player, Actor* creature) {
	while(player->health > 0 && hasRun == 0) {
		int action = inputAction();
		switch(action) {
			case 1: attack(player, creature);
				break;
			case 2: run(player, creature);
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
}

int inputAction() {
	while(1) {
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
}

void attack(Actor* attacker, Actor* defender) {
	defender->health -= calcDamage(attacker->strength);
}

void run(Actor* escaping, Actor* chasing) {
	hasRun = runAway(escaping->agility, chasing->agility);
}

int calcDamage(int strength) {
	int damageTotal = 0;
	damageTotal = strength;
	return damageTotal;
}

int runAway(int escapingAgility, int chasingAgility) {
	if(escapingAgility > chasingAgility) {
		return 1;
	}
	else {
		return 0;
	}
}
