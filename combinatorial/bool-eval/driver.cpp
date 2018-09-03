#include "bool_eval.h"

int main(int argc, char const *argv[])
{
    std::string s;
    bool res;
    std::fstream infile;
    for (int i = 1; i < argc; ++i)
    {
        infile.open(argv[i]);
        infile >> s >> res;
        std::cout << "num ways to parenthesize " << argv[i] << ": " << num_paren(s, res) << "\n";
        infile.close();
    }
    return 0;
}
