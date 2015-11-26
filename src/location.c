/*------------------------------------------------------------------------------
| NuCTE		| location.c
| Author	| Benjamin E Allen
| Date		| 25 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Implement location code
\-----------------------------------------------------------------------------*/

#include "location.h"
#include "io.h"

void describeLocation(struct location loc) {
	char* desc = loc.description;
	printMessage(desc);
}
