#include <iostream>
#include <fstream>
#include <unordered_map>
#include <functional>
#include <string>

struct pair_hash
{
    size_t operator() (const std::pair<std::string, bool> &p) const noexcept
    {
        std::string to_hash;
        if (p.second) to_hash = p.first + 'a';
        else to_hash = p.first + 'b';
        size_t hash = std::hash<std::string>{}(to_hash);
        return hash;
    }
};

int num_paren_helper(std::string expr, bool res, std::unordered_map<std::pair<std::string, bool>, int, pair_hash> &memo);
int num_paren(const std::string &expr, bool res);

