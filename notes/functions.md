Functions (C++)

Where functions can be defined
- A function must be declared before it is used.
- You can define it above main, or declare it above and define later.

Declarations vs definitions
- Declaration: tells the compiler the signature.
  - int add(int, int);
- Definition: provides the body.
  - int add(int a, int b) { return a + b; }

Global (free) functions
- Functions defined outside any class are global (free) functions.
- Variables defined outside any function are global variables.
- Avoid global variables when possible.

Overloading
- Same function name, different parameter types.
- Return type alone does not overload.

Templates
- One definition that works for many types.
- Example:
  - template <typename T> T add_t(T a, T b) { return a + b; }

Default arguments
- Allowed in declarations.
- Example: int scale(int value, int factor = 2);

Passing styles
- Pass-by-value: copies the argument.
- Pass-by-reference: aliases the original; can modify it.
- Pass-by-const-reference: no copy, no modification.

Return by reference
- Safe only if the referenced object outlives the function call.
- Never return references to local variables.

Lambdas
- Anonymous functions.
- Syntax:
  - [capture](params) -> return_type { body }
- Capture examples:
  - [] no capture
  - [x] capture x by value
  - [&x] capture x by reference

std::transform (example use)
- Applies a function to each element of a range.
- Example: std::transform(v.begin(), v.end(), v.begin(), [](int n){ return n*n; });

Exceptions and throw
- throw raises an exception.
- try/catch handles it.
- std::runtime_error is a common exception type.

Rule of thumb
- Prefer const references for large read-only inputs.
- Prefer returning by value; modern compilers optimize well.

Common mistakes
- Calling a function before it is declared.
- Trying to overload only by return type (not allowed).
- Returning a reference to a local variable.
- Modifying data passed by const reference.
- Using global variables for convenience (hidden dependencies).

Lambda examples
Basic:
  - auto square = [](int x) { return x * x; };
  - square(3) -> 9

Capture by value:
  - int factor = 2;
  - auto scale = [factor](int x) { return x * factor; };

Capture by reference:
  - int total = 0;
  - auto add = [&total](int x) { total += x; };

Use with algorithms:
  - std::vector<int> v = {1,2,3,4};
  - std::for_each(v.begin(), v.end(), [](int n){ std::cout << n << " "; });
