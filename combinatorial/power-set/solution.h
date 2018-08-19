/*
 * Problem: Given a set S, find the set of all distinct subsets of S.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

/*
 * custom hash for unordered set.
 * using unordered set to avoid duplicae subsets.
 */
struct set_vector_hash
{
    size_t operator() (const std::vector<int> &v) const
    {
        size_t ret = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            ret += pow(v[i], 2);
        }
        return ret;
    }
};

/*
 * Effects: prints all sets in power set
 */
void print_set (std::unordered_set<std::vector<int>, set_vector_hash > &powset);

/*
 * Effects: returns an unordered set of vectors.
 *          Each vector is a subset of s and is in the power set.
 */
std::unordered_set<std::vector<int>, set_vector_hash > power_set (std::vector<int> &s);
