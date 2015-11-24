/*------------------------------------------------------------------------------
| NuCTE		| io.c
| Author	| Benjamin E Allen
| Date		| 22 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Implement member functions of input.h
\-----------------------------------------------------------------------------*/

#include "io.h"
#include <stdio.h>

void printMessage(const char* message) {
	printf("%s\n", message);
}

const char* getInput() {
	char* line;
	int lineLimit = 64;

	fgets(line, lineLimit, stdin);

	return line;
};

void debugInput(const char* line) {
	printMessage(line);
}
