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
	Output output;
	Input input;

	bool isQuit = false;

	while(isQuit == false) {
		const char* command;
		command = input.getInput();

		if (strcmp(command, "quit") == 0) {
			isQuit = true;
		}
		else {
			output.printMessage(command);
		}
	}

	return 0;
}
