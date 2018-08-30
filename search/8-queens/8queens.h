/*
 * Problem: Find the number of ways to solve an 8-queens problem.
 */

#include <iostream>
#include <vector>

static const int GRID_SIZE = 8;

/*
 * Requires: cols.size() == 8, cols[n] == -1 if no queen placed on row,
 *           else cols[n] is the column number of the queen placed on row
 *           for all n = 0, 1, 2,..., 7
 *           row >= 0, col >= 0
 * Effects: returns true if placement at (row, col) is valid, false otherwise
 */
bool is_valid_placement(const std::vector<int> &cols, int row, int col);

/*
 * Requires: cols.size() == 8, cols[n] == -1 if no queen placed on row,
 *           else cols[n] is the column number of the queen placed on row
 *           for all n = 0, 1, 2,..., 7
 *           row >= 0
 * Modifies: cols, results
 * Effects: finds all solutions to an 8-queens problem and adds them to results
 */
void place_queens(std::vector<int> &cols, int row, std::vector<std::vector<int>> &results);

/*
 * Effects: prints all solutions and solution count
 */
void print_solns(std::vector<std::vector<int>> &solns);

/*
 * Effects: prints all solutions to an 8-queens problem and solution count
 */
void solve();
