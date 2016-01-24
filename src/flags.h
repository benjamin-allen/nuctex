/*------------------------------------------------------------------------------
| NuCTex	| flags.h
| Author	| Benjamin A - Nullsrc
| Created	| 23 January, 2016
|-------------------------------------------------------------------------------
| Overview	| Declare flags struct
\-----------------------------------------------------------------------------*/

#ifndef NULLSRC_FLAGS_HEADER
#define NULLSRC_FLAGS_HEADER

#define MAX_FLAG_AMOUNT 5

typedef struct Flag {
	int id;
	char* name;
} Flag;

Flag sharp;

#endif /* NULLSRC_FLAGS_HEADER */
