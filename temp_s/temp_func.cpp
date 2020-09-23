#include <iostream>
#include <string>

template<typename t1, typename t2>
bool less(t1 v1, t2 v2) {
    std::cout << "Template called\n";
    return (v1 < v2);
}

template<typename t1, char *t2>
bool less<t1>(t1 v1, char *v2) {
    std::cout << "Template(char*) called\n";
    return (v1 < std::string(v2));
}

int main()
{
    char *foo;
    std::string bar("bar");
    bool b;

    b = less(1, 3);
    b = less(bar, foo);
    return (0);
}


