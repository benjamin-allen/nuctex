/*------------------------------------------------------------------------------
| NuCTE		| command.c
| Author	| Benjamin E Allen
| Date		| 23 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Implement command functions.
\-----------------------------------------------------------------------------*/

#include "command.h"
#include "io.h"
#include "globals.h"

int g_isQuit = 0;

void callCommand(const char* input) {
	if(input == "quit") {
		quit();
	}
	else {
		printMessage("Invalid Command!");
	}
}

void quit() {
	g_isQuit = 1;
}
