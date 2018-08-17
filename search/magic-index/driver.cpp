#include <fstream>
#include <cassert>
#include "solution.h"

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cerr << "must provide at least one test input\n";
        exit(1);
    }

    std::fstream infile;
    int out, size, val;
    int ans;
    std::vector<int> v;

    // loop through all input files
    for (int i = 1; i < argc; ++i)
    {
        // read input size, vals, and oracle (if provided)
        infile.open(argv[i]);
        infile >> size;
        for (int i = 0; i < size; ++i)
        {
            infile >> val;
            v.push_back(val);
        }

        out = magic_index(v);
        infile >> ans;
        if (!infile.fail()) assert(out == ans); // check answer
        std::cout << argv[i] << " magic index: " << out << "\n";
        v.clear();
        infile.close();
    }

    return 0;
}
