/********************************************************
 * Stack						*
 *	A set of routines to implement a simple integer	*
 *	stack.						*
 *							*
 * Procedures						*
 *	stack_init -- initalize the stack.		*
 *	stack_push -- put an item on the stack.		*
 *	stack_pop -- remove an item from the stack.	*
 ********************************************************/
#include <assert.h>
#include <cstdlib>
#include <iostream>

const int STACK_SIZE = 100;	// Maximum size of a stack

// The stack itself
struct stack {
   int count;			// Number of items in the stack
   int data[STACK_SIZE];	// The items themselves
};

/********************************************************
 * stack_init -- initialize the stack.			*
 *							*
 * Parameters						*
 *	the_stack -- stack to initalize			*
 ********************************************************/
inline void stack_init(struct stack& the_stack)
{
    the_stack.count = 0;	// Zero the stack
}
/********************************************************
 * stack_push -- push an item on the stack.		*
 *							*
 * Warning: We do not check for overflow.		*
 *							*
 * Parameters						*
 *	the_stack -- stack to use for storing the item	*
 *	item -- item to put in the stack		*
 ********************************************************/
inline void stack_push(struct stack& the_stack,
		       const int item)
{
    assert((the_stack.count >= 0) &&
	   (the_stack.count < 
	     sizeof(the_stack.data)/sizeof(the_stack.data[0])));

    the_stack.data[the_stack.count] = item;
    ++the_stack.count;
}
/********************************************************
 * stack_pop -- get an item off the stack.		*
 *							*
 * Warning: We do not check for stack underflow.	*
 *							*
 * Parameters						*
 *	the_stack -- stack to get the item from		*
 *							*
 * Returns						*
 * 	The top item from the stack.			*
 ********************************************************/
inline int stack_pop(struct stack& the_stack)
{
    // Stack goes down by one
    --the_stack.count;

    assert((the_stack.count >= 0) &&
	   (the_stack.count < 
	     sizeof(the_stack.data)/sizeof(the_stack.data[0])));

    // Then we return the top value
    return (the_stack.data[the_stack.count]);
}

// A short routine to test the stack
int main()
{
    struct stack a_stack;	// Stack we want to use

    stack_init(a_stack);

    // Push three value on the stack
    stack_push(a_stack, 1);
    stack_push(a_stack, 2);
    stack_push(a_stack, 3);

    // Pop the item from the stack
    std::cout << "Expect a 3 ->" << stack_pop(a_stack) << '\n';
    std::cout << "Expect a 2 ->" << stack_pop(a_stack) << '\n';
    std::cout << "Expect a 1 ->" << stack_pop(a_stack) << '\n';

    return (0);
}
