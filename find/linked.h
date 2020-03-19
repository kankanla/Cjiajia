#include <string>
// Define an element of a linked list
class linked_list_element {
    public:
	std::string data;		// Data for the element
    private:
	// Pointer to the next element
	class linked_list_element *next_ptr;
    
    friend class linked_list;	// The list itself
};

// The linked list
class linked_list {
    private:
  	linked_list_element *first_ptr;	// First element of the list

    public:
	// Create the list
	linked_list() { first_ptr = NULL; };
	~linked_list();	// Destroy the list
    private:
	// Don't allow use of the copy constructor
	linked_list(const linked_list&);	

    public:
	// Find an element in the list
	bool find(const std::string& name);
        
};
