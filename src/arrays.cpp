#include <iostream>
int main(int argc, char *argv[])
{
    int array[] = {1, 2, 3, 4, 5};
    int *px = array;

    std::cout << "first element: " << array[0] << std::endl;
    std::cout << "px is: " << px << std::endl;  // actually pointing to 1st address
    std::cout << "px is: " << *px << std::endl; // actually pointing to 1st value

    px++;
    std::cout << "px address: " << px << std::endl; // actually pointing to 2nd address
    std::cout << "px is: " << *px << std::endl;     // actually pointing to 2nd value

    px--;

    // show the array offset
    for (int i = 0; i < 5; i++)
    {

        std::cout << *(px + i) << std::endl;
        std::cout << *(array + i) << std::endl;
        std::cout << array[i] << std::endl;
    }

    return 0;
}
