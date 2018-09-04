/* Implement a method to perform basic string compression using the counts of repeated chars */
#include <iostream>
#include <string>
#include <fstream>

std::string compress(std::string str)
{
    if (str.length() < 2)
    {
        return str;
    }

    std::string original = str;
    int count, start = 0;
    for (int i = 0; i < str.length(); )
    {
        count = 1;
        start = i;
        while (i != str.length())
        {
            if (str[i] == str[i+1])
            {
                count++;
                i++;
            }
            else
            {
                break;
            }
        }
        if (count > 1)
        {
            str.replace(start + 1, count - 1, std::to_string(count));
            i = start + 1;
        }
        else
        {
            i++;
        }
    }

    if (original.length() == str.length())
    {
        return original;
    }
    return str;
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
        std::string compressed = compress(str);
        std::cout << str << " compressed to " << compressed << "\n";
    }

    return 0;
}