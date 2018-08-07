#include <stdlib.h>
#include "binary_search.h"

void test_empty();
void test_single_elem_exist();
void test_sorted_array_exist();
void test_single_elem_nonexist();
void test_sorted_array_nonexist();

int main(int argc, char const *argv[])
{
    test_empty();
    test_single_elem_exist();
    test_single_elem_nonexist();
}

void test_empty()
{
    std::cout << "Testing binary search on empty vector...\n";
    std::vector<int> v;
    int index = binary_search<int>(0, v);
    assert(index == -1);
    std::cout << "\n";
}

void test_single_elem_exist()
{
    std::cout << "Testing binary search on vector with single element...\n";
    std::vector<int> v;
    v.push_back(1);
    int index = binary_search<int>(1, v);
    assert(v[index] == 1);
    std::cout << v[index] << " found at index " << index << "\n\n";
}

void test_single_elem_nonexist()
{
    std::cout << "Testing binary search on vector with single element...\n";
    std::vector<int> v;
    v.push_back(1);
    int index = binary_search<int>(2, v);
    assert(index == -1);
    std::cout << "\n";
}
