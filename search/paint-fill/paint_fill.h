#include <stdio.h>
#include <stdlib.h>

/*
 * Modifies: canvas, done
 * Effects: fills all cells == ori that are reachable from point (x, y) with color 
 */
void fill_helper(int** canvas, int n, int m, int x, int y, int color, int ori, int **done);

/*
 * Modifies: canvas
 * Effects: fills all cells == ori that are reachable from point (x, y) with color 
 */
void fill(int** canvas, int n, int m, int x, int y, int color);

/*
 * Effects: prints all values in canvas
 */
void print_canvas(int** canvas, int n, int m);
