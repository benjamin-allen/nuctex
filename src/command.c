/*------------------------------------------------------------------------------
| NuCTE		| command.c
| Author	| Benjamin E Allen
| Date		| 23 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Implement command functions.
\-----------------------------------------------------------------------------*/

#include <string.h>
#include "command.h"
#include "io.h"
#include "gamef.h"

// callCommand() ---
// Main game command parser. Basically a giant if-elseif-else statement. This
// thing will grow.
void callCommand(char* input) {

	// quit command
	if(strcmp(input, "quit") == 0) {	// strcmp returns 0 on truth. I hate it
		quit();							// but that's how it is.
	}

	// default "no-match" response
	else {
		printMessage("Invalid Command!");
	}
}
