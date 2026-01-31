RAII (Resource Acquisition Is Initialization)

What it means
- Tie resource lifetime to object lifetime.
- When an object is constructed, it acquires a resource.
- When it is destroyed, it releases that resource automatically.

Why it matters
- Prevents leaks and double-frees.
- Makes cleanup automatic, even on exceptions.
- Simplifies ownership rules.

Common resources
- Heap memory (new/delete)
- File handles (open/close)
- Mutex locks (lock/unlock)
- Network sockets (connect/close)

Example (manual, error-prone)
FILE* f = fopen("data.txt", "r");
if (!f) { return; }
// if we return early or throw, fclose may never run
fclose(f);

Example (RAII)
{
    std::ifstream file("data.txt"); // opens in constructor
    // when file goes out of scope, it closes automatically
}

Smart pointers are RAII
- std::unique_ptr frees memory when it goes out of scope.
- std::shared_ptr frees when the last owner goes away.

Rule of thumb
- Prefer RAII wrappers instead of raw new/delete.
- If you must manage a resource manually, wrap it in a class.

