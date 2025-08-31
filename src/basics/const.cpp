#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

void PassbyRef(const std::vector<int> &alias) { /* cannot change the data now...*/ }

int main(int argc, char *argv[])
{
    const int x = 40;
    std::cout << "x: " << x << std::endl;

    // to check the type
    std::cout << std::is_const_v<int> << std::endl;
    std::cout << std::is_const_v<const int> << std::endl;

    // c++17 way
    std::cout << std::is_const<decltype(x)>::value << std::endl;

    std::vector<int> y(100);
    std::fill(std::begin(y), std::end(y), 1);
    PassbyRef(y);
    return 0;
}
