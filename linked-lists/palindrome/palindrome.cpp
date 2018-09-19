/*
 * Problem: Given a linked-list, check to see if it is a palindrome.
 */

#include <iostream>
#include <fstream>

struct node
{
    int datum;
    node* next;
    node(node* n) : datum(n->datum), next(n->next) {}
    node(int d_in, node* n_in) : datum(d_in), next(n_in) {}
};

/*
 * Effects: returns true if the list is palindromic, false otherwise
 */
bool palindrome(node* head);

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
            if (prev != nullptr) prev->next = n;
            prev = n;
            if (node_start == nullptr) node_start = n;
        }
        infile.close();

        bool res = palindrome(node_start);

        std::cout << argv[i] << " list ";
        if (res) std::cout << "is a palindrome.\n";
        else std::cout << "is not a palindrome.\n";

        prev = nullptr;
        node_start = nullptr;
    }
    return 0;
}

bool palindrome(node* head)
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