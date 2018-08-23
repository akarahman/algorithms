#include <stdio.h>
#include <stdlib.h>
#include "solution.h"

int main(int argc, char const *argv[])
{
    int mcand = 0;
    int mplier = 0;

    // get input through stdio
    while (scanf("%d", &mcand) != EOF && scanf("%d", &mplier) != EOF)
    {
        printf("%dx%d = %d\n", mcand, mplier, multiply(mcand, mplier));
    }

    return 0;
}
