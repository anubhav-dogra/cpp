#include <iostream>
#include <vector>
int main(int argc, char *argv[])
{
    int x = 5;
    // pointer
    int *px = &x;
    // stack allocated array
    int array[] = {1, 2, 3, 4, 6};
    // heap alloacated array
    int *dynamicallyAllocatedArray = new int[1000];

    std::vector<int> v;
    v.push_back(1);
    v.push_back(1);

    std::cout << "x                              :" << sizeof(x) << std::endl; // 4 bytes
    std::cout << "px                             :" << sizeof(px) << std::endl;
    std::cout << "array                          :" << sizeof(array) << std::endl; // 5 elements * 4 bytes
    std::cout << "dynamicallyAllocatedArray      :" << sizeof(dynamicallyAllocatedArray)
              << std::endl; // pointing to the first element

    std::cout << "v                              :" << sizeof(v)
              << std::endl; // size of actual data structure !!!  v.size() will give number of elemeents
    return 0;
}
