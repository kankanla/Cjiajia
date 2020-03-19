#include <iostream>
#include <cstring>

// A template for the "max" function

template<typename kind> 
kind max(kind d1, kind d2) {
    if (d1 > d2)
        return (d1);
    return (d2);
}

// A specialization for the "max" function 
//   because we handle char * a little differently
const char *const max(const char *const d1, const char *const d2) {
    if (std::strcmp(d1, d2) > 0)
        return (d1);
    return (d2);
}

int main()
{
    // Let's test out max
    std::cout << "max(1,2) " << max(1,2) << '\n';
    std::cout << "max(2,1) " << max(2,1) << '\n';

    std::cout << "max(\"able\", \"baker\") " << 
	          max("able", "baker") << '\n';

    std::cout << "max(\"baker\", \"able\") " << 
	          max("baker", "able") << '\n';
    return (0);
}
