Const Correctness (C++)

What const means
- const prevents modification through that name/reference.
- It does not make the object globally immutable; only through that access path.
- Think of it as a contract: "this code path will not mutate through this handle."

Pass-by-const-reference
- Use for large objects you only need to read.
- Avoids copying and prevents accidental mutation.
- Common for vectors, strings, maps, and user-defined classes.

Pointers and const (read right-to-left rule)
- const int* p     : pointer to const int (can't change *p)
- int* const p     : const pointer to int (can't change p)
- const int* const p : const pointer to const int

Examples
- const int* p = &x; // *p is read-only
- int* const p = &x; // p cannot point somewhere else
- const int* const p = &x; // neither p nor *p can change through this name

How to read declarations
- Start at the variable name, then move right when possible, then left.
- `const int* p`
  `p` is a pointer to const int.
- `int* const p`
  `p` is a const pointer to int.
- `const int* const p`
  `p` is a const pointer to const int.

Object constness
- `const int x = 40;`
  `x` itself cannot be reassigned.
- `const std::vector<int> v = {1, 2, 3};`
  You cannot call mutating operations like `push_back` on `v`.
- `auto` drops top-level const in copies:
  - `const int x = 5;`
  - `auto y = x;` means `y` is plain `int`
  - `const auto z = x;` keeps `z` const

Const with functions
- Prefer const on parameters and member functions.
- Returning const by value is usually unnecessary.
- For member functions: add const to promise no mutation of the object.
  - int size() const;
- A const member function can be called on const objects.

Common mistakes
- Forgetting const on read-only references.
- Returning references to locals.
- Confusing const pointer vs pointer to const.
- Assuming `const` means the object can never change anywhere.
- Returning `const` by value and expecting extra safety.

Rule of thumb
- Default to const for anything you don’t intend to modify.

Robotics-style examples
- Sensor input buffer:
  - `void process_scan(const std::vector<float>& ranges);`
  - You read the scan without copying or mutating it.
- Filter state pointer:
  - `double* const state`
  - The pointer must keep pointing to the same state buffer during the function.
- Calibration table:
  - `const double* const table`
  - The function should not modify the table or retarget the pointer.

Why this matters
- Const makes APIs easier to trust.
- The compiler catches accidental mutation.
- In robotics code, this helps separate sensor inputs, configuration, and mutable state.
