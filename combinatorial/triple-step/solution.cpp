#include "solution.h"

int recursive_solve (int n)
{
    // base cases
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    return recursive_solve (n-1) + recursive_solve (n-2) + recursive_solve (n-3);
}

int dp_solve_td (int n)
{
    int memo[n]; // don't need memo[0]
    memo[0] = 1;
    memo[1] = 2;
    memo[2] = 4;
    for (int i = 3; i < n; ++i) memo[i] = 0;
    return dp_td_helper(n, memo);
}

int dp_td_helper (int n, int* a)
{
    if (a[n-1] == 0)
    {
        // calculate if lookup fails
        a[n-1] = dp_td_helper(n-1, a) + dp_td_helper(n-2, a) + dp_td_helper(n-3, a);
    }
    return a[n-1];
}
