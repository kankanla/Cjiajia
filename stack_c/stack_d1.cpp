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
 *	stack -- initialize the stack.			*
 *	push -- put an item on the stack.		*
 *	pop -- remove an item from the stack.		*
 ********************************************************/
// The stack itself
class stack {
    protected:
	int count;		// Number of items in the stack
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
 * m_stack -- Stack on which we can push multiple items *
 *							*
 * Member function					*
 *	push_many -- push an item on the stack		*
 ********************************************************/
class m_stack: public stack {
    public:
	// m_stack -- default constructor
	// ~m_stack -- default destructor
	// copy constructor defaults

	// Push three items on the stack
	void push_three(const int item1,
		  const int item2,
		  const int item3);

	// Sum the elements
	int sum();
};
/********************************************************
 * m_stack::push_three -- push an item on the stack.	*
 *							*
 * Parameters						*
 *	item1, item2, item3 -- 				*
 *		items to put in the stack		*
 ********************************************************/
inline void m_stack::push_three(const int item1, 
		const int item2, const int item3)
{
    stack::push(item1);
    stack::push(item2);
    stack::push(item3);
}
/********************************************************
 * m_stack::sum -- Sum the elements in the stack	*
 * 							*
 * Returns:						*
 * 	The elements in the stack.			*
 ********************************************************/
inline int m_stack::sum() {
    int index;		// Index into the array
    int total = 0;	// Running sum

    for (index = 0; index < count; ++index) {
	assert(index >= 0);
	assert(index < sizeof(data)/sizeof(data[0]));

	total += data[index];
    }
    return (total);
}
