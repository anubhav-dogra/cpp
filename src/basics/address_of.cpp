/*
Goal: print addresses and see how different types show up.
Key takeaways:
- & gives the address; printing char* shows as C-string by default.
- Cast to void* to print raw addresses for char and functions.
*/
// where the address of the variable is?
#include <cstdint>
#include <iostream>

void foo() {}

int main(int argc, char *argv[])
{
    // stack of memory
    int x = 42;
    float y = 72;
    char a = 'a';
    signed char b = 'b';
    unsigned char c = 'c';

    std::cout << "x: " << &x << std::endl;
    // or
    std::cout << "x: " << &(x) << std::endl;

    std::cout << "y: " << &y << std::endl;
    std::cout << "a: " << &a << std::endl;
    std::cout << "b: " << &b << std::endl;
    std::cout << "c: " << &c << std::endl;
    std::cout << "function: " << &foo << std::endl;

    /*x: 0x7ffebf9b3100*/
    /*y: 0x7ffebf9b3104*/

    /*a: abc**/
    /*char* prints as a C-string (until '\0'), not the raw address*/
    /*b: bc**/
    /*c: c**/

    // correct way: cast to void* to print the raw address
    // See notes/casts.md for why static_cast is preferred in C++.
    std::cout << "Correct way for char or functions" << std::endl;
    std::cout << "a: " << static_cast<void *>(&a) << std::endl;
    std::cout << "b: " << static_cast<void *>(&b) << std::endl;
    std::cout << "c: " << static_cast<void *>(&c) << std::endl;
    // Function pointers cannot be converted to void* in standard C++.
    std::cout << "function: " << reinterpret_cast<std::uintptr_t>(&foo) << std::endl;
    std::cout << "main function: " << reinterpret_cast<std::uintptr_t>(&main) << std::endl;

    return 0;
}
