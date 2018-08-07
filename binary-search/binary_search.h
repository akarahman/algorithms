#include <vector>
#include <iostream>
#include <functional>
#include <cassert>

template <class T>
void print_vector(const std::vector<T> &v, int midpoint, int start, int end);
template <class T, class Compare>
int binary_search_helper(T key, const std::vector<T> &v, int start, int end, Compare comp);
template <class T, class Compare = std::less<T> >
int binary_search(T key, const std::vector<T> &v, Compare comp = Compare());

template <class T, class Compare>
int binary_search_helper(T key, const std::vector<T> &v, int start, int end, Compare comp)
{
    if (end < start || v.empty()) 
    { 
        std::cout << "Key not found.\n";
        return -1; 
    }
    std::cout << "Finding midpoint...\n";
    int mid = (end - start) / 2 + start;
    print_vector(v, mid, start, end);
    if (v[mid] == key) { return mid; }

    /* if key is less than midpoint */
    if (comp(key, v[mid]))
    {
        std::cout << "Searching left subarray...\n";
        return binary_search_helper(key, v, start, mid-1, comp);
    }

    std::cout << "Searching right subarray...\n";
    return binary_search_helper(key, v, mid+1, end, comp);
}

template <class T, class Compare>
int binary_search(T key, const std::vector<T> &v, Compare comp)
{
    std::cout << "Searching for key " << key << "...\n";
    return binary_search_helper(key, v, 0, v.size()-1, comp);
}

template <class T>
void print_vector(const std::vector<T> &v, int midpoint, int start, int end)
{
    std::cout << "[ ";
    for (int i = start; i <= end; ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "]\n";
    // int pos = 2 + (midpoint-start)*2;
    // for (int i = 0; i < pos; ++i)
    // {
    //     std::cout << " ";
    // }
    // std::cout << "^\n";
}
