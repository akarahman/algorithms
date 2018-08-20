#include "solution.h"

bool helper(std::unordered_set<coord, coord_hash> &off_limits, 
            std::vector<coord> &results, coord &loc, int n, int m)
{
    // if the destination can be reached with one move
    if ((loc.x == n - 1 && loc.y + 1 == m - 1) ||
       (loc.x + 1 == n - 1 && loc.y == m - 1))
    {
        results.push_back(loc);
        return true;
    }
    // check if right cell accessible
    if (loc.y < m-1)
        {
        coord right(loc.x, loc.y + 1);
        if (off_limits.find(right) == off_limits.end())
        {
            // if path leads to dest
            if (helper(off_limits, results, right, n, m))
            {
                results.push_back(loc);
                return true;
            }
        }
    }
    // check if cell below is accessible
    if (loc.x < n-1)
    {
        coord down(loc.x + 1, loc.y);
        if (off_limits.find(down) == off_limits.end())
        {
            // if path leads to dest
            if (helper(off_limits, results, down, n, m))
            {
                results.push_back(loc);
                return true;
            }
        }
    }
    
    // current path does not lead to dest
    return false;
}

std::vector<coord> find_path(std::unordered_set<coord, coord_hash> &off_limits, int n, int m)
{
    std::vector<coord> res;
    coord start(0, 0);
    if (n == 1 && m == 1)
    {
        res.push_back(start);
        return res;
    }
    if (!helper(off_limits, res, start, n, m))
    {
        return res;
    }

    // reverse list
    for (int i = 0; i < res.size()/2; ++i)
    {
        std::swap(res[i], res[res.size() - 1 - i]);
    }
    res.push_back(coord(n-1, m-1));
    return res;
}

void print_path(std::vector<coord> &path, std::unordered_set<coord, coord_hash> &off_limits, int n, int m)
{
    std::vector<std::vector<char> > grid;
    int i;
    for (i = 0; i < n; ++i)
    {
        grid.push_back(std::vector<char>(m, '.'));
    }
    for (i = 0; i < path.size(); ++i)
    {
        grid[path[i].x][path[i].y] = 'p';
    }
    for (auto it = off_limits.begin(); it != off_limits.end(); ++it)
    {
        grid[it->x][it->y] = 'x';
    }
    for (i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << grid[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}