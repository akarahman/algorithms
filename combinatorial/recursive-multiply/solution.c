#include "solution.h"

int mult_helper (int mcand, int mplier, int** cache)
{
    if (mcand == 0 || mplier == 0) return 0;
    if (cache[mcand-1][mplier-1] != 0) return cache[mcand-1][mplier-1];
    int shift = mcand >> 1;
    cache[mcand-1][mplier-1] = mult_helper(shift, mplier, cache) +
                               mult_helper(shift, mplier, cache) +
                               mult_helper(mcand - shift - shift, mplier, cache);
    return cache[mcand-1][mplier-1];
}

int multiply (int mcand, int mplier)
{
    int **cache;
    // allocate 2D array
    cache = malloc(mcand * sizeof *cache);
    for (int i = 0; i < mcand; ++i)
    {
        cache[i] = malloc(mplier * sizeof *cache[i]);
        for (int j = 0; j < mplier; ++j)
        {
            // initialize cache
            // prepopulate all entries that have mcand/mplier == 1
            if (i == 0) cache[i][j] = j+1;
            else if (j == 0) cache[i][j] = i+1;
            else cache[i][j] = 0;
        }
    }

    int res = mult_helper(mcand, mplier, cache);

    // free allocated memory
    for (int i = 0; i < mcand; ++i) free(cache[i]);
    free(cache);

    return res;
}