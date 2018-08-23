#include <stdio.h>
#include <stdlib.h>

void fill_helper(int** canvas, int n, int m, int x, int y, int color, int ori, int **done);
void fill(int** canvas, int n, int m, int x, int y, int color);
void print_canvas(int** canvas, int n, int m);
