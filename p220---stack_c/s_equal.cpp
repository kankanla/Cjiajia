/********************************************************
 * stack_equal -- Test to see if two stacks are equal	*
 *							*
 * Parameters						*
 *	s1, s2 -- the two stacks			*
 *							*
 * Returns						*
 *	0 -- stacks are not equal			*
 *	1 -- stacks are equal				*
 ********************************************************/
int stack_equal(const stack& s1, const stack& s2)
{
    int index;	// Index into the items in the array

    // Check number of items first
    if (s1.count != s2.count)
	return (0);

    for (index = 0; index < s1.count; ++index) {

	assert((index >= 0) && 
	       (index < sizeof(s1.data)/sizeof(s1.data[0])));

	assert((index >= 0) && 
	       (index < sizeof(s2.data)/sizeof(s2.data[0])));

	if (s1.data[index] != s2.data[index])
	    return (0);
    }
    return (1);
}
