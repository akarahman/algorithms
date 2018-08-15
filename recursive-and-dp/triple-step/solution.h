/*
 * Problem: A child is running up a staircase with n steps and can hop either 1 step, 
 *          2 steps or 3 steps at a time. Count how many possible ways the child can 
 *          run up the stairs.
 */

#include <iostream>
#include <fstream>
#include <cassert>

int recursive_solve (int);
int dp_solve_td (int);
int dp_td_helper (int, int*);