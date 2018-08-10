#include <fstream>
#include <cassert>
#include "selection_sort.h"

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cerr << "must provide at lease one input\n";
        exit(1);
    }

    std::fstream infile;
    int val, last;
    std::vector<int> v;
    for (int i = 1; i < argc; ++i)
    {
        infile.open(argv[i]);
        while (infile >> val)
        {
            v.push_back(val);
        }

        std::cout << "unsorted vector [ ";
        for (int j = 0; j < v.size(); ++j)
        {
            std::cout << v[j] << " ";
        }
        std::cout << "]\n";

        selection_sort(v);

        std::cout << "sorted vector [ ";
        for (int j = 0; j < v.size(); ++j)
        {
            std::cout << v[j] << " ";
        }
        std::cout << "]\n\n";

        last = v[0];
        for (int k = 1; k < v.size(); ++k)
        {
            assert(v[k] >= last);
            last = v[k];
        }

        infile.close();
        v.clear();
    }

    return 0;
}
