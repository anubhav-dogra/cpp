Pointers Notes (C++)

What a pointer is
- A pointer holds the address of another object.
- The type of the pointer tells the compiler how to interpret the bytes at that address.

Basic syntax
- int x = 7;
- int* px = &x;        // px stores the address of x
- int value = *px;     // dereference: read the value at that address
- *px = 14;            // write through pointer: modifies x

Addresses and types
- &x gives the address of x.
- The pointer type matters: int* vs double* have different sizes and alignment assumptions.
- Printing char* prints a C-string (characters until '\0') and not the address; it needs to cast to void* to print the raw address.

Pointer arithmetic (arrays)
- For arrays, the name decays to a pointer to the first element.
- px + 1 advances by sizeof(element), not by 1 byte.
- array[i] == *(array + i)
- See src/basics/arrays.cpp for a deeper pointer-arithmetic demo.

Heap allocation (manual)
- new T allocates on heap and returns T*
- delete frees a single T allocated with new
- new T[n] allocates an array; delete[] frees it
- Mismatched new/delete leads to undefined behavior

Common pointer pitfalls
- Dangling pointer: points to an object that no longer exists.
- Null dereference: accessing *nullptr causes a crash.
- Double delete: deleting the same pointer twice.
- Memory leak: forgetting to delete heap allocations.

Smart pointers (RAII)
- RAII: Resource Acquisition Is Initialization.
- Use smart pointers to manage heap objects automatically.

unique_ptr
- Exclusive ownership of a heap object.
- Not copyable; move-only.
- Example: std::unique_ptr<Foo> p = std::make_unique<Foo>();

shared_ptr
- Shared ownership with reference counting.
- Object destroyed when last shared_ptr is destroyed.
- Use make_shared for efficiency.

weak_ptr
- Non-owning observer of a shared_ptr-managed object.
- Does not increase reference count.
- Use lock() to safely access: if (auto sp = wp.lock()) { ... }

When to use what
- Prefer stack objects when possible.
- Use unique_ptr for single ownership.
- Use shared_ptr only when shared ownership is necessary.
- Use weak_ptr to break cycles (graphs, parent/child).

Mini exercises
1) Create int x, int* p = &x. Change *p and print x.
2) Allocate new int[5], write values, delete[] it.
3) Try copying unique_ptr and fix with std::move.
4) Create shared_ptr, copy it, and print use_count().
