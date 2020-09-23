/********************************************************
 * An experment in partial template specilization.	*
 ********************************************************/
#include <iostream>
#include <string>

template<typename T1, typename T2>
class foo {
    public:
	foo(T1 x, T2 y) {
	    std::cout << "foo(T1, T2)\n";
	}
};

template<typename T1>
class foo<T1, T1> {
    public:
	foo(T1 x, T1 y) {
	    std::cout << "foo(T1, T1)\n";
	}
};
template<typename T1>
class foo<T1, char *> {
    public:
	foo(T1 x, char *y) {
	    std::cout << "foo(T1, char *)\n";
	}
};

template<typename T1, typename T2>
void bar(T1 x, T2 y)
{
    std::cout << "bar(T1, T2)\n";
}

template<typename T1>
void bar(T1 x, T1 y)
{
    std::cout << "bar(T1, T1)\n";
}

int main()
{
    foo<int, double> f1(38, 34.5);
    foo<int, int> f2(38, 38);
    foo<int, char *> f3(38, "sam");
    bar<int, double>(38, 34.5);
    bar<int>(38, 38);
    bar(38, 38.5);
    bar(38, 38);
    return (0);
}


