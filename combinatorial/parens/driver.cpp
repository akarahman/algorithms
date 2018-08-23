#include <stdio.h>
#include <stdlib.h>
#include "parens.h"

int main(int argc, char const *argv[])
{
    int n;

    // get input through stdio
    while (std::cin >> n)
    {
        std::unordered_set<std::string> parens_res = parens(n);
        print_result(parens_res);
        std::cout << "num configurations: " << parens_res.size() << "\n";
    }

    return 0;
}
