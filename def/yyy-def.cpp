#include <iostream>
#include <cstdlib>

/*
	確認必要
*/

int main(int argc, char const *argv[])
{
	char line[10];

	while (true) {
		std::cout << "Enter add(a), delete(d),quie(q):";
		std::cin.getline(line, sizeof(line));
		switch (line[0]) {
		case 'a':
			std::cout << "Add\n";
			break;
		case 'b':
			std::cout << "Delete\n";
			break;
		case'q':
			std::cout << "Quit\n";
			exit(0);
			break;
		defualt:
			std::cout << "Error:Bad command " << line[0] << '\n';
			std::cout << line << std::endl;
			break;
		}
	}
	return 0;
}