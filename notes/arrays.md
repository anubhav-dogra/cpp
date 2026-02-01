Arrays (C++)

What an array is
- Fixed-size sequence of elements stored contiguously in memory.
- Size is part of the type: int[5] is different from int[3].

Indexing and pointer arithmetic
- array[i] == *(array + i), // reference for using in a loop!
- array decays to a pointer to the first element in most expressions.
- Pointer arithmetic is scaled by element size.

Size and decay
- sizeof(array) gives total bytes of the array in the same scope.
- When passed to a function, an array decays to a pointer (size info is lost).
- sizeof(pointer) only gives the pointer size (usually 8 bytes on 64-bit).

Function parameters: pointer vs array vs reference
- void f(const int* arr) and void f(const int arr[]) are the same (array decays).
- To keep size, pass it explicitly or use a reference to the whole array:
  - void g(const int (&arr)[5]) keeps size (only works for size 5).

std::array in functions
- std::array keeps size in its type.
- Use a template to accept any size:
  - template <std::size_t N> void h(const std::array<int, N>& arr)

Bounds
- C++ does not check bounds for raw arrays.
- Accessing out of bounds is undefined behavior.

Multidimensional arrays
- int a[2][3] is contiguous.
- When passing to functions, you must specify all but the first dimension.

Safer alternatives
- std::array<T, N>: fixed-size, keeps size info, stack-allocated.
- std::vector<T>: dynamic-size, heap-allocated, tracks size.

Rule of thumb
- Prefer std::array or std::vector.
- Use raw arrays mostly for interop or very low-level code.

Common mistakes
- Using sizeof(arr) inside a function that receives a pointer.
- Going out of bounds (no runtime checks for raw arrays).
- Assuming array length can be changed (raw arrays are fixed-size).
