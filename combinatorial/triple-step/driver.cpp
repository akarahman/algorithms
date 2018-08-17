#include "solution.h"

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cerr << "must provide at least one test input\n";
        exit(1);
    }

    std::fstream infile;
    int n, out;
    int ans = 0;
    for (int i = 1; i < argc; ++i)
    {
        infile.open(argv[i]);
        infile >> n;
        infile >> ans;
        infile.close();

        out = recursive_solve(n);
        if (ans) assert(out == ans);
        std::cout << "solving recursively...\nnumber of ways to climb " << n 
                  << " steps: " << out << "\n";
                  
        out = dp_solve_td(n);
        if (ans) assert(out == ans);
        std::cout << "solving using top-down dp...\nnumber of ways to climb " << n 
                  << " steps: " << out << "\n";
    }

    return 0;
}
