/*------------------------------------------------------------------------------
| NuCTex	| location.h
| Author	| Benjamin A - Nullsrc
| Created	| 25 November, 2015
| Changed	| 4 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Define structs and functions used in the location code
\-----------------------------------------------------------------------------*/
#ifndef NULLSRC_LOCATION_HEADER
#define NULLSRC_LOCATION_HEADER

/* this is the main location structure.
one location represents one map tile */
typedef struct Location {
	char* description;		// A string description of the location

	/* these are the location pointers. These will point to other locations that
	this location connects to. Set to a location that has been declared, and
	make sure that it makes sense. To create a "wall," set the pointer to 0
	in the initialization (location.c) */
	struct Location* n;
	struct Location* s;
	struct Location* e;
	struct Location* w;
} Location;

// current game locations
Location nw;
Location ne;
Location sw;
Location se;
Location dead;

#endif /* NULLSRC_LOCATION_HEADER */
