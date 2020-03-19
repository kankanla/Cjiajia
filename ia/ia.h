/********************************************************
 * definitions for the infinite array (ia) class        *
 *                                                      *
 * An infinite array is an array whose size can grow    *
 * as needed.  Adding more elements to the array        *
 * will just cause it to grow.                          *
 *------------------------------------------------------*
 * class infinite_array                                 *
 *    Member functions					*
 *      infinite_array()  -- default constructor	*
 *	~infinite_array() -- destructor 		*
 *	int& operator [](int index)			*
 *		gets an element of the infinite array	*
 ********************************************************/
#include <string.h>

// number of elements to store in each cell of the infinite array 
const unsigned int BLOCK_SIZE = 10;
	
class infinite_array {
    private:
	// the data for this block 
	int   data[BLOCK_SIZE];       

	// pointer to the next array 
	class infinite_array *next;
    public:
	// Default constructor
	infinite_array() 
        { 
	    next = NULL;
	    memset(data, '\0', sizeof(data));
        }

	// Default destructor
	~infinite_array();

	// Return a reference to an element of the array
	int& operator[] (const unsigned int index);
};
