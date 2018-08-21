/*
 * Problem: you know.
 */

#include <iostream>

/*
 * Requires: src > 0
 * Modifies: src, dest, num_moves
 * Effects: moves one disk from src to dest
 *          decrements src, increments dest and num_moves
 */
void move_disk(int &src, int &dest, int &num_moves);

/*
 * Requires: h <= src
 * Modifies: src, dest, num_moves
 * Effects: moves the top h disks from src to dest
 */
void move_tower(int h, int &src, int &dest, int &temp, int &num_moves);

/*
 * Effects: solves an h-disk towers of hanoi problem and prints the number of moves
 */
void solve(int h);

void move_disk(int &src, int &dest, int &num_moves)
{
    src--;
    dest++;
    num_moves++;
}

void move_tower(int h, int &src, int &dest, int &temp, int &num_moves)
{
    if (h > 0)
    {
        move_tower(h-1, src, temp, dest, num_moves);
        move_disk(src, dest, num_moves);
        move_tower(h-1, temp, dest, src, num_moves);
    }
}

void solve(int h)
{
    int num_moves = 0;
    int src = h;
    int temp = 0;
    int dest = 0;
    move_tower(h, src, dest, temp, num_moves);
    std::cout << "solved in " << num_moves << " moves.\n";
}