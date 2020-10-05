/********************************************************
 * split -- split a entry of the form Last/First	*
 *	into two parts.					*
 ********************************************************/
#include <iostream>
#include <cstring>
#include <cstdlib>

int main()
{
    char line[80];	// The input line
    char *first_ptr;	// pointer we set to point to the first name
    char *last_ptr;	// pointer we set to point to the last name 

    std::cin.getline(line, sizeof(line));

    last_ptr = line;	// last name is at beginning of line 

    first_ptr = strchr(line, '/');	// Find slash 

    // Check for an error 
    if (first_ptr == NULL) {
	std::cerr << "Error: Unable to find slash in " << line << '\n';
	exit (8);
    }

    *first_ptr = '\0';	// Zero out the slash 

    ++first_ptr;	// Move to first character of name 

    std::cout << "First:" << first_ptr << " Last:" << last_ptr << '\n';
    return (0);
}
/********************************************************
 * strchr -- find a character in a string		*
 *	Duplicate of a standard library function,	*
 *	put here for illustrative purposes.		*
 *							*
 * Parameters						*
 *	string_ptr -- string to look through		*
 *	find -- character to find			*
 *							*
 * Returns 						*
 *	pointer to 1st occurrence of character in string*
 *	or NULL for error				*
 ********************************************************/
char *strchr(char * string_ptr, char find)
{
    while (*string_ptr != find) {

       // Check for end 

       if (*string_ptr == '\0')
	   return (NULL);	// not found 

	++string_ptr;
    }
    return (string_ptr);	// Found 
}
