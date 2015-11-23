/*------------------------------------------------------------------------------
| NuCTE		| output.cpp
| Author	| Benjamin E Allen
| Date		| 22 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Implement the functions defined in output.h, which handle all game
|			  output to the player
\-----------------------------------------------------------------------------*/

#include <cstdio>
#include "output.hpp"

// Generic print message function. Give it a string directly or give it a variable with a string in it.
void Output::printMessage(const char* message) {
	printf("%s\n", message);
}
