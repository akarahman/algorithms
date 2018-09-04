#include <stdio.h>
#include <stdlib.h>

char* urlify(char*, int);

int main(int argc, char const *argv[])
{
    FILE* infile;
    size_t alloc, size;
    for (int i = 1; i < argc; ++i)
    {
        infile = fopen(argv[i], "r");
        fscanf(infile, "%zu %zu", &alloc, &size);
        char* s = (char *)malloc(alloc * sizeof(char));
        getline(&s, &size, infile); // skip \n char
        getline(&s, &size, infile);
        fclose(infile);
        printf("%s urlified: %s\n", argv[i], urlify(s, size));
    }
    return 0;
}


char* urlify(char* s, int size)
{
    int end = size-1;
    int i;
    for (i = 0; i < size; ++i)
    {
        if (s[i] == ' ') end += 2;
    }
    
    for (i = size-1; i >= 0; --i)
    {
        if (s[i] != ' ') s[end--] = s[i];
        else
        {
            s[end--] = '0';
            s[end--] = '2';
            s[end--] = '%';
        }
    }

    return s;
}