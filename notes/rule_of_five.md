Rule of 5 (C++)

What problem this solves
- If a class owns a resource directly, the compiler-generated copy behavior may be wrong.
- Raw pointers are the classic example: copying the pointer copies the address, not the owned memory.

Shallow copy vs deep copy
- Shallow copy:
  two objects end up pointing to the same memory.
- Deep copy:
  each object gets its own independent memory.

Why shallow copy is dangerous
- Mutating one object changes the shared resource seen by the other.
- When both objects are destroyed, both try to free the same memory.
- That causes double-free and undefined behavior.

The five special member functions
- Destructor:
  releases the owned resource.
- Copy constructor:
  builds a new object as a deep copy of another object.
- Copy assignment:
  replaces an existing object's resource with a deep copy of another object's resource.
- Move constructor:
  steals the resource from a temporary or expiring object.
- Move assignment:
  frees current ownership, then steals from another object.

Rule of 3 vs Rule of 5
- Rule of 3:
  if you need a destructor, copy constructor, or copy assignment, you usually need all three.
- Rule of 5:
  with move semantics added, you usually need all five.

When move helps
- Returning large objects by value.
- Inserting objects into `std::vector`.
- Reallocations inside containers.

Moved-from objects
- They must remain valid.
- They do not need to keep their old value.
- A common state is `nullptr` for owning pointers.

Why `noexcept` matters
- Standard containers prefer move operations when they are marked `noexcept`.
- If move might throw, a container may fall back to copy instead.

Common mistakes
- Copying an owning raw pointer without deep-copy logic.
- Returning references to objects that will be destroyed.
- Forgetting self-assignment checks in assignment operators.
- Forgetting to release the current resource in move assignment.
- Writing all this manually when `std::vector` or `std::unique_ptr` would remove the need.

Rule of thumb
- Prefer standard containers and smart pointers over owning raw pointers.
- Write the Rule of 5 manually only when you are learning it or truly need custom ownership.

Robotics-style examples
- Sensor packet buffer owned by a parser object.
- Preallocated state buffer owned by a controller class.
- History window owned by a ring-buffer implementation.
