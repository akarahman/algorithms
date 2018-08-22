/*
 * Problem: Compute all unique permutations of s.
 * Input: s is a string of characters that may or may not be distinct.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

/*
 * Effects: computes and returns all permutations of s
 */
std::vector<std::string> perm_helper(std::unordered_map<char, int> &chars);

/*
 * Effects: computes and returns all permutations of s
 */
std::vector<std::string> gen_perms(const std::string &s);

/*
 * Effects: prints all strings (permutations) in s 
 */
void print_perms(const std::vector<std::string> &s);

/*
 * For checking the correctness of results
 */
void assert_result(int size, const std::string s, const std::vector<std::string> &v);
