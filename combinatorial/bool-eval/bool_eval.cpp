#include "bool_eval.h"

int num_paren(std::string expr, bool res)
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

    int count = 0;
    for (int i = 1; i < expr.size(); i += 2)
    {
        if (res)
        {
            if (expr[i] == '&')
            {
                count += num_paren(expr.substr(0, i), true) *
                         num_paren(expr.substr(i+1), true);
            }
            if (expr[i] == '|')
            {
                count += num_paren(expr.substr(0, i), true) *
                         num_paren(expr.substr(i+1), true);
                count += num_paren(expr.substr(0, i), false) *
                         num_paren(expr.substr(i+1), true);
                count += num_paren(expr.substr(0, i), true) *
                         num_paren(expr.substr(i+1), false);
            }
            if (expr[i] == '^')
            {
                count += num_paren(expr.substr(0, i), true) *
                         num_paren(expr.substr(i+1), false);
                count += num_paren(expr.substr(0, i), false) *
                         num_paren(expr.substr(i+1), true);
            } 
        }
        else
        {
            if (expr[i] == '&')
            {
                count += num_paren(expr.substr(0, i), true) *
                         num_paren(expr.substr(i+1), false);
                count += num_paren(expr.substr(0, i), false) *
                         num_paren(expr.substr(i+1), true);
                count += num_paren(expr.substr(0, i), false) *
                         num_paren(expr.substr(i+1), false);
            }
            if (expr[i] == '|')
            {
                count += num_paren(expr.substr(0, i), false) *
                         num_paren(expr.substr(i+1), false);
            }
            if (expr[i] == '^')
            {
                count += num_paren(expr.substr(0, i), true) *
                         num_paren(expr.substr(i+1), true);
                count += num_paren(expr.substr(0, i), false) *
                         num_paren(expr.substr(i+1), false);
            }
        }
    }
    return count;
}
