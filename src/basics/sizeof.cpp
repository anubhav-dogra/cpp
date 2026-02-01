/*
Goal: understand sizeof on objects vs pointers.
Key takeaways:
- sizeof(pointer) is size of address, not pointed data.
- sizeof(vector) is the control block, not element count.
Notes: see notes/sizeof.md for real-world uses and caveats.
*/
#include <iostream>
#include <vector>
int main(int argc, char *argv[])
{
    int x = 5;
    // pointer
    int *px = &x;
    // stack allocated array
    int array[] = {1, 2, 3, 4, 6};
    // heap allocated array
    int *dynamicallyAllocatedArray = new int[1000];

    std::vector<int> v;
    v.push_back(1);
    v.push_back(1);

    std::cout << "x                              :" << sizeof(x) << std::endl; // 4 bytes
    std::cout << "px                             :" << sizeof(px)
              << std::endl; // 8 bytes giving size of the address (pointer)
    std::cout << "array                          :" << sizeof(array) << std::endl; // 5 elements * 4 bytes
    std::cout << "dynamicallyAllocatedArray      :" << sizeof(dynamicallyAllocatedArray)
              << std::endl; // pointing to the first element,or size of a pointer!

    std::cout << "v                              :" << sizeof(v)
              << std::endl; // size of control structure, not elements
    std::cout << "v.size (used) and v.capacity (reserved): " << v.size() << " and " << v.capacity() << std::endl;

    std::cout << "growth demo (size/capacity):" << std::endl;
    std::vector<int> grow;
    for (int i = 0; i < 10; i++)
    {
        grow.push_back(i);
        std::cout << "push " << i << " -> size " << grow.size() << ", capacity " << grow.capacity() << std::endl;
    }
    return 0;
}
