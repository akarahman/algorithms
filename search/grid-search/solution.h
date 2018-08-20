/*
 * Problem: Given an n x m grid, find a path from (0, 0) to (n-1, m-1).
 *          Only right and down movements are allowed.
 * Input:   n, m, array of coordinates (x,y) representing off limit cells that cannot
 *          be included in the path
 *          n > 0, m > 0
 *          0 < x < n, 0 < y < m
 * Output:  sequence of coordintes representing the path
 */

#include <iostream>
#include <vector>
#include <unordered_set>

struct coord
{
    int x;
    int y;
    coord(int x_in, int y_in) : x(x_in), y(y_in) {}
    bool operator== (const coord &rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }
};

struct coord_hash
{
    size_t operator() (const coord &c) const
    {
        return pow(c.x, c.y);
    }
};

/*
 * Requires: n > 0, m > 0, loc is a coordinate in the grid
 * Modifies: results
 * Effects: returns true if path found, false otherwise
 *          sets results to a sequence of coords representing the path from 
 *          dest(exclusive) to start(inclusive)
 */
bool helper(std::unordered_set<coord, coord_hash> &off_limits, 
            std::vector<coord> &results, 
            coord &loc, int n, int m);

/*
 * Requires: n > 0, m > 0
 * Effects: returns a sequence of coords representing the path from the start to dest
 */
std::vector<coord> find_path(std::unordered_set<coord, coord_hash> &off_limits, int n, int m);

/*
 * Requires: n > 0, m > 0
 * Effects: prints the grid and path
 *          'p' represents a cell in the path, 'x' represents a cell that is off limits,
 *          '.' is a regular cell
 *          example: 
 *              px...
 *              pppx.
 *              ..ppp
 */
void print_path(std::vector<coord> &path, std::unordered_set<coord, coord_hash> &off_limits, int n, int m);