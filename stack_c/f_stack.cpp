// The stack itself
class stack {
    private:
	int count;		// Number of items in the stack
	int data[STACK_SIZE];	// The items themselves
    public:
	// Initialize the stack
	void init();

	// Push an item on the stack
	void push(const int item);

	// Pop an item from the stack
	int pop();

	friend int stack_equal(const stack& s1, const stack& s2);
};
