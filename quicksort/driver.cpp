#include <fstream>
#include <cassert>
#include "quicksort.h"

void assert_order(std::vector<int> &v);

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cerr << "must provide at least 1 input\n";
        exit(1);
    }

    std::ifstream infile;
    int val;
    std::vector<int> v1;
    for (int i = 1; i < argc; ++i)
    {
        infile.open(argv[i]);
        while (infile >> val)
        {
            v1.push_back(val);
        }

        std::cout << "unsorted vector ";
        print_vect(std::cout, v1, 0, v1.size());
        std::cout << "\n";

        quicksort(v1);

        std::cout << "sorted vector ";
        print_vect(std::cout, v1, 0, v1.size());
        std::cout << "\n\n";
        assert_order(v1);
        
        infile.close();
        v1.clear();
    }

    return 0;
}

void assert_order(std::vector<int> &v)
{
    if (v.empty()) return;
    int last = v[0];
    for (int k = 1; k < v.size(); ++k)
    {
        assert(v[k] >= last);
        last = v[k];
    }
}
