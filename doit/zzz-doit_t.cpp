#include <iostream>

class simple {
public:
	float do_it2(float f) {
		return (f * 2);
	}

	int do_it(int j, int i) {
		return (j + i);
	}
};

class derived: public simple {
public:
	float do_it2(float f) {
		return (f * 3);
	}
};

int main(int argc, char const *argv[])
{

	derived var;
	float f;
	int i;

	f = var.do_it2(3.2f);
	i = var.do_it(1, 2);
	std::cout << f << "ff\n";
	std::cout << i << "ff\n";

	/* code */
	return 0;
}