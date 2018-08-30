/*
 * Problem: Count the number of ways to make change for n cents with quarters, dimes,
 *          nickels and pennies.
 */

#include <iostream>
#include <vector>

struct verbose
{
    int num_quarts;
    int num_dimes;
    int num_nickels;
    verbose() : num_quarts(0), num_dimes(0), num_nickels(0) {}
    void reset() { num_quarts = 0, num_dimes = 0, num_nickels = 0; }
    void print()
    {
        std::cout << num_quarts << " quarters, " 
                  << num_dimes << " dimes, " 
                  << num_nickels << " nickels, ";
    }
    void add(int denom, int count)
    {
        if (denom == 25) num_quarts += count;
        else if (denom == 10) num_dimes += count;
        else if (denom == 5) num_nickels += count;
    }
    void remove(int denom, int count)
    {
        if (denom == 25) num_quarts -= count;
        else if (denom == 10) num_dimes -= count;
        else if (denom == 5) num_nickels -= count;
    }
};

static const std::vector<int> d = {25, 10, 5, 1};
static verbose v;

int change_helper(int amount, int denom, std::vector<std::vector<int>> &memo);
int ways(int n);
