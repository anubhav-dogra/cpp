Stack vs Heap (C++)

Quick idea
- Stack: automatic memory for local variables and function calls.
- Heap: dynamic memory you request explicitly.

Stack
- Lifetime: automatic (created when scope starts, destroyed when scope ends).
- Allocation: very fast.
- Size: limited (depends on OS; typically a few MB).
- Typical use: local variables, small fixed-size objects, return addresses, function frames.

Heap
- Lifetime: manual or managed (new/delete or smart pointers).
- Allocation: slower than stack.
- Size: large (uses system memory).
- Typical use: objects that must outlive a scope, large buffers, shared ownership.

Benefits
Stack benefits
- Fast allocation/deallocation.
- Automatic cleanup (no leaks if you stay on stack).
- Simple and predictable lifetime.

Heap benefits
- Can allocate large objects not suitable for stack.
- Can control lifetime beyond a function scope.
- Useful for shared ownership or polymorphic objects.

Costs / risks
- Stack overflow if you allocate too much on stack (huge arrays or deep recursion).
- Heap leaks if you forget to delete (use RAII / smart pointers).
- Dangling pointers if you delete and still use the pointer.

Examples
Stack example
- int x = 10;  // freed automatically at end of scope

Heap example (manual)
- int* p = new int(10);
- delete p;

Heap example (safe)
- auto p = std::make_unique<int>(10); // deleted automatically

Rule of thumb
- Prefer stack allocation by default.
- Use heap only when you need dynamic lifetime or large dynamic size.

Mini exercises
1) Create an array of 1,000,000 ints on stack vs heap and observe behavior.
2) Write a function that returns a std::unique_ptr to an object.
3) Add a deep recursion and see when stack overflows.
