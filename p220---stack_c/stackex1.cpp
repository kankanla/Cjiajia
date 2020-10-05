/********************************************************
 * Stack						*
 *	A file implementing a simple stack class	*
 ********************************************************/
#include <cstdlib>
#include <iostream>

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
class stack {
    protected:
	int count;		// Number of items in the stack
    private:
	int data[STACK_SIZE];	// The items themselves
    public:
	// Initialize the stack
	stack();
	// ~stack() -- default destructor
	// copy constructor defaults

	// Push an item on the stack
	void push(const int item);

	// Pop an item from the stack
	int pop();
};

/********************************************************
 * stack::stack -- initialize the stack.		*	
 ********************************************************/
inline stack::stack()
{
    count = 0;	// Zero the stack
}
/********************************************************
 * stack::push -- push an item on the stack.		*
 *							*
 * Warning: We do not check for overflow.		*
 *							*
 * Parameters						*
 *	item -- item to put in the stack		*
 ********************************************************/
inline void stack::push(const int item)
{
    assert((count >= 0) &&
	   (count < sizeof(data)/sizeof(data[0])));

    data[count] = item;
    ++count;
}
/********************************************************
 * stack::pop -- get an item off the stack.		*
 *							*
 * Warning: We do not check for stack underflow.	*
 *							*
 * Parameters						*
 *	the_stack -- stack to initalize			*
 *							*
 * Returns						*
 * 	The top item from the stack.			*
 ********************************************************/
inline int stack::pop()
{
    // Stack goes down by one
    --count;

    assert((count >= 0) &&
	   (count < sizeof(data)/sizeof(data[0])));

    // Then we return the top value
    return (data[count]);
}

/********************************************************
 * bound_err -- a class used to handle out of bounds	*
 *		exceptions.				*
 ********************************************************/
class bound_err {
    public:
	char *what;	// What caused the error

	// Initialize the bound error with a message
	bound_err(char *i_what) {
	    what = i_what;
	}
	// bound_err(bound_err) -- default copy constructor
	// ~ bound_err -- default destructor
};

/********************************************************
 * b_stack -- bound checking stack.			*
 *							*
 * Member function					*
 *	push -- push an item on the stack		*
 *	pop -- remove an item from the stack.		*
 ********************************************************/
class b_stack: public stack {
    public:
	// b_stack -- default constructor
	// ~b_stack -- default destructor
	// copy constructor defaults

	// Push an item on the stack
	void push(const int item);

	// Remove an item from the stack
	int pop();
};
/********************************************************
 * b_stack::push -- push an item on the stack.		*
 *							*
 * Parameters						*
 *	item -- item to put in the stack		*
 ********************************************************/
inline void b_stack::push(const int item)
{
    assert(count >= 0);	// This should never happen

    if (count >= STACK_SIZE) {
	bound_err overflow("Push overflows stack");
	throw overflow;
    }
    stack::push(item);
}
/********************************************************
 * b_stack::pop -- get an item off the stack.		*
 *							*
 * Returns						*
 * 	The top item from the stack.			*
 ********************************************************/
inline int b_stack::pop()
{
    if (count <= 0) {
	throw bound_err("Pop causes stack underflow");
    }
    return (stack::pop());
}

b_stack test_stack;	// Define a stack for our bounds checking

void push_a_lot() {
   int i;	// Push counter

    for (i = 0; i < 5000; ++i) {
	test_stack.push(i);
    }
}

int main()
{
    try {
       push_a_lot();
    }
    catch (bound_err& err) {
	std::cerr << "Error: Bounds exceeded\n";
	std::cerr << "Reason: " << err.what << '\n';
	exit (8);
    }
    catch (...) {
	std::cerr << "Error: Unexpected exception occurred\n";
	exit (8);
    }
    return (0);
}

