#include "parens.h"

void parens_helper(int left, int right, std::string &s, std::unordered_set<std::string> &res)
{
    if (left == 0 && right == 0) 
    {
        // base case, no more pairs
        res.insert(s);
    }
    else
    {
        if (left > 0)
        {
            // if enough left paren, add to buffer
            s += '(';
            parens_helper(left-1, right, s, res);
            // remove when done to move on to next combination
            s.pop_back();
        }
        if (right > 0 && left < right)
        {
            // if there is a left paren to be paired
            s += ')';
            parens_helper(left, right-1, s, res);
            // remove when done to move on to next combination
            s.pop_back();
        }
    }
}

std::unordered_set<std::string> parens(int n)
{
    std::unordered_set<std::string> res;
    std::string s;
    parens_helper(n, n, s, res);
    return res;
}

void print_result(std::unordered_set<std::string> &s)
{
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        std::cout << *it << "\n";
    }
}