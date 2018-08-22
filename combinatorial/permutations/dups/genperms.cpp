#include "genperms.h"

std::vector<std::string> perm_helper(std::unordered_map<char, int> &chars)
{
    if (chars.size() < 2) 
    {
        // base case
        return std::vector<std::string>(1, std::string(chars.begin()->second, chars.begin()->first));
    }

    std::vector<std::string> perms;
    std::vector<std::string> res;
    std::unordered_map<char, int> next;

    // choose prefix
    for (auto it = chars.begin(); it != chars.end(); ++it)
    {
        // exclude prefix
        next = chars;
        if (it->second == 1) next.erase(it->first);
        else next[it->first] -= 1;

        // compute subsets excluding prefix
        perms = perm_helper(next);
        for (int i = 0; i < perms.size(); ++i)
        {
            // add prefix to results
            res.push_back(it->first + perms[i]);
        }
    }
    return res;
}

std::vector<std::string> gen_perms(const std::string &s)
{
    if (s.size() < 2) return std::vector<std::string>(1, s); // base case

    std::vector<std::string> res; // result vector
    std::unordered_map<char, int> char_counts;

    // scan string and count char occurences
    for (char c : s)
    {
        if (char_counts.find(c) != char_counts.end()) char_counts[c]++;
        else char_counts[c] = 1;
    }

    return perm_helper(char_counts);
}

void print_perms(const std::vector<std::string> &s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        std::cout << s[i] << "\n";
    }
}

void assert_result(int size, const std::string s, const std::vector<std::string> &v)
{
    std::unordered_set<std::string> set;
    for (int i = 0; i < v.size(); ++i)
    {
        assert(set.find(v[i]) == set.end());
        set.insert(v[i]);
    }

    std::unordered_map<char, int> map;
    for (char c : s)
    {
        if (map.find(c) != map.end()) map[c]++;
        else map[c] = 1;
    }

    int denom = 1;
    int fact = 1;
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        for (int i = 1; i <= it->second; ++i)
        {
            fact *= i;
        }
        denom *= fact;
        fact = 1;
    }

    for (int i = 1; i <= s.size(); ++i)
    {
        fact *= i;
    }

    int num_perms = fact / denom;
    assert(num_perms == v.size());
}