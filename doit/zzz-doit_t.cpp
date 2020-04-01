#include <iostream>

class simple {
public:
	int do_it(int i) {
		return i++;
	}
	float do_it(float f) {
		std::cout << "simple float " << (f / 2) << '\n';
		return (f / 2);
	}
};

class derived: public simple {
public:
	int do_int(int i, int j) {
		return i + j;
	}
};

int main(int argc, char const *argv[])
{

	//非継承
	simple var;
	int a;
	float b;
	a = var.do_it(5);
	b = var.do_it(6.3f);
	std::cout << "a " << a << '\n';
	std::cout << "b " << b << '\n';

	//継承
	derived var2;
	int c;
	float d;

	c = var2.do_int(2, 4);
	// d = var2.do_int(9.3f);	//Fails;
	return 0;
}

