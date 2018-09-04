/* 
 * Given a string, write a function to check if it is a permutation of a palindrome.
 * Not limited to dictionary words.
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

bool palindrome_perm(std::string str)
{
    if (str.length() < 2)
    {
        return true;
    }

    std::unordered_map<char, int> letters;
    auto it = letters.end();
    int letter_count = 0;
    bool odd_found = false;
    bool odd = false;

    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == ' ')
        {
            continue;
        }

        letter_count++;
        it = letters.find(str[i]);
        if (it != letters.end())
        {
            it->second++;
        }
        else
        {
            letters.insert(std::make_pair(str[i], 1));
        }
    }

    odd = letter_count % 2;
    for (auto iter = letters.begin(); iter != letters.end(); ++iter)
    {
        if ((iter->second % 2) == 1)
        {
            if (!odd || odd_found)
            {
                return false;
            }
            odd_found = true;
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
        if (palindrome_perm(str))
        {
            std::cout << str << " is a permutation of a palindrome.\n";
        }
        else {
            std::cout << str << " is not a permutation of a palindrome.\n";
        }
    }

    return 0;
}