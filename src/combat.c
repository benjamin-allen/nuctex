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

int combat(Actor* player, Actor* creature) {
	printMessage("The monster stands before you menacingly.");
	
	while(player->health > 0 && hasRun == 0 && creature->health > 0) {
		int action = fightMenu();
		switch(action) {
			case 0:
				break;
			case 1:
				attack(player, creature, 1);
				break;
			case 2:
				printMessage("You rest to regain your energy...");
				break;
			case 3:
				run(player, creature);
				break;
			default: printMessage("AH! THAT'S NOT OKAY!");
		}

		monsterAct(arng(10), player, creature); 
	}
	if(player->health <= 0) {
		printMessage("You have died.");
		return 1;
	}
	else if(hasRun != 0) {
		printMessage("You manage to flee the fight.");
		return 0;
	}
	else if(creature->health <=0) {
		printMessage("You slay the monster.");
		creature->actorPos = &dead;
		return 0;
	}
}

int fightMenu() {
	printMessage("1: Attack | 2: Rest | 3: Flee");
	char* choice = getInput();
	if(checkOne(choice, "1") == 0) {
		return 1;
	}
	else if(checkOne(choice, "2") == 0) {
		return 2;
	}
	else if(checkOne(choice, "3") == 0) {
		return 3;
	}
	else {
		return 0;
	}
}

void monsterAct(int number, Actor* player, Actor* creature) {
	if(number == 0) {
		printMessage("The monster is still, and appears to be taking a rest");
	}
	else {
		attack(creature, player, 0);
	}
}

void attack(Actor* attacker, Actor* defender, int isPlayerAttacking) {
	int damage = calcDamage(attacker->strength);
	defender->health -= damage;
	if(isPlayerAttacking == 1) {
		printDamage(damage, defender->name);
	}
	else {
		printf("The %s hits you and does %i damage!\n", attacker->name, damage);
	}
}

void run(Actor* escaping, Actor* chasing) {
	hasRun = runAway(escaping->agility, chasing->agility);
}
