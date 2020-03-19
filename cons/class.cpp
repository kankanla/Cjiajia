#include <iostream>

class base_class {
    public:
	base_class() {
	    std::cout << "base_class constructor called\n";
	}
	~base_class() {
	    std::cout << "base_class destructor called\n";
	}
};
class derived_class:public base_class {
    public:
	derived_class() {
	    std::cout << "derived_class constructor called\n";
	}
	~derived_class() {
	    std::cout << "derived_class destructor called\n";
	}
};

