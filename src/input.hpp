/*------------------------------------------------------------------------------
| NuCTE		| input.hpp
| Author	| Benjamin E Allen
| Date		| 22 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Define the class used to handle player input.
\-----------------------------------------------------------------------------*/

class Input {
public:
	const char* input;

	const char* getInput();
	void printInputBack(const char*);
};
