#include<iostream>

int integer;
float floating;

int main(int argc, char const *argv[])
{
	floating = 1.0 / 2.0;
	integer = 1 / 3;
	floating = (1 / 2) + (1 / 2);
	floating = 3.0 / 2.0;
	std::cout << floating << std::endl;
	integer = floating;
	std::cout << integer << std::endl;
	return 0;
}