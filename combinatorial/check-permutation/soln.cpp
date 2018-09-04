/* Given two strings, write a method to decide if one is a permutation of the other */
#include <iostream>
#include <string>
#include <fstream>

bool is_permutation(std::string s1, std::string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    
    // are identical strings a permutation of each other?
    if (s1 != s2)
    {
        return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    std::ifstream infile;
    std::string str1, str2;

    for (int i = 1; i < argc; ++i)
    {
        infile.open(argv[i]);
        std::getline(infile, str1);
        std::getline(infile, str2);
        infile.close();
        if (is_permutation(str1, str2))
        {
            std::cout << str1 << " and " << str2 << " are permutations of each other.\n";
        }
        else {
            std::cout << str1 << " and " << str2 << " are not permutations of each other.\n";
        }
    }

    return 0;
}