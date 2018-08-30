#include "8queens.h"

bool is_valid_placement(const std::vector<int> &cols, int row, int col)
{
    // check every filled row
    for (int r = 0; r < row; ++r)
    {
        // if attempting to place queen in an occupied column
        if (col == cols[r]) return false;
        // if attempting to place queen in occupied diag
        if (abs(col - cols[r]) == abs(row - r)) return false;
    }
    return true;
}

void place_queens(std::vector<int> &cols, int row, std::vector<std::vector<int>> &results)
{
    // all queens placed
    if (row == GRID_SIZE) results.push_back(cols);
    else
    {
        // check each column to see if can be placed
        for (int c = 0; c < GRID_SIZE; ++c)
        {
            if (is_valid_placement(cols, row, c))
            {
                // place queen and move to next row
                cols[row] = c;
                place_queens(cols, row+1, results);
            }
        }
    }
}

void print_solns(std::vector<std::vector<int>> &solns)
{
    // for each solution
    for (int i = 0; i < solns.size(); ++i)
    {
        // for each row
        for (int j = 0; j < solns[i].size(); ++j)
        {
            // for each column
            for (int n = 0; n < GRID_SIZE; ++n)
            {
                if (n == solns[i][j]) std::cout << "Q ";
                else std::cout << "X ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    std::cout << "total solutions: " << solns.size() << "\n";
}

void solve()
{
    std::vector<int> cols(GRID_SIZE, -1);
    std::vector<std::vector<int>> res;
    place_queens(cols, 0, res);
    print_solns(res);
}
