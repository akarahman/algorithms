#include <iostream>
#include <vector>

template <class T> int find_min(std::vector<T> &v, int &num_comparisons, int start);
template <class T> void selection_sort(std::vector<T> &v);

template <class T> int find_min(std::vector<T> &v, int &num_comparisons, int start)
{
    int min_index = start;
    for (int i = start+1; i < v.size(); ++i)
    {
        ++num_comparisons;
        if (v[i] < v[min_index]) min_index = i;
    }
    return min_index;
}

template <class T> void selection_sort(std::vector<T> &v)
{
    int index;
    int num_comparisons = 0;
    int num_swaps = 0;
    for (int i = 0; i < v.size()-1; ++i)
    {
        index = find_min(v, num_comparisons, i);
        if (index != i)
        {
            std::swap(v[i], v[index]);
            ++num_swaps;
        } 
    }
    std::cout << "comparison count: " << num_comparisons << "\n";
    std::cout << "swap count: " << num_swaps << "\n";
}