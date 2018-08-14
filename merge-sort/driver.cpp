#include <fstream>
#include <cassert>
#include "mergesort.h"

void print_vect(std::vector<int> &v);
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
    std::vector<int> v2;
    for (int i = 1; i < argc; ++i)
    {
        infile.open(argv[i]);
        while (infile >> val)
        {
            v1.push_back(val);
            v2.push_back(val);
        }

        std::cout << "unsorted vector ";
        print_vect(v1);
        std::cout << "\n";

        std::cout << "sorting recursively...\n";
        mergesort(v1);

        std::cout << "sorted vector ";
        print_vect(v1);
        std::cout << "\n\n";
        assert_order(v1);
        
        std::cout << "sorting bottom-up...\n";
        bottom_up_mergesort(v2);

        std::cout << "sorted vector ";
        print_vect(v2);
        std::cout << "\n\n";
        assert_order(v2);

        infile.close();
        v1.clear();
        v2.clear();
    }

    return 0;
}

void print_vect(std::vector<int> &v)
{
    std::cout << "[ ";
    for (int j = 0; j < v.size(); ++j)
    {
        std::cout << v[j] << " ";
    }
    std::cout << "]";
}

void assert_order(std::vector<int> &v)
{
    int last = v[0];
    for (int k = 1; k < v.size(); ++k)
    {
        assert(v[k] >= last);
        last = v[k];
    }
}
