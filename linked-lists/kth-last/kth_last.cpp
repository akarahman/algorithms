/*
 * Problem: Find the kth to last element in a singly-linked list.
 */

#include <iostream>
#include <fstream>

struct node
{
    int data;
    node* next;
};

/*
 * Requires: n is a positive integer
 *           n <= size of the list pointed to by head
 * Effects: returns the kth to last value in the list pointed to by head
 */
int kth_last(node* head, int n);

int main(int argc, char const *argv[])
{
    std::ifstream infile;
    int x, k;
    node* n = nullptr;
    node* prev = nullptr;
    node* node_start = nullptr;

    for (int i = 1; i < argc; ++i)
    {
        infile.open(argv[i]);
        infile >> k;
        while (infile >> x)
        {
            n = new node;
            n->data = x;
            n->next = nullptr;
            if (prev != nullptr) prev->next = n;
            prev = n;
            if (node_start == nullptr) node_start = n;
        }
        infile.close();
        std::cout << argv[i] << " " << k << "(th) last value: " 
                  << kth_last(node_start, k) << "\n";
        prev = nullptr;
        node_start = nullptr;
    }
    return 0;
}

int kth_last(node* head, int n)
{
    // fast head is always n-1 nodes ahead of slow
    node *slow = head, *fast = head;
    for (int i = 1; i < n; ++i) fast = fast->next;
    // when fast reaches end of list, slow is at the kth last position
    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}