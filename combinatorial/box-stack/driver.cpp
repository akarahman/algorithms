#include "box_stack.h"

int main(int argc, char const *argv[])
{
    std::fstream infile;
    int n, w, h, d;
    std::vector<box> boxes;
    for (int i = 1; i < argc; ++i)
    {
        infile.open(argv[i]);
        infile >> n;
        for (int j = 0; j < n; ++j)
        {
            infile >> w >> h >> d;
            boxes.push_back(box(w, h, d));
        }
        std::cout << argv[i] << " tallest stack: " << build_stack(boxes) << "\n";
        infile.close();
        boxes.clear();
    }
    return 0;
}
