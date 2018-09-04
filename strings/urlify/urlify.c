/*
 * Problem: Given a string, replace all spaces with "%20" without using extra space.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Requires: s is large enough to store the final string
 *           size is the true length of s
 * Modifies: s
 * Effects: url-ifies s
 */
void urlify(char* s, size_t size);

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
        urlify(s, size);
        printf("%s urlified: %s\n", argv[i], s);
    }
    return 0;
}


void urlify(char* s, size_t size)
{
    int end = size-1; // index of last char in final string
    int i;
    // scan for spaces to determine length of final string
    for (i = 0; i < size; ++i)
    {
        if (s[i] == ' ') end += 2;
    }
    
    for (i = size-1; i >= 0; --i)
    {
        // copy char
        if (s[i] != ' ') s[end--] = s[i];
        // replace char with "%20"
        else
        {
            s[end--] = '0';
            s[end--] = '2';
            s[end--] = '%';
        }
    }
}