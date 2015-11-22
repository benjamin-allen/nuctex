/*------------------------------------------------------------------------------
| NuCTE		| output.hpp
| Author	| Benjamin E Allen
| Date		| 22 November, 2015
|-------------------------------------------------------------------------------
| Overview	| Define output class, used to relay information from the game to
|			| the player
\-----------------------------------------------------------------------------*/

class Output {
public:
	const char* message;

	void printMessage(const char* message);
};
