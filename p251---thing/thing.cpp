#include <iostream>

int main()
{
    int   thing_var;  // define a variable 
    int  *thing_ptr;  // define a pointer 

    thing_var = 2;      // assigning a value to thing
    std::cout <<"Thing " << thing_var << '\n';

    thing_ptr = &thing_var; // make the pointer point to thing
    *thing_ptr = 3;     // thing_ptr points to thing_var so
                        // thing_var changes to 3
    std::cout << "Thing " << thing_var << '\n';

    // another way of printing the data
    std::cout << "Thing " << *thing_ptr << '\n';
    return (0);
}
