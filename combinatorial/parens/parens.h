/*
 * Problem: Compute all valid combinations of n parentheses.
 * Example: 3 -> ()()(), (())(), ()(()), (()()), ((()))
 */

#include <iostream>
#include <unordered_set>

/*
 * Requires: left, right >= 0
 *           left (right) is the number of left (right) parentheses
 * Modifies: res
 * Effects: computes all valid combinations of left/right parentheses and adds all of them to res
 * Note: s is not modified when the funciton returns, but is used by the function as a buffer
 */
void parens_helper(int left, int right, std::string &s, std::unordered_set<std::string> &res);

/*
 * Requires: n > 0
 * Effects: computes and returns all valid combinations of left/right parentheses
 */
std::unordered_set<std::string> parens(int n);

/*
 * Effects: prints all elements of s
 */
void print_result(std::unordered_set<std::string> &s);
