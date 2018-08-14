#include <iostream>
#include <vector>
#include <iterator>

// Effects: prints elements in v within the range [start, end]
template <class T> void print_vect(std::ostream &os, std::vector<T> &v, int start, int end)
{
    os << "[ ";
    for (int i = start; i <= end; ++i)
    {
        os << v[i] << " ";
    }
    os << "]";
}

/*
 * Requires: elements in the range [start1, start2) and [start2, end2) in v are each sorted subarrays
 * Modifies: v
 * Effects: merges the two subarrays and copies the result to v[start1, end2)
 */
template <class T> void merge(std::vector<T> &v, int start1, int start2, int end2, int &num_comp);

/*
 * Requires: start and end are non-negative integers, start < v.size(), end < v.size(), start <= end
 * Modifies: v
 * Effects: sorts elements in v withn the range [start, end]
 */
template <class T> void mergesort_helper(std::vector<T> &v, int start, int end);

/*
 * Modifies: v
 * Effects: sorts v
 */
template <class T> void mergesort(std::vector<T> &v);

/*
 * Modifies: v
 * Effects: sorts v
 */
template <class T> void bottom_up_mergesort(std::vector<T> &v);


template <class T> void merge(std::vector<T> &v, int start1, int start2, int end2, int &num_comp)
{
    ++num_comp;
    if (v[start2-1] <= v[start2]) return;
    // for debugging purposes only
    std::clog << "merging subarrays ";
    print_vect(std::clog, v, start1, start2-1);
    std::clog << " and ";
    print_vect(std::clog, v, start2, end2-1);
    std::clog << "\n";

    int end1 = start2;
    int s = start1;
    std::vector<T> res;
    while (start1 != end1 && start2 != end2)
    {
        ++num_comp;
        res.push_back(std::min(v[start1], v[start2]));
        if (res.back() == v[start1]) ++start1;
        else ++start2;
    }
    while (start1 != end1)
    {
        res.push_back(v[start1]);
        ++start1;
    }
    while (start2 != end2)
    {
        res.push_back(v[start2]);
        ++start2;
    }
    for (int i = 0; i < res.size(); ++i)
    {
        v[s] = res[i];
        ++s;
    }
}

template <class T> void mergesort_helper(std::vector<T> &v, int start, int end, int &num_comp)
{
    // for debugging purposes only
    std::clog << "recursively sorting ";
    print_vect(std::clog, v, start, end);
    std::clog << "\n";

    if (start == end)
    {
        return;
    }
    int mid = (end-start)/2 + start;
    mergesort_helper(v, start, mid, num_comp);
    mergesort_helper(v, mid+1, end, num_comp);
    merge(v, start, mid+1, end+1, num_comp);
}

template <class T> void mergesort(std::vector<T> &v)
{
    if (v.empty()) return;
    int num_comp = 0;
    mergesort_helper(v, 0, v.size()-1, num_comp);
    std::cout << "num comparisons: " << num_comp << "\n";
}

template <class T> void bottom_up_mergesort(std::vector<T> &v)
{
    int end;
    int num_comp = 0;
    // for subarrays of size 1, 2, 4, ... , N-1
    for (int i = 1; i < v.size(); i *= 2)
    {
        // for each pair of subarrays of size i
        // skip subarray if does not have another to merge with
        for (int j = 0; j < v.size()-i; j += i*2)
        {
            // if one subarray is less than the size of the subarray, take whats left
            end = (j+(i*2) > v.size()) ? v.size() : j+(i*2);
            merge(v, j, j+i, end, num_comp);
        }
    }
    std::cout << "num comparisons: " << num_comp << "\n";
}