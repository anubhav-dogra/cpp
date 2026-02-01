/*
Goal: show array basics, decay to pointer, sizes, and passing to functions.
Key takeaways:
- The array name converts to a pointer to the first element in most expressions.
- *(array + i) equals array[i].
- sizeof(array) is total bytes in the same scope, but decays in functions.
Exercise: change the loop to print addresses and values together.
*/
#include <array>
#include <cstddef>
#include <iostream>
#include <vector>

// Arrays decay to pointers when passed to functions.
void PrintArrayDecay(const int *arr)
{
    // Here arr is just a pointer; size information is lost.
    std::cout << "sizeof(arr) in function: " << sizeof(arr) << std::endl;
}

// Pass size explicitly for raw arrays.
void PrintArrayWithSize(const int arr[], std::size_t size)
{
    for (std::size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

// Reference to a fixed-size array (no decay). Only accepts size 5.
void PrintFixedArrayRef(const int (&arr)[5])
{
    std::cout << "fixed array size: " << sizeof(arr) / sizeof(arr[0]) << std::endl;
    for (std::size_t i = 0; i < 5; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

// std::array keeps size information; use a template for any size.
template <std::size_t N>
void PrintStdArray(const std::array<int, N> &arr)
{
    std::cout << "std::array size: " << arr.size() << std::endl;
    for (std::size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

// std::vector is dynamic-size (covered in detail later).
void PrintVector(const std::vector<int> &vec)
{
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}

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

    // sizeof gives total bytes for arrays in the same scope
    std::cout << "sizeof(array): " << sizeof(array) << std::endl;
    std::cout << "sizeof(px): " << sizeof(px) << std::endl;
    std::cout << "array length: " << sizeof(array) / sizeof(array[0]) << std::endl;

    PrintArrayDecay(array);
    PrintArrayWithSize(array, sizeof(array) / sizeof(array[0]));
    PrintFixedArrayRef(array);

    std::array<int, 5> stdarr = {1, 3, 4, 5, 6};
    PrintStdArray(stdarr);

    std::vector<int> myVec = {11, 22, 33, 44, 55};
    PrintVector(myVec);

    // show the array offset
    for (int i = 0; i < 5; i++)
    {
        std::cout << "addr: " << static_cast<void *>(&array[i]) << " value: " << array[i] << std::endl;
        std::cout << *(px + i) << std::endl;
        std::cout << *(array + i) << std::endl;
        std::cout << array[i] << std::endl;
    }

    return 0;
}
