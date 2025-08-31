#include <cstddef>
#include <iostream>
class Collection
{
    public:
        Collection() { data = new int[10]; }
        ~Collection() { delete[] data; }
        // operator overloading
        int &operator[](std::size_t idx) { return data[idx]; }
        const int &operator[](std::size_t idx) const { return data[idx]; }

    private:
        int *data;
};
int main(int argc, char *argv[])
{
    Collection mycollection;
    mycollection[0] = 7;
    mycollection[1] = 7;
    mycollection[2] = 7;
    mycollection[3] = 7;
    mycollection[4] = 7;
    std::cout << mycollection[0] << std::endl;
    return 0;
}
