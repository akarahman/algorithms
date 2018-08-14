#include <iostream>
#include <vector>

/*
 * Requires: start and end are non-negative integers, start <= end, end is the index past the last element
 * Modifies: pivot
 * Effects: sets pivot to a random number within the range [start, end-start)]
 */
void set_pivot(int &pivot, int start, int end);

/*
 * Requires: start and end are non-negative integers, start <= end, end is the index past the last element
 * Modifies: v
 * Effects: sorts v recursively
 */
template <class T> void quicksort_helper(std::vector<T> &v, int start, int end);

/*
 * Modifies: v
 * Effects: sorts v
 */
template <class T> void quicksort(std::vector<T> &v);

template <class T> void print_vect(std::ostream &os, std::vector<T> &v, int start, int end)
{
    os << "[ ";
    for (int i = start; i < end; ++i)
    {
        os << v[i] << " ";
    }
    os << "]";
}

void set_pivot(int &pivot, int start, int end)
{
    pivot = start + (rand() % (end-start));
}

template <class T> void quicksort_helper(std::vector<T> &v, int start, int end)
{
    if (end - start <= 1) return;
    int pivot;
    int i = start;
    int j = end-1;
    set_pivot(pivot, start, end);
    std::clog << "chosen pivot is " << v[pivot] << "\n";
    std::swap(v[pivot], v[i++]);
    pivot = start;

    while (true)
    {
        while(i < end && v[i] <= v[pivot])
        {
            if (v[i] < v[pivot]) std::swap(v[i], v[pivot++]);
            ++i;
        }
        while(v[j] > v[pivot]) --j;
        if (i >= j) break;

        std::swap(v[i], v[j--]);
    }

    std::clog << "recusively sorting ";
    print_vect(std::clog, v, start, pivot);
    std::clog << " and ";
    print_vect(std::clog, v, i, end);
    std::clog << "\n";

    quicksort_helper(v, start, pivot);
    quicksort_helper(v, i, end);
}


template <class T> void quicksort(std::vector<T> &v)
{
    quicksort_helper(v, 0, v.size());
}

