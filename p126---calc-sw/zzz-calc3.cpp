#include <iostream>

int r;
char o;
int v;

/*
	正常動作
*/


int main(int argc, char const *argv[])
{
	r = 0;

	while (1) {
		std::cin >> o >> v;

		if ((o == 'q') || (o == 'Q')) {
			break;
		}

		switch (o) {
		case '+':
			r += r;
			break;
		case '-':
			r -= r;
			break;
		case '/':
			if (v == 0) {
				std::cout << "V==0 \n";
			} else {
				r /= v;
			}
			break;

		default:
			std::cout << "default \n";
			break;
		}
	}

	std::cout << "if break" << std::endl;

	return 0;
}