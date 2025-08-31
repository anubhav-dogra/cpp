#include <array>
#include <cstddef>
#include <iostream>
#include <vector>

/*void PrintArray1(int arr[]) { std::cout << "sizeof" << sizeof(arr) << std::endl; }*/
/* NOT CORRECT=> its only passed by pointer(which is first address only)*/

void PrintArray2(int arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {

        std::cout << arr[i] << std::endl;
    }
}
void PrintArray(std::array<int, 5> arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

// GOOD WAY
void PrintVector(const std::vector<int> &vec) // const if not modifying the variable
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}
int main(int argc, char *argv[])
{
    int array1[] = {1, 2, 3, 4};
    /*PrintArray1(array1);*/

    // onw way
    PrintArray2(array1, sizeof(array1) / sizeof(int));

    // another way
    std::array<int, 5> array = {1, 3, 4, 5, 6};
    PrintArray(array, sizeof(array) / sizeof(int));

    // Good way
    std::vector<int> myVec = {11, 22, 33, 44, 55};
    PrintVector(myVec);
    return 0;
}
