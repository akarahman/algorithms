/*
 * Problem: Given a stack of n boxes with widths wn, heights hn and depths dn,
 *          compute the height of the highest possible stack. The height of the 
 *          stack is the sum of all heights in the stack.
 * Restrictions: boxes cannot be rotated.
 *               A box can only be placed on top of another box iff it is strictly smaller 
 *               in width, height and depth than the box below it.
 * Note: it is possible that some boxes may not be included in the tallest stack.
 */

#include <iostream>
#include <stack>
#include <vector>
#include <fstream>

struct box
{
    int w, h, d;
    box(int w_in, int h_in, int d_in) : w(w_in), h(h_in), d(d_in) {}
    bool operator> (const box &rhs) const
    {
        return (w > rhs.w);
    }
};

/* 
 * Effects: returns true if top can be placed on bottom, false otherwise
 */
bool is_valid_placement(const box &top, const box &bottom);

/* 
 * Requires: index, max and current are non-negative integers
 *           boxes is sorted in descending order
 * Modifies: max
 * Effects: computes the height of the tallest stack and stores the value in max
 */
void build_stack_helper(const std::vector<box> &boxes, int index, int &max, int current);

/*
 * Effects: returns the height of the tallest possible stack of boxes
 */
int build_stack(std::vector<box> boxes);