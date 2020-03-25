/********************************************************
 * DataBase -- A very simple database program to	*
 *		lookup names in a hardcoded list.	*
 * 							*
 * Usage:						*
 *	database					*
 *		Program will ask you for a name.	*
 *		Enter the name; it will tell you if	*
 *		it is the list.				*
 *							*
 *		A blank name terminates the program.	*
 ********************************************************/
const int STRING_LENGTH = 80;	/* Length of typical string */
#include <iostream>
#include <string>

int main()
{
	std::string name;	// a name to lookup

	bool lookup(const std::string&); // lookup a name

	while (true) {
		std::cout << "Enter name: ";
		std::getline(std::cin, name);

		// Check for blank name
		if (name.length() <= 0)
			break;

		if (lookup(name))
			std::cout << name << " is in the list\n";
		else
			std::cout << name << " is not in the list\n";
	}
	return (0);
}
/********************************************************
 * lookup -- lookup a name in a list			*
 *							*
 * Parameters						*
 *	name -- name to lookup				*
 *							*
 * Returns						*
 *	true -- name in the list			*
 *	false -- name not in the list			*
 ********************************************************/
bool lookup(const std::string& name)
{
	// List of people in the database
	// Note: Last name is a NULL for end of list
	static char *list[] = {
		"John",
		"Jim",
		"Jane",
		"Clyde",
		NULL
	};
	// We are using C style strings for the list because
	// we can create an initialized array of C style string while
	// we can't do that with the C++ string class

	int index;		// index into list

	for (index = 0; list[index] != NULL; ++index) {
		if (std::string(list[index]) == name)
			return (true);
	}
	return (false);
}
