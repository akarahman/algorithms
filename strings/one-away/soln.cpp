/* 
 * Given two strings, write a function to check if they are one edit away.
 * Operations: insert char, remove char, replace char.
 */
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

bool one_away(std::string s1, std::string s2)
{
    if (s1 == s2)
    {
        return true;
    }

    int s1_len = s1.length();
    int s2_len = s2.length();
    bool edited = false;
    if (std::abs(s1_len - s2_len) > 1)
    {
        return false;
    }

    // for strings of equal length
    if (s1_len == s2_len)
    {
        for (int i = 0; i < s1_len; ++i)
        {
            if (s1[i] != s2[i])
            {
                if (!edited)
                {
                    edited = true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }

    // for strings of unequal length
    // make s2 the longer string if applicable
    if (s1_len > s2_len) {
        std::string temp = s1;
        s1 = s2;
        s2 = temp;
    }

    for (int i = 0, j = 0; i < s1.length(); ++i, ++j)
    {
        if (s1[i] != s2[j])
        {
            if (!edited)
            {
                if (s1[i] == s2[j+1])
                {
                    edited = true;
                    j++;
                }
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    std::ifstream infile;
    std::string str1;
    std::string str2;

    for (int i = 1; i < argc; ++i)
    {
        infile.open(argv[i]);
        std::getline(infile, str1);
        std::getline(infile, str2);
        infile.close();
        if (one_away(str1, str2))
        {
            std::cout << str1 << " and " << str2 << " are one edit away.\n";
        }
        else {
            std::cout << str1 << " and " << str2 << " are multiple edits away.\n";
        }
    }

    return 0;
}