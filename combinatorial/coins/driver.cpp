#include "coins.h"

int main(int argc, char const *argv[])
{
    int n, res;

    // get input through stdio
    while (std::cin >> n)
    {
        res = ways(n);
        std::cout << "num ways to make change for " << n << " cents: " << res << "\n\n";
    }

    return 0;
}
