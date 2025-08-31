// where the address of the variable is?
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
    /*&char are considered as strings in cpp ? ! confused !*/
    /*b: bc**/
    /*c: c**/

    // correct way
    std::cout << "Correct way for char or functions" << std::endl;
    std::cout << "a: " << (void *)&a << std::endl;
    std::cout << "b: " << (void *)&b << std::endl;
    std::cout << "c: " << (void *)&c << std::endl;
    std::cout << "function: " << (void *)&foo << std::endl;
    std::cout << "main function: " << (void *)&main << std::endl;

    return 0;
}
