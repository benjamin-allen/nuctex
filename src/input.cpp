/*------------------------------------------------------------------------------
| NuCTE		| input.cpp
| Author	| Benjamin E Allen
| Date		| 22 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Implement member functions of Input
\-----------------------------------------------------------------------------*/

#include "input.hpp"
#include "output.hpp"
#include <iostream>
#include <string>

// Catch-all function to capture a line of input.
const char* Input::getInput() { 
	std::string rawInput; // Create a string for the raw input
	getline(std::cin, rawInput); // Get rawInput from the cin inputstream. 
	
	const char* returnedInput = rawInput.c_str(); // Convert the string to a c-string
	return returnedInput;
}

// Debugging function to ensure that input is being captured properly. Kept here for legacy purposes.
void Input::printInputBack(const char* input) {
	Output print; // Very briefly allocate an output object.
	print.printMessage(input); // print out that output object.
}
