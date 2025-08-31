#include <algorithm>
#include <iterator>
#include <vector>

void PassbyRef(std::vector<int> &alias) { alias[0] = 40; }

int main(int argc, char *argv[])
{
    std::vector<int> x(1000000000);
    std::fill(std::begin(x), std::end(x), 1);
    PassbyRef(x);
    return 0;

    // run using time ./object_name to check how much time it takes
}
