#include <iostream>
#include <string>
#include <fstream>

bool is_string_rotation(std::string s1, std::string s2)
{
    std::string cat = s1 + s1;
    std::size_t found;
    found = cat.find(s2);
    if (s1.length() == s2.length() && s1.length() > 0) {
        if (found != std::string::npos)
        {
            return true;
        }
    }
    return false;
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
        if (is_string_rotation(str1, str2))
        {
            std::cout << str2 << " is a rotation of " << str1 << " \n";
        }
        else {
            std::cout << str2 << " is not a rotation of " << str1 << " \n";
        }
    }

    return 0;
}