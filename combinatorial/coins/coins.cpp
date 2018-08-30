#include "coins.h"

int change_helper(int amount, int denom, std::vector<std::vector<int>> &memo)
{
    // lookup precomputed values
    if (amount > 0 && memo[amount-1][denom] > 0) 
    {
        std::cout << "found memo for " << amount << " cents.\n";
        return memo[amount-1][denom];
    }
    // last denomination (1), only one way to use pennies
    if (denom >= d.size()-1) 
    {
        v.print();
        std::cout << amount << " pennies.\n";
        return 1;
    }
    int ways = 0;
    // try 0, 1, 2, ... , n pieces of the denom until it exceeds the amount
    for (int i = 0; i*d[denom] <= amount; ++i)
    {
        v.add(d[denom], i);
        ways += change_helper(amount - i*d[denom], denom+1, memo);
        v.remove(d[denom], i);
    }
    // log computed values
    if (amount > 0) memo[amount-1][denom] = ways;
    return ways;
}

int ways(int n)
{
    std::vector<std::vector<int>> memo(n, std::vector<int>(d.size(), 0));
    int res = change_helper(n, 0, memo);
    v.reset();
    return res;
}