#include <iostream>

void t1(char &b);
int main(int argc, char const *argv[])
{
	char b ='A';
	t1(b);
	std::cout << b << std::endl;
}

void t1(char &b){
	for(int j=0; j< 10000; j++){
		for(int i=0; i<90000000; i++){

		}
		std::cout << j << "  " << std::endl;
	}
	b='C';
}