#include <iostream>
#include <ostream>
#include <utility>
#include <vector>
class Array
{
    public:
        Array()
        {
            data = new int[10];
            for (int i = 0; i < 10; i++)
            {
                data[i] = i * i;
            }
        }
        ~Array() { delete[] data; }
        void PrintingData()
        {
            for (int i = 0; i < 10; i++)
            {
                std::cout << data[i] << std::endl;
            }
        }
        void SetData(int index, int value) { data[index] = value; }

    private:
        int *data;
};

// example with Copy constructor
class DArray
{
    public:
        DArray()
        {
            std::cout << "constructor called" << std::endl;
            data = new int[10];
            for (int i = 0; i < 10; i++)
            {
                data[i] = i * i;
            }
        }
        ~DArray()
        {
            delete[] data;
            std::cout << "Darray destructed" << std::endl;
        }
        // Copy constructor
        DArray(const DArray &righthandside)
        {
            std::cout << "Copy constructor called" << std::endl;
            data = new int[10];
            for (int i = 0; i < 10; i++)
            {
                data[i] = righthandside.data[i];
            }
        }
        // Copy assignment operator
        //   Object is already constructed, we are just making a copy later
        DArray &operator=(const DArray &righthandside)
        {
            std::cout << "Copy assignment operator called" << std::endl;
            if (&righthandside == this)
            {
                return *this;
            }
            if (data != nullptr)
            {
                delete[] data;
            }
            data = new int[10];
            for (int i = 0; i < 10; i++)
            {
                data[i] = righthandside.data[i];
            }
            return *this;
        }

        // move constructor policy
        DArray(DArray &&source)
        {
            data = source.data;
            source.data = nullptr;
            std::cout << "was move constructded" << std::endl;
        }
        DArray &operator=(DArray &&source)
        {
            if (this != &source)
            {
                data = source.data;
                source.data = nullptr;
                std::cout << "used move assignment" << std::endl;
            }
            return *this;
        }
        void PrintingData()
        {
            for (int i = 0; i < 10; i++)
            {
                std::cout << data[i] << std::endl;
            }
        }
        void SetData(int index, int value) { data[index] = value; }

    private:
        int *data;
};

int main(int argc, char *argv[])
{
    /*Array myArray;*/
    /*myArray.SetData(0, 100);*/
    /*myArray.PrintingData();*/

    // c++ gives a "free of cost" copy constructor and copy assignment operator. But it dows a shallow copy.
    // we will see errors at the end, and data will be exactly same for both the instances.
    /*Array myArray2 = myArray;*/
    /*myArray2.PrintingData();*/

    // Correct way is to do Deep Copy for dynamically allocated memory.. create a cropy constructor, RULE OF 3

    DArray dmyArray;
    dmyArray.SetData(0, 100);
    dmyArray.PrintingData();

    DArray dmyArray1 = dmyArray;
    dmyArray1.PrintingData();

    DArray dmyArray2;
    dmyArray2 = dmyArray;
    dmyArray2.PrintingData();

    // moving...
    // Rule of 5
    std::vector<DArray> darrays;
    for (int i = 0; i < 10; i++)
    {
        DArray temp;
        darrays.push_back(std::move(temp));
    }
    return 0;
}
