#include <iostream>

// This function won't work
void inc_counter(int counter)
{
    ++counter;
}

int main()
{
   int a_count = 0;	// Random counter

   inc_counter(a_count);
   std::cout << a_count << '\n';
   return (0);
}
