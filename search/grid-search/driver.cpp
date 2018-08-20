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
    int x, y, n, m;
    std::unordered_set<coord, coord_hash> in;
    std::vector<coord> out;

    // loop through all input files
    for (int i = 1; i < argc; ++i)
    {
        // read values
        infile.open(argv[i]);
        infile >> n >> m;
        while (infile >> x >> y) in.insert(coord(x, y));

        out = find_path(in, n, m);
        std::cout << argv[i] << " path: ";
        if (out.empty())
        {
            std::cout << "no path found.\n\n";
        }
        else
        {
            std::cout << "\n";
            print_path(out, in, n, m);
        }

        in.clear();
        infile.close();
    }

    return 0;
}
