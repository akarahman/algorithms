#include <iostream>
#include <unordered_set>

void parens_helper(int left, int right, std::string &s, std::unordered_set<std::string> &res);
std::unordered_set<std::string> parens(int n);
void print_result(std::unordered_set<std::string> &s);
