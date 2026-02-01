sizeof (C++)

What sizeof does
- Returns the size in bytes of a type or object.
- Works at compile time for most types.

Common real-world uses
1) Raw buffer allocation
- auto buf = std::make_unique<std::byte[]>(N * sizeof(MyStruct));

2) C / system APIs
- memset(ptr, 0, sizeof(MyStruct));
- send(fd, &packet, sizeof(packet), 0);

3) Compile-time checks
- static_assert(sizeof(uint32_t) == 4, "unexpected size");

4) Array length in the same scope
- size_t n = sizeof(arr) / sizeof(arr[0]);

5) Layout / alignment
- std::cout << sizeof(MyStruct) << std::endl;

Robotics-flavored examples
- Hardware packets: pack structs into bytes for CAN/UART protocols.
- Shared memory / IPC: size matters for memory mapping.
- Performance: struct size affects cache behavior in control loops.

Important caveats
- sizeof(pointer) is size of the address, not the data it points to.
- sizeof(vector) is the control block, not the element count.
- sizeof(message) is NOT the serialized ROS2 message size.

Rule of thumb
- Use sizeof for raw memory, fixed layouts, and compile-time checks.
- Use container APIs for sizes (size(), capacity()).
