/********************************************************
 * Stack						*
 *	A file implementing a simple stack class	*
 ********************************************************/
#include <cstdlib>
#include <iostream>
#include <assert.h>

const int STACK_SIZE = 100;	// Maximum size of a stack

/********************************************************
 * bound_err -- a class used to handle out of bounds	*
 *		execeptions.				*
 ********************************************************/
class bound_err {
    public:
	const string what;	// What caused the error

	// Initialize the bound error with a message
	bound_err(const string& i_what) what(i_what) {}
	// Assignment operator defaults
	// bound_err(bound_err) -- default copy constructor
	// ~ bound_err -- default destructor
};

/********************************************************
 * Stack class						*
 *							*
 * Member functions					*
 *	init -- initialize the stack.			*
 *	push -- put an item on the stack.		*
 *	pop -- remove an item from the stack.		*
 ********************************************************/
// The stack itself
class stack {
    private:
	int count;		// Number of items in the stack
	int data[STACK_SIZE];	// The items themselves
    public:
	// Initialize the stack
	stack(): count(0) {};
	// Copy constructor defaults
	// Assignment operator defaults

	// Push an item on the stack
	void push(const int item) throw(bound_err);

	// Pop an item from the stack
	int pop() throw(bound_err);
};
/********************************************************
 * stack::push -- push an item on the stack.		*
 *							*
 * Warning: We do not check for overflow.		*
 *							*
 * Parameters						*
 *	item -- item to put in the stack		*
 ********************************************************/
inline void stack::push(const int item) throw(bound_err)
{
    if ((count < 0) &&
	   (count >= sizeof(data)/sizeof(data[0]))) {
	throw("Push overflows stack");
    }
    data[count] = item;
    ++count;
}
/********************************************************
 * stack::pop -- get an item off the stack.		*
 *							*
 * Warning: We do not check for stack underflow.	*
 *							*
 * Returns						*
 * 	The top item from the stack.			*
 ********************************************************/
inline int stack::pop() throw(bound_err)
{
    // Stack goes down by one
    --count;

    if ((count < 0) &&
	   (count >= sizeof(data)/sizeof(data[0]))) {
	throw("Pop underflows stack");
    }
    // Then we return the top value
    return (data[count]);
}
static stack test_stack;	// Define a stack for our bounds checking

/********************************************************
 * push_a_lot -- Push too much on to the stack		*
 ********************************************************/
static void push_a_lot() {
   int i;	// Push counter

    for (i = 0; i < 5000; i++) {
	test_stack.push(i);
    }
}

int main()
{
    try {
       push_a_lot();
    }
    catch (bound_err& err) {
       cerr << "Error: Bounds exceeded\n";
       cerr << "Reason: " << err.what << '\n';
       exit (8);
    }
    catch (...) {
       cerr << "Error: Unexpected exception occurred\n";
       exit (8);
    }
    return (0);
}

