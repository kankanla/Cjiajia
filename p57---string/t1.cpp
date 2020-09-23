#include <iostream>
#include <string>

void test(std::string& b) {
    std::cout << b << std::endl;
    b = "abc";
}

int main(int argc, char const *argv[])
{
    std::string name = "namew";
    test(name);
    std::cout << name << std::endl;
    return 0;
}