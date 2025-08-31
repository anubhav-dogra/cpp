
#include <iostream>
class Base
{
    public:
        Base() { std::cout << "Base constructor" << std::endl; }
        virtual ~Base()
        {
            std::cout << "Base destructor" << std::endl;
        } // derived destructor is not called if not virtual here !!
        // step 1- 3
        /*void Memberfunc() { std::cout << "Base member function" << std::endl; }*/

        // step 4
        virtual void Memberfunc() { std::cout << "Base member function" << std::endl; }
};
class Derived : public Base
{
    public:
        Derived() { std::cout << "Derived constructor" << std::endl; }
        ~Derived() { std::cout << "Derived destructor" << std::endl; }
        // step 1- 3
        /*void Memberfunc() { std::cout << "Derived member functon" << std::endl; }*/

        // step 4
        void Memberfunc() override { std::cout << "Derived member functon" << std::endl; }
};
int main(int argc, char *argv[])
{
    // check which member function is called here
    Base baseInstance;
    baseInstance.Memberfunc();

    std::cout << "***********second step*************" << std::endl;
    Derived derived_instance;
    derived_instance.Memberfunc();

    // creating the explicit type
    // check which member function is called now,..
    // comment out virutal and uncomment step 1-3 method.
    std::cout << "***************third step***************" << std::endl;
    Base *instance = new Derived;
    instance->Memberfunc();
    delete instance;

    // how to call member function from derived class ?
    // problem is that we have not given permission to call the right member,
    // we need to make the function override,...
    std::cout << "***************fourth step*************" << std::endl;
    Base *instance_ = new Derived;
    instance_->Memberfunc();
    instance_->Base::Memberfunc();
    delete instance_;

    std::cout << "***************fifth step*************" << std::endl;
    Derived d;
    return 0;
}
