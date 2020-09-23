#include <iostream>
#include <cstring>

/********************************************************
 * tmp_name -- return a temporary file name		*
 *							*
 * Each time this function is called, a new name will	*
 * be returned.						*
 *							*
 * Returns						*
 * 	Pointer to the new file name.			*
 ********************************************************/
char *tmp_name()
{
    char name[30];		// The name we are generating 
    static int sequence = 0;	// Sequence number for last digit 

    ++sequence;	// Move to the next file name 

    strcpy(name, "tmp");

    // Put in the sequence digit 
    name[3] = static_cast<char>(sequence + '0');

    // End the string 
    name[4] = '\0';

    return(name);
}

int main()
{
    std::cout << "Name: " << tmp_name() << '\n';
    return(0);
}
