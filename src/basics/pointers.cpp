/*
Goal: show raw pointers, pointer arithmetic, and smart pointers.
Key takeaways:
- A pointer stores an address; dereference reads/writes the pointed value.
- new[]/delete[] must match; prefer smart pointers.
*/
// data type that stores an address
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>

class MyClass
{
    public:
        MyClass() { std::cout << "constructed" << std::endl; };
        ~MyClass() { std::cout << "destroyed" << std::endl; };
};

int main(int argc, char *argv[])
{
    // --- raw pointer basics ---
    int x = 7;
    int *px = &x; // stores the address

    std::cout << "x stores      : " << x << std::endl;
    std::cout << "x address     : " << &x << std::endl;
    std::cout << "px stores     : " << px << std::endl;
    // dereferencing: retrieve the value of the type we point to
    std::cout << "px derefrenced: " << *px << std::endl; // output is value
    *px = 14;
    std::cout << "x stores      : " << x << std::endl; // updates the value of x

    // --- pointer arithmetic (with arrays) ---
    int nums[3] = {10, 20, 30};
    int *pnums = nums; // same as &nums[0]
    std::cout << "pnums[0]: " << *pnums << std::endl;
    std::cout << "pnums[1]: " << *(pnums + 1) << std::endl;
    std::cout << "pnums[2]: " << *(pnums + 2) << std::endl;

    // --- heap memory with manual lifetime ---
    // See notes/memory_stack_heap.md for stack vs heap notes.
    int *array = new int[1000];
    // we must delete it after allocating heap memory
    delete[] array;

    // pitfalls of pointers
    // int *py = nullptr;
    // pitfall is if we derefrence it to some value
    //*py = 42; // segmentation fault will occur !!

    std::cout << "****************SMART POINTERS******************" << std::endl;
    // Ownership...

    // normal way
    MyClass myclass;

    // --- unique_ptr: single owner, move-only ---
    // See notes/raii.md for why RAII matters.
    std::cout << "****************SMART unique POINTERS******************" << std::endl;
    /*std::unique_ptr<MyClass> myclass1 = std::unique_ptr<MyClass>(new MyClass);*/
    std::unique_ptr<MyClass> myclass1 = std::make_unique<MyClass>();
    // Uncomment to see compile error: copy is deleted for unique_ptr
    /*std::unique_ptr<MyClass> myclass_copy = myclass1;*/
    // I dont have to call delete to clear heap memory here. !
    // I cannot copy as well but can move..
    std::unique_ptr<MyClass> myclass2 = std::move(myclass1);
    std::cout << "myclass1 is null? " << (myclass1 == nullptr) << std::endl;
    // array
    /*std::unique_ptr<MyClass[]> myclass_array = std::unique_ptr<MyClass[]>(new MyClass[10]);*/
    /*std::unique_ptr<MyClass[]> myclass_array = std::make_unique<MyClass[]>(10);*/

    // --- shared_ptr: shared ownership via reference count ---
    std::cout << "****************SMART shared POINTERS******************" << std::endl;
    std::shared_ptr<MyClass> myclass3 = std::make_shared<MyClass>();
    std::shared_ptr<MyClass> myclass4 = myclass3;
    std::cout << "shared use_count: " << myclass3.use_count() << std::endl;

    // --- weak_ptr: non-owning observer ---
    std::cout << "****************SMART weak POINTERS******************" << std::endl;
    // its a non owning pointer, and it does not increase reference count

    // --- RAII demo: automatic cleanup when leaving scope ---
    {
        auto raii_owner = std::make_unique<MyClass>();
        std::cout << "inside RAII scope" << std::endl;
    } // destructor runs here automatically

    return 0;
}
