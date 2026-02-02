/*
Goal: function basics + overloads vs templates + defaults + returns + lambdas + errors + passing styles.
Key takeaways:
- Functions can be declared before they are defined.
- Overloads differ by parameter types (not return type).
- Templates are one function definition for many types.
- Returning references is only safe if the referred object outlives the call.
 - Pass-by-value copies; pass-by-ref can mutate; const-ref reads without copying.
Exercise: add a new overload or call the template with double.
Notes: see notes/functions.md for detailed explanations.
*/
#include <algorithm>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>

// forward declaration, (coz we are defining it after main)
int add(int, int);
auto add(float a, float b) -> float; // new style of defining the return type
double add(double a, double b);

// template: one definition for many types
template <typename T>
T add_t(T a, T b)
{
    return a + b;
}

// declared and defined
void print(void) { std::cout << "just basic" << std::endl; }

// default arguments (must be in declaration, not repeated in definition)
int scale(int value, int factor = 2);

// return by reference: safe only if caller passes a valid lvalue
int &identity_ref(int &x) { return x; }

// passing styles
void SetValue(int arg);
void PassbyRef(int &alias);
void PassbyConstRef(const int &alias);

// error code style (no exceptions)
bool safe_divide(double a, double b, double &out);

// exception style
double strict_divide(double a, double b);

int main(int argc, char *argv[])
{

    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.2f, (float)1.3) << std::endl; // needed to specify if it was double or float !
    std::cout << add(1.2, 1.3) << std::endl;
    std::cout << add_t<int>(3, 4) << std::endl;
    std::cout << add_t<double>(1.5, 2.5) << std::endl;

    std::cout << "scale default: " << scale(5) << std::endl;
    std::cout << "scale custom: " << scale(5, 3) << std::endl;

    int x = 10;
    int &ref = identity_ref(x);
    ref = 20;
    std::cout << "identity_ref changed x: " << x << std::endl;

    double result = 0.0;
    if (safe_divide(10.0, 2.0, result))
    {
        std::cout << "safe_divide: " << result << std::endl;
    }

    try
    {
        std::cout << "strict_divide: " << strict_divide(10.0, 0.0) << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "strict_divide error: " << e.what() << std::endl;
    }

    // lambda example: transform a vector
    std::vector<int> v = {1, 2, 3};
    std::transform(v.begin(), v.end(), v.begin(), [](int n) { return n * n; });
    std::cout << "lambda transform: ";
    for (int n : v)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    int y = 10;
    std::cout << "y is " << y << std::endl;
    std::cout << "address of y is " << &y << std::endl;
    SetValue(y);
    std::cout << "after SetValue, y is " << y << std::endl;
    PassbyRef(y);
    std::cout << "after PassbyRef, y is " << y << std::endl;
    PassbyConstRef(y);
    return 0;
}

// function declared
int add(int a, int b) { return a + b; }

float add(float a, float b) { return a + b; }

double add(double a, double b) { return a + b; }

int scale(int value, int factor) { return value * factor; }

void SetValue(int arg)
{
    std::cout << "SetValue:\targ is initially: " << arg << std::endl;
    std::cout << "SetValue:\targ address: " << &arg << std::endl;
    arg = 30;
    std::cout << "SetValue:\targ modified to: " << arg << std::endl;
}

void PassbyRef(int &alias)
{
    std::cout << "alias address is: " << &alias << std::endl;
    alias = 40;
}

void PassbyConstRef(const int &alias)
{
    std::cout << "const ref address is: " << &alias << std::endl;
    /*alias = 50; // compiler fails here! cannot change const variable.*/
}

bool safe_divide(double a, double b, double &out)
{
    if (b == 0.0)
    {
        return false;
    }
    out = a / b;
    return true;
}

double strict_divide(double a, double b)
{
    if (b == 0.0)
    {
        throw std::runtime_error("division by zero");
    }
    return a / b;
}
