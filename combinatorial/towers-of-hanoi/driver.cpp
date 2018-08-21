#include <stdio.h>
#include <stdlib.h>
#include "solution.h"
#include "visual.h"

int main(int argc, char const *argv[])
{
    int height;

    // get input through stdio
    while (std::cin >> height)
    {
        towers t(height);
        // t.solve(true);
        // t.reset_towers();
        // t.solve(false);
        solve(height);
    }

    return 0;
}
