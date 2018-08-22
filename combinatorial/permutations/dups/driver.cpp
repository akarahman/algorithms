#include <stdio.h>
#include <stdlib.h>
#include "genperms.h"

int main(int argc, char const *argv[])
{
    std::string s;

    // get input through stdio
    while (std::cin >> s)
    {
        std::vector<std::string> perms = gen_perms(s);
        print_perms(perms);
        std::cout << "num perms: " << perms.size() << "\n";
        // assert_result(s.size(), s, perms);
    }

    return 0;
}
