#include <iostream>

int countdown(int n)
{
    // base case
    if (n == 0)
    {
        std::cout << "0.......blast!!" << std::endl;
        return 0;
    }

    // recursive case
    std::cout << n << std::endl;
    return countdown(n - 1);
}

int main(int argc, char *argv[])
{
    countdown(10);
    return 0;
}
