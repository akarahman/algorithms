#include "solution.h"

void print_set (std::unordered_set<std::vector<int>, set_vector_hash> &powset)
{
    std::cout << "{ ";
    for (auto it = powset.begin(); it != powset.end(); ++it)
    {
        std::cout << "{ ";
        for (int j = 0; j < it->size(); ++j)
        {
            std::cout << (*it)[j] << " ";
        }
        std::cout << "} ";
    }
    std::cout << "}";
}

std::unordered_set<std::vector<int>, set_vector_hash> power_set (std::vector<int> &s)
{
    std::unordered_set<std::vector<int>, set_vector_hash> ret;  // result
    std::unordered_set<std::vector<int>, set_vector_hash> copy; // for reference while modifying ret
    
    if (s.empty())
    {
        // return empty set
        ret.insert(std::vector<int>());
        return ret;
    }

    std::vector<int> vals; // to store items in a subset
    int key = s.back();    // key currently being considered
    s.pop_back();          // exclude key
    ret = power_set(s);    // find subsets without key
    copy = ret;

    // for each subset that does not contain key,
    // make a new copy of subset and insert subset u { key } to ret
    for (auto it = copy.begin(); it != copy.end(); ++it)
    {
        vals = *it;
        vals.push_back(key);
        ret.insert(vals);
    }
    return ret;
}