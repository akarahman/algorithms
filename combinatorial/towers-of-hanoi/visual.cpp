#include "visual.h"

std::ostream& operator<< (std::ostream& os, const std::vector<int>& v)
{
    for (int i = v.size()-1; i >= 0; --i)
    {
        os << v[i] << " ";
    }
    return os;
}

towers::towers(int h)
{
    for (int i = h; i > 0; --i)
    {
        src.push_back(i);
    }
}

void towers::print_towers()
{
    std::cout << "source: " << src << "   mid: " << temp << "   dest: " << dest << "\n";
}

void towers::move_disk(std::vector<int> &s, std::vector<int> &d, int &num_moves)
{
    d.push_back(s.back());
    s.pop_back();
    ++num_moves;
}

void towers::move_tower(int h, std::vector<int> &s, std::vector<int> &d, 
                        std::vector<int> &t, bool &verbose, int &num_moves)
{
    if (h > 0)
    {
        move_tower(h-1, s, t, d, verbose, num_moves);
        move_disk(s, d, num_moves);
        if (verbose) print_towers();
        move_tower(h-1, t, d, s, verbose, num_moves);
    }
}

void towers::reset_towers()
{
    for (int i = 0; i < dest.size(); ++i)
    {
        src.push_back(dest[i]);
    }
    dest.clear();
}

void towers::solve(bool verbose)
{
    int num_moves = 0;
    if (verbose) print_towers();
    move_tower(src.size(), src, dest, temp, verbose, num_moves);
    std::cout << "solved in " << num_moves << " moves.\n";
}
