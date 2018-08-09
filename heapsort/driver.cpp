#include <fstream>
#include "heapsort.h"

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cerr << "must provide at least 1 input\n";
        exit(1);
    }

    std::ifstream infile;
    int val;
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

        heapsort(v);

        std::cout << "sorted vector [ ";
        for (int j = 0; j < v.size(); ++j)
        {
            std::cout << v[j] << " ";
        }
        std::cout << "]\n\n";

        infile.close();
        v.clear();
    }

    return 0;
}
