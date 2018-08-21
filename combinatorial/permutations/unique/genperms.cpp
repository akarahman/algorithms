#include "genperms.h"

std::vector<std::string> gen_perms(const std::string &s)
{
    if (s.size() < 2) return std::vector<std::string>(1, s); // base case

    std::vector<std::string> res; // result vector
    // permutations of s minus the first char
    std::vector<std::string> perms = gen_perms(s.substr(1, s.size()-1)); 
    std::string substr;

    while (!perms.empty())
    {
        substr = perms.back();
        // for each permutation, insert s[0] at every position possible and add each to result vector
        for (int i = 0; i <= substr.size(); ++i)
        {
            res.push_back(substr.substr(0, i) + s[0] + substr.substr(i, substr.size()));
        }
        perms.pop_back();
    }
    return res;
}

void print_perms(const std::vector<std::string> &s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        std::cout << s[i] << "\n";
    }
}