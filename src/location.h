/*------------------------------------------------------------------------------
| NuCTex	| location.h
| Author	| Benjamin A - Nullsrc
| Created	| 25 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Define structs and functions used in the location code
\-----------------------------------------------------------------------------*/
#ifndef NULLSRC_LOCATION_HEADER
#define NULLSRC_LOCATION_HEADER

#include "items.h"
#define NOWHERE -1
#define LOCATION_INDEX_LIMIT 100

/* this is the main location structure.
one location represents one map tile */
typedef struct Location {
	int id;
	char* description;		// A string description of the location

	/* these are the location pointers. These will point to other locations that
	this location connects to. Set to a location that has been declared, and
	make sure that it makes sense. To create a "wall," set the pointer to 0
	in the initialization (location.c) */
	int n;
	int s;
	int e;
	int w;

	Inventory inv;
} Location;

typedef struct L_index {
	Location loc[LOCATION_INDEX_LIMIT];
}L_index;

L_index LIndex;

#endif /* NULLSRC_LOCATION_HEADER */
