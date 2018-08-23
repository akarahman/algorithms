#include "paint_fill.h"

void fill_helper(int** canvas, int n, int m, int x, int y, int color, int ori, int **done)
{
    // update color and mark as done to avoid revisiting
    if (canvas[x][y] != color) canvas[x][y] = color;
    done[x][y] = 1;
    // check cell above
    if (x-1 >= 0 && !done[x-1][y] && (canvas[x-1][y] == ori || canvas[x-1][y] == color)) 
    {
        fill_helper(canvas, n, m, x-1, y, color, ori, done);
    }
    // check cell below
    if (x+1 < n && !done[x+1][y] && (canvas[x+1][y] == ori || canvas[x+1][y] == color)) 
    {
        fill_helper(canvas, n, m, x+1, y, color, ori, done);
    }
    // check left cell
    if (y-1 >= 0 && !done[x][y-1] && (canvas[x][y-1] == ori || canvas[x][y-1] == color)) 
    {
        fill_helper(canvas, n, m, x, y-1, color, ori, done);
    }
    // check right cell
    if (y+1 < m && !done[x][y+1] && (canvas[x][y+1] == ori || canvas[x][y+1] == color)) 
    {
        fill_helper(canvas, n, m, x, y+1, color, ori, done);
    }
}

void fill(int** canvas, int n, int m, int x, int y, int color)
{
    int** done;
    done = malloc(n * sizeof *done);
    for (int i = 0; i < n; ++i)
    {
        done[i] = malloc(m * sizeof *done[i]);
        for (int j = 0; j < m; ++j)
        {
            done[i][j] = 0;
        }
    }
    int ori = canvas[x][y];
    fill_helper(canvas, n, m, x, y, color, ori, done);
    for (int i = 0; i < n; ++i) free(done[i]);
    free(done);
}

void print_canvas(int** canvas, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%#x ", canvas[i][j]);
        }
        printf("\n");
    }
}