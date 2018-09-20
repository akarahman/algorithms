/*
 * Problem: Given a linked-list, check to see if it is a palindrome.
 */

#include <iostream>
#include <fstream>
#include <cassert>

struct node
{
    int datum;
    node* next;
    node* prev;
    node(node* n) : datum(n->datum), next(n->next) {}
    node(int d_in, node* n_in) : datum(d_in), next(n_in) {}
};

/*
 * Requires: head points to a singly-linked list
 * Effects: returns true if the list is palindromic, false otherwise
 */
bool spalindrome(node* head);

/*
 * Requires: head points to a doubly-linked list
 *           tail points to the last element of the list 
 * Effects: returns true if the list is palindromic, false otherwise
 */
bool dpalindrome(node* head, node* tail);

int main(int argc, char const *argv[])
{
    std::ifstream infile;
    int x;
    node* n = nullptr;
    node* prev = nullptr;
    node* node_start = nullptr;

    for (int i = 1; i < argc; ++i)
    {
        infile.open(argv[i]);
        while (infile >> x)
        {
            n = new node(x, nullptr);
            n->prev = prev;
            if (prev != nullptr) prev->next = n;
            prev = n;
            if (node_start == nullptr) node_start = n;
        }
        infile.close();

        bool res = spalindrome(node_start);
        bool other = dpalindrome(node_start, n);
        assert(res == other);

        std::cout << argv[i] << " list ";
        if (res) std::cout << "is a palindrome.\n";
        else std::cout << "is not a palindrome.\n";

        prev = nullptr;
        node_start = nullptr;
    }
    return 0;
}

bool spalindrome(node* head)
{
    if (!head || !(head->next)) return true;
    node* fast = head;
    node* slow = head;
    int size_mid = 0;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        ++size_mid;
    }
    node* second_half = new node(slow);
    second_half->next = nullptr;
    slow = slow->next;
    while (slow)
    {
        node* n = new node(slow);
        n->next = second_half;
        second_half = n;
        slow = slow->next;
    }
    node* first_half = head;
    while (second_half)
    {
        if (first_half->datum != second_half->datum) return false;
        first_half = first_half->next;
        second_half = second_half->next;
    }
    while (second_half)
    {
        node* del = second_half;
        second_half = second_half->next;
        delete del;
    }
    return true;
}

bool dpalindrome(node* head, node* tail)
{
    if (!head || head == tail) return true;
    node* front = head;
    node* back = tail;
    while (front != back && front->prev != back)
    {
        if (front->datum != back->datum) return false;
        front = front->next;
        back = back->prev;
    }
    return true;
}