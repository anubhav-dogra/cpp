/*
Goal: understand const correctness and how to query types.
Key takeaways:
- const prevents mutation through that name/reference.
- Use const references to avoid copies when read-only.
Notes: see notes/const.md for deeper rules and examples.
*/
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>

void PassbyRef(const std::vector<int> &alias)
{
    std::cout << "vector size via const ref: " << alias.size() << std::endl;
    // alias[0] = 42; // error: cannot modify through const reference
}

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

    int value = 10;
    const int *ptr_to_const = &value; // pointer to const int
    int *const const_ptr = &value;    // const pointer to int
    const int *const const_ptr_to_const = &value;

    // *ptr_to_const = 20; // error: cannot modify through ptr_to_const
    *const_ptr = 20; // ok: pointer is const, value is not
    // const_ptr = &x; // error: cannot reassign const pointer

    std::cout << "ptr_to_const sees: " << *ptr_to_const << std::endl;
    std::cout << "const_ptr sees: " << *const_ptr << std::endl;
    std::cout << "const_ptr_to_const sees: " << *const_ptr_to_const << std::endl;
    return 0;
}
