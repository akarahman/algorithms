/*
 * Problem: Given a sorted array A of n distinct integers, 
 *          find an index i where A[i] == i (if one exists).
 */

#include <iostream>
#include <vector>
#include <math.h>

/*
 * Requires: start <= end, end is the index past the last element
 * Effects: returns the magic index
 */
int helper(std::vector<int> &v, int start, int end);

/*
 * Effects: returns the magic index
 */
int magic_index(std::vector<int> &v);
