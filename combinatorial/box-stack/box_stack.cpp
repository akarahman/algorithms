#include "box_stack.h"

bool is_valid_placement(const box &top, const box &bottom)
{
    return (bottom.w > top.w && bottom.h > top.h && bottom.d > top.d);
}

void build_stack_helper(const std::vector<box> &boxes, int index, int &max, int current)
{
    if (index >= boxes.size())
    {
        if (current > max) max = current;
    }

    for (int i = index; i < boxes.size(); ++i)
    {
        int next = i+1;
        current += boxes[i].h;
        while (next < boxes.size() && !is_valid_placement(boxes[next], boxes[i])) 
        {
            next++;
        }
        build_stack_helper(boxes, next, max, current);
        current -= boxes[i].h;
    }
}

int build_stack(std::vector<box> boxes)
{
    std::sort(boxes.begin(), boxes.end(), std::greater<box>());
    int max = 0;
    build_stack_helper(boxes, 0, max, 0);
    return max;
}