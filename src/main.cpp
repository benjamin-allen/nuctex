/*------------------------------------------------------------------------------
| NuCTE		| main.cpp
| Author	| Benjamin E Allen
| Date		| 22 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Initialize main game loop. Doesn't do much yet.
\-----------------------------------------------------------------------------*/

#include "output.hpp"
#include "input.hpp"
#include <string.h>

int main() {
	Output output; // Create an output object to be used in the main game loop
	Input input; // Create an input object to be used in the main game loop

	bool isQuit = false; // Flag for stopping the game loop.

	while(isQuit == false) {
		const char* command; // Happy little command variable. TODO: Remove const?
		command = input.getInput(); // Save the output of getInput() to command

		if (strcmp(command, "quit") == 0) {	// If the command entered is 'quit'...
			isQuit = true; // ...quit the game.
		}
		else {
			output.printMessage(command); // Otherwise, print out the command just entered.
		}
	}

	return 0;
}
