#include "solution.h"

int helper(std::vector<int> &v, int start, int end)
{
    if (start == end) return -1;                    // empty, not found
    int mid = (end-start == 1) ? start : ceil((double)(end-start)/2) + start; // midpoint index
    if (v[mid] == mid) return mid;                  // found magic index
    if (v[mid] > mid) return helper(v, start, mid); // search left subarr
    else return helper(v, mid+1, end);              // search right subarr
}

int magic_index(std::vector<int> &v)
{
    return helper(v, 0, v.size());
}