#include <iostream>
#include <vector>

/* 
 * Requires: size <= v.size()
 * Modifies: v
 * Effects: sifts node down if heap property is violated
 */
template <class T> void sift_down(std::vector<T> &v, int node, int size);
/*
 * Modifies: v
 * Effects: builds a heap in-place from v
 */
template <class T> void heapify(std::vector<T> &v);
/*
 * Modifies: v
 * Effects: sorts v in ascending order
 */
template <class T> void heapsort(std::vector<T> &v);


template <class T> void sift_down(std::vector<T> &v, int node, int size)
{
    int child, right_child, left_child;
    
    while (true)
    {
        right_child = 2 * node + 2;
        left_child = 2 * node + 1;

        if (left_child >= size && right_child >= size) return;
        else if (right_child >= size) child = left_child;
        else child = (v[left_child] > v[right_child]) ? left_child : right_child;

        if (v[child] > v[node])
        {
            std::clog << v[node] << " violates heap property. Sifting down...\n";

            /* swap nodes */
            std::swap(v[node], v[child]);
            
            node = child;
        }
        else return;
    }
}

template <class T> void heapify(std::vector<T> &v)
{
    std::clog << "building heap...\n";
    for (int i = v.size()/2 - 1; i >= 0; --i)
    {
        sift_down(v, i, v.size());
    }
}

template <class T> void heapsort(std::vector<T> &v)
{
    heapify(v);
    std::clog << "sorting vector...\n";
    int size = v.size();
    while (size > 1)
    {
        std::swap(v[0], v[size-1]);
        --size;
        sift_down(v, 0, size);
    }
}