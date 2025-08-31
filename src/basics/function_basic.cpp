#include <iostream>
#include <ostream>

// forward declaration, (coz we are defining it after main)
int add(int, int);
/*float add(float a, float b);*/
auto add(float a, float b) -> float; // new style of defining the return type

// declared and defined
void print(void) { std::cout << "just basic" << std::endl; }

int main(int argc, char *argv[])
{

    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.2f, (float)1.3) << std::endl; // needed to specify if it was double or float !
    return 0;
}

// function declared
int add(int a, int b) { return a + b; }

float add(float a, float b) { return a + b; }
