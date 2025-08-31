#include <iostream>
class TopLevelClass
{
    public:
        /*TopLevelClass() {}*/
        TopLevelClass(std::string arg) { std::cout << "top level class" << std::endl; }
        ~TopLevelClass() { std::cout << "top level destructed" << std::endl; };
};
class BaseClass : public TopLevelClass
{
    public:
        BaseClass()
            : TopLevelClass("arg")
        {
            std::cout << "Base constructor" << std::endl;
        }
        BaseClass(std::string name)
            : TopLevelClass("arg"),
              m_name(name)
        {
            std::cout << "baseclass(name) constructor" << std::endl;
        }
        ~BaseClass() { std::cout << "Base destructed" << std::endl; }
        void func1() { std::cout << "func1 is called" << std::endl; }
        void func2() { std::cout << "func2 is called" << std::endl; }
        float x, y;

    protected:
        int mprotected;

    private:
        int mprivate;
        std::string m_name;
};
class ChildClass : public BaseClass
{
    public:
        /*ChildClass()*/
        ChildClass()
            : BaseClass("default")
        {
            /*x = 1;*/
            /*mprotected = 2;*/
            /*mprivate = 3; // ERROR cannot access this !*/
            std::cout << "Child Constructed" << std::endl;
        }
        ~ChildClass() { std::cout << "Child destructed" << std::endl; }
        void child_func1() { std::cout << "child_func" << std::endl; }
        float z;
};

int main(int argc, char *argv[])
{
    /*BaseClass bc;*/
    /*bc.mprivate = 3; // EEROR same here !! Only can be used internally by the class*/

    /*bc.func1();*/

    /*ChildClass child1;*/
    /*child1.func1();*/
    /*child1.child_func1();*/

    /*std::cout << "baseclass size " << sizeof(bc) << std::endl;*/
    /*std::cout << "childclass size " << sizeof(child1) << std::endl; // baseclass +  childclass*/

    ChildClass cc;
    return 0;
}
