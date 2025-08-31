#include <iostream>
#include <ostream>

/*void SetValue(int *arg)*/
/*{*/
/*    std::cout << "SetValue:\targ is initially: " << arg << std::endl;*/
/*    *arg = 20;*/
/*    std::cout << "SetValue:\targ modified to: " << arg << std::endl;*/
/*}*/
/**/
void SetValue(int arg)
{

    std::cout << "SetValue:\targ is initially: " << arg << std::endl;
    arg = 30;
    std::cout << "SetValue:\targ modified to: " << arg << std::endl;
}

void PassbyRef(int &alias)
{
    std::cout << "alias address is: " << &alias << std::endl;
    alias = 40;
}

int main(int argc, char *argv[])
{
    int x = 10;
    int &ref = x; // ref is just an alias of x
    std::cout << "x is " << x << std::endl;
    std::cout << "address of x is " << &x << std::endl;

    std::cout << "ref is " << ref << std::endl;
    std::cout << "address of ref is " << &ref << std::endl;

    SetValue(x); // this will cause no change !

    /*SetValue(&x); // if I just x, value of x will not be changed*/

    std::cout << "SV x is " << x << std::endl;
    std::cout << "SV address of x is " << &x << std::endl;

    PassbyRef(x);

    std::cout << "PBR x is " << x << std::endl;
    std::cout << "PBR address of x is " << &x << std::endl;
    return 0;
}
