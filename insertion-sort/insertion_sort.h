#include <iostream>
#include <vector>

template <class T> void insertion_sort(std::vector<T> &v);

template <class T> void insertion_sort(std::vector<T> &v)
{
    int index;
    int num_comparisons = 0;
    int num_swaps = 0;
    for (int i = 1; i < v.size(); ++i)
    {
        index = i;
        ++num_comparisons;
        while (index && v[index] < v[index-1])
        {
            std::clog << "swapping " << v[index] << " with " << v[index-1] << "\n";
            std::swap(v[index], v[index-1]);
            --index;
            ++num_comparisons;
            ++num_swaps;
        }
    }
    std::cout << "comparison count: " << num_comparisons << "\n";
    std::cout << "swap count: " << num_swaps << "\n";
}