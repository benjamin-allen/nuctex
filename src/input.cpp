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

const char* Input::getInput() {
	std::string rawInput;
	getline(std::cin, rawInput);
	
	const char* returnedInput = rawInput.c_str();
	return returnedInput;
}

void Input::printInputBack(const char* input) {
	Output print;
	print.printMessage(input);
}
