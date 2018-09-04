/* Implement an algorithm to determine if a string has unique characters */
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>

bool unique_chars(std::string str)
{
    if (str.length() <= 1)
    {
        return true;
    }

    std::sort(str.begin(), str.end());
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == str[i+1])
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv)
{
    std::ifstream infile;
    std::string str;

    for (int i = 1; i < argc; ++i)
    {
        infile.open(argv[i]);
        std::getline(infile, str);
        infile.close();
        if (unique_chars(str))
        {
            std::cout << str << " has all unique characters.\n";
        }
        else {
            std::cout << str << " does not have all unique characters.\n";
        }
    }

    return 0;
}
