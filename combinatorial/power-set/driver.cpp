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
    int val;
    std::vector<int> s;
    std::unordered_set<std::vector<int>, set_vector_hash> out;

    // loop through all input files
    for (int i = 1; i < argc; ++i)
    {
        // read values
        infile.open(argv[i]);
        while (infile >> val) s.push_back(val);

        out = power_set(s);
        std::cout << argv[i] << " power set, " << out.size() << " total subsets: ";
        print_set(out);
        std::cout << "\n";

        s.clear();
        infile.close();
    }

    return 0;
}
