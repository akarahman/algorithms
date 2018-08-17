/*
 * Problem: A child is running up a staircase with n steps and can hop either 1 step, 
 *          2 steps or 3 steps at a time. Count how many possible ways the child can 
 *          run up the stairs.
 */

#include <iostream>
#include <fstream>
#include <cassert>

/*
 * Requires: n > 0
 * Effects: returns number of ways to climb steps
 */
int recursive_solve (int n);

/*
 * Requires: n > 0
 * Effects: returns number of ways to climb steps
 */
int dp_solve_td (int n);

/*
 * Requires: size of a == n, n > 0
 * Effects: returns number of ways to climb steps
 */
int dp_td_helper (int n, int* a);