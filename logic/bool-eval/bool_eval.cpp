#include "bool_eval.h"

int num_paren_helper(std::string expr, bool res, std::unordered_map<std::pair<std::string, bool>, int, pair_hash> &memo)
{
    if (expr.size() == 0) return 0;
    if (expr.size() == 1) 
    {
        bool val;
        if (expr[0] == '0') val = false;
        else if (expr[0] == '1') val = true;
        else throw std::exception();
        return (val == res) ? 1 : 0;
    }
    std::pair<std::string, bool> p = std::make_pair(expr, res);
    if (memo.find(p) != memo.end()) return memo[p];

    int count = 0;
    for (int i = 1; i < expr.size(); i += 2)
    {
        int right_true = num_paren_helper(expr.substr(0, i), true, memo);
        int right_false = num_paren_helper(expr.substr(0, i), false, memo);
        int left_true = num_paren_helper(expr.substr(i+1), true, memo);
        int left_false = num_paren_helper(expr.substr(i+1), false, memo);

        int total_parens = (right_true + right_false) * (left_true + left_false);
        int total_true = 0;

        if (expr[i] == '&')
        {
            total_true += right_true * left_true;
        }
        if (expr[i] == '|')
        {
            total_true += right_true * left_true + 
                          right_true * left_false + 
                          right_false * left_true;
        }
        if (expr[i] == '^')
        {
            total_true += right_true * left_false + right_false * left_true;
        } 

        count += res ? total_true : total_parens - total_true;
    }

    memo[p] = count;
    return count;
}

int num_paren(const std::string &expr, bool res)
{
    std::unordered_map<std::pair<std::string, bool>, int, pair_hash> memo;
    return num_paren_helper(expr, res, memo);
}


// int num_paren(std::string expr, bool res)
// {
//     if (expr.size() == 0) return 0;
//     if (expr.size() == 1) 
//     {
//         bool val;
//         if (expr[0] == '0') val = false;
//         else if (expr[0] == '1') val = true;
//         else throw std::exception();
//         return (val == res) ? 1 : 0;
//     }

//     int count = 0;
//     for (int i = 1; i < expr.size(); i += 2)
//     {
//         if (res)
//         {
//             if (expr[i] == '&')
//             {
//                 count += num_paren(expr.substr(0, i), true) *
//                          num_paren(expr.substr(i+1), true);
//             }
//             if (expr[i] == '|')
//             {
//                 count += num_paren(expr.substr(0, i), true) *
//                          num_paren(expr.substr(i+1), true);
//                 count += num_paren(expr.substr(0, i), false) *
//                          num_paren(expr.substr(i+1), true);
//                 count += num_paren(expr.substr(0, i), true) *
//                          num_paren(expr.substr(i+1), false);
//             }
//             if (expr[i] == '^')
//             {
//                 count += num_paren(expr.substr(0, i), true) *
//                          num_paren(expr.substr(i+1), false);
//                 count += num_paren(expr.substr(0, i), false) *
//                          num_paren(expr.substr(i+1), true);
//             } 
//         }
//         else
//         {
//             if (expr[i] == '&')
//             {
//                 count += num_paren(expr.substr(0, i), true) *
//                          num_paren(expr.substr(i+1), false);
//                 count += num_paren(expr.substr(0, i), false) *
//                          num_paren(expr.substr(i+1), true);
//                 count += num_paren(expr.substr(0, i), false) *
//                          num_paren(expr.substr(i+1), false);
//             }
//             if (expr[i] == '|')
//             {
//                 count += num_paren(expr.substr(0, i), false) *
//                          num_paren(expr.substr(i+1), false);
//             }
//             if (expr[i] == '^')
//             {
//                 count += num_paren(expr.substr(0, i), true) *
//                          num_paren(expr.substr(i+1), true);
//                 count += num_paren(expr.substr(0, i), false) *
//                          num_paren(expr.substr(i+1), false);
//             }
//         }
//     }
//     return count;
// }
