/*
 * Problem: Compute all permutations of s, where all characters in s are distinct.
 */

#include <iostream>
#include <vector>

/*
 * Effects: computes and returns all permutations of s
 */
std::vector<std::string> gen_perms(const std::string &s);

/*
 * Effects: prints all strings (permutations) in s 
 */
void print_perms(const std::vector<std::string> &s);

