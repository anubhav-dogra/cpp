// data type that stores an address
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>

class MyClass
{
    public:
        MyClass() { std::cout << "constructed" << std::endl; };
        ~MyClass() { std::cout << "destoyed" << std::endl; };
};

int main(int argc, char *argv[])
{
    int x = 7;
    int *px = &x; // stores the address

    std::cout << "x stores      : " << x << std::endl;
    std::cout << "x address     : " << &x << std::endl;
    std::cout << "px stores     : " << px << std::endl;
    // derefrencing: retrieve the value of the type we point to
    std::cout << "px derefrenced: " << *px << std::endl; // output is value
    *px = 14;
    std::cout << "x stores      : " << x << std::endl; // updates the value of x

    // heap memory
    int *array = new int[1000];
    // we must delete it after allocating heap memory
    delete[] array;

    // pitfalls of pointers
    /*int *py = nullptr;*/
    // pitfall is if we derefrence it to some value
    /**py = 42; // segmentation fault will occur !!*/

    std::cout << "****************SMART POINTERS******************" << std::endl;
    // Ownership...

    // normal way
    /*MyClass myclass;*/

    // unique_ptr way
    std::cout << "****************SMART unique POINTERS******************" << std::endl;
    /*std::unique_ptr<MyClass> myclass1 = std::unique_ptr<MyClass>(new MyClass);*/
    std::unique_ptr<MyClass> myclass1 = std::make_unique<MyClass>();
    // I dont have to call delete to clear heap memory here. !
    // I cannot cppy as well but can move..
    std::unique_ptr<MyClass> myclass2 = std::move(myclass1);
    // array
    /*std::unique_ptr<MyClass[]> myclass_array = std::unique_ptr<MyClass[]>(new MyClass[10]);*/
    /*std::unique_ptr<MyClass[]> myclass_array = std::make_unique<MyClass[]>(10);*/

    std::cout << "****************SMART shared POINTERS******************" << std::endl;
    std::shared_ptr<MyClass> myclass3 = std::make_shared<MyClass>();
    std::shared_ptr<MyClass> myclass4 = myclass3;

    // Weak ptr
    std::cout << "****************SMART weak POINTERS******************" << std::endl;
    // its a non owning pointer, and it does not increase reference count
    return 0;
}
