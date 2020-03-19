#include <iostream>
#include <string>
#include "linked.h"
/********************************************************
 * find -- look for a data item in the list             *
 *                                                      *
 * Parameters                                           *
 *      name -- name to look for in the list          	*
 *                                                      *
 * Returns                                              *
 *      true if name is found                           *
 *      false if name is not found                      *
 ********************************************************/
bool linked_list::find(const std::string& name)
{
    /* current structure we are looking at */
    linked_list_element *current_ptr;

    current_ptr = first_ptr;

    while ((current_ptr->data != name != 0) &&
           (current_ptr != NULL))
        current_ptr = current_ptr->next_ptr;

    /*
     * If current_ptr is null, we fell off the end of the list and
     * didn't find the name
     */
    return (current_ptr != NULL);
}
