#include <iostream>

float answer;

/*
	answer = 1 / 3; ではなく
	answer = 1.0f / 3.0f; 必要
*/

int main(int argc, char const *argv[])
{
	answer = 1.0f / 3.0f;
	std::cout << answer << std::endl;
	return 0;
}