C++ Casts (Quick Guide)

Why casts exist
- Convert between types when the compiler won't do it implicitly.
- Be explicit about potentially lossy or unsafe conversions.

static_cast
- Compile-time conversion.
- Safe for well-defined conversions.
Use for:
- numeric conversions (double -> int)
- pointer upcasts (Derived* -> Base*)
- converting void* or printing addresses
Avoid for:
- downcasting unless you are 100% sure of the dynamic type.

dynamic_cast
- Runtime-checked cast for polymorphic types (classes with virtual functions).
- Returns nullptr (for pointers) if cast fails.
Use for:
- safe downcasts (Base* -> Derived*) when you need runtime safety.

const_cast
- Add/remove const or volatile.
Use for:
- removing const only when the original object was non-const.
Danger:
- modifying a truly const object is undefined behavior.

reinterpret_cast
- Bit-level re-interpretation.
- Very low-level and often unsafe.
Use only when you must (e.g., low-level system code).

Examples
static_cast
- int i = static_cast<int>(3.14);
- Base* b = static_cast<Base*>(derivedPtr);
- std::cout << static_cast<void*>(&a);

dynamic_cast
- if (auto d = dynamic_cast<Derived*>(b)) { d->DerivedOnly(); }

const_cast
- auto p = const_cast<char*>(cstr);

reinterpret_cast
- auto raw = reinterpret_cast<std::byte*>(ptr);

Rule of thumb
- Prefer static_cast when safe.
- Use dynamic_cast for checked downcasts.
- Avoid const_cast and reinterpret_cast unless you have a strong reason.

Printing pointers vs integers
- Pointer types (e.g., void*) usually print in hex by default.
- Integer types (e.g., std::uintptr_t) print in decimal by default.
- Same address, different display format. Use std::hex / std::dec to control.

Function pointers and void*
- Standard C++ does not allow converting function pointers to void*.
- To print function addresses, cast to std::uintptr_t and print as integer.

Example: show the same address in hex and decimal
```
auto addr = reinterpret_cast<std::uintptr_t>(&foo);
std::cout << "hex: " << std::hex << addr << std::endl;
std::cout << "dec: " << std::dec << addr << std::endl;
```
