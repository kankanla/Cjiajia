#include <cstdlib>
#include <iostream>
#include <assert.h>

const int STACK_SIZE = 100;	// Maximum size of a stack

/********************************************************
 * Stack class						*
 *							*
 * Member functions					*
 *	stack -- initalize the stack.			*
 *	push -- put an item on the stack.		*
 *	pop -- remove an item from the stack.		*
 ********************************************************/
// The stack itself
template<typename kind>
class stack {
    private:
	int count;		// Number of items in the stack
	kind data[STACK_SIZE];	// The items themselves
    public:
	// Initialize the stack
	stack() {
	    count = 0;	// Zero the stack
	}

	// Push an item on the stack
	void push(const kind item) {
	    assert(count >= 0);
	    assert(count < sizeof(data)/sizeof(data[0]));

	    data[count] = item;
	    ++count;
	}

	// Pop an item from the stack
	kind pop() {
	    // Stack goes down by one
	    --count;

	    assert(count >= 0);
	    assert(count < sizeof(data)/sizeof(data[0]));

	    // Then we return the top value
	    return (data[count]);
	}
};

