#include "paint_fill.h"

int main(int argc, char const *argv[])
{
    int n, m, val, x, y, color;
    int **canvas;
    FILE *f;

    for (int file = 1; file < argc; ++file)
    {
        f = fopen(argv[file], "r");
        // get input through stdio
        fscanf(f, "%d %d %x %d %d", &x, &y, &color, &n, &m);
        
        canvas = malloc(n * sizeof *canvas);
        for (int i = 0; i < n; ++i)
        {
            canvas[i] = malloc(m * sizeof *canvas[i]);
            for (int j = 0; j < m; ++j)
            {
                fscanf(f, "%x", &val);
                canvas[i][j] = val;
            }
        }

        fill(canvas, n, m, x, y, color);
        printf("%s: \n", argv[file]);
        print_canvas(canvas, n, m);
        printf("\n");

        for (int i = 0; i < n; ++i) free(canvas[i]);
        free(canvas);
        fclose(f);
    }

    return 0;
}
