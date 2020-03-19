/********************************************************
 * infinite-array -- routines to handle infinite arrays *
 *                                                      *
 * An infinite array is an array that grows as needed.  *
 * There is no index too large for an infinite array    *
 * (unless we run out of memory).                       *
 ********************************************************/
#include <iostream>
#include <cstdlib>
#include <assert.h>

#include "ia.h"                 // get common definitions 

/********************************************************
 * operator [] -- find an element of an infinite array  *
 *                                                      *
 * Parameters                                           *
 *      index   -- index into the array                 *
 *                                                      *
 * Returns                                              *
 *      Reference to the element in the array		*
 ********************************************************/
int& infinite_array::operator [] (const unsigned int index)
{
    // pointer to the current bucket 
    class infinite_array *current_ptr;

    unsigned int current_index;	// Index we are working with

    current_ptr = this;
    current_index = index;

    while (current_index >= BLOCK_SIZE) {
        if (current_ptr->next == NULL) {
            current_ptr->next = new infinite_array;
            if (current_ptr->next == NULL) {
		std::cerr << "Error:Out of memory\n";
                exit(8);
            }
        }
        current_ptr = current_ptr->next;
        current_index -= BLOCK_SIZE;
    }
    assert(current_index >= 0);
    assert(current_index < 
	    sizeof(current_ptr->data)/sizeof(current_ptr->data[0]));
    return (current_ptr->data[current_index]);
}

/********************************************************
 * ~infinite_array -- Destroy the infinite array	*
 ********************************************************/
infinite_array::~infinite_array()
{
    /*
     * Note: We use a cute trick here.
     *
     * Because each bucket in the infinite array is
     * an infinite array itself, when we destroy
     * next, it will destroy all that bucket's "next"s
     * and so on recusively clearing the entire array.
     */
    if (next != NULL) {
       delete next;
       next = NULL;
    }
}
