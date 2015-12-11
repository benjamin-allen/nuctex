/*------------------------------------------------------------------------------
| NuCTex		| location.h
| Author	| Benjamin E Allen
| Date		| 25 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Define structs and functions used in the location code
\-----------------------------------------------------------------------------*/

typedef struct Location {
	char* description;

	struct Location* north;
	struct Location* south;
	struct Location* east;
	struct Location* west;
} Location;
