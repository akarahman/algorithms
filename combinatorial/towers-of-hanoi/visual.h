/*
 * This version of the solution provides the option to print the state of the 
 * towers after each move
 */

#include <vector>
#include <iostream>

std::ostream& operator<< (std::ostream& os, const std::vector<int>& v);

class towers
{
public:
    /*
     * Effects: creates an h-disk tower of hanoi
     */
    towers(int h);
    ~towers() {}

    /*
     * Effects: prints the current state of the towers
     */
    void print_towers();

    /*
     * Effects: moves all disks back to the src peg
     */
    void reset_towers();

    /*
     * Effects: solves the ToH problem and prints the number of moves
     *          prints the state of the tower after each move if verbose is true
     */
    void solve(bool verbose);

private:
    std::vector<int> src;
    std::vector<int> temp;
    std::vector<int> dest;

    /*
    * Requires: src.size() > 0
    * Modifies: s, d, num_moves
    * Effects: moves top disk from s to d, increments num_moves
    */
    void move_disk(std::vector<int> &s, std::vector<int> &d, int &num_moves);

    /*
    * Requires: h <= src.size()
    * Modifies: src, dest, num_moves
    * Effects: moves the top h disks from src to dest
    */
    void move_tower(int h, std::vector<int> &s, std::vector<int> &d, 
                    std::vector<int> &t, bool &verbose, int &num_moves);
};