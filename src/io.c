/*------------------------------------------------------------------------------
| NuCTE		| io.c
| Author	| Benjamin E Allen
| Date		| 22 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Implement member functions of io.h
\-----------------------------------------------------------------------------*/

#include "io.h"
#include <stdio.h>
#include <string.h>

char g_command[64];

void printMessage(char* message) {
	printf("%s\n", message);
}

char* removeNewline(char* line) {
	char* pos;
	if((pos=strchr(line, '\n')) != NULL) {
		*pos = '\0';
	}
}

char* getInput() {
	char* pLine = g_command;

	fgets(pLine, 64, stdin);
	removeNewline(pLine);

	return pLine;
};

void debugInput(char* line) {
	printMessage("BEGINNING DEBUG OF CSTRING");
	int i = 0;
	while (line[i] != 0) {
		printf("%c", line[i]);
		i++;
	}
	printf("\n");
	printMessage("ENDING DEBUG OF CSTRING");
}
