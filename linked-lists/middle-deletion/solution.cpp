/*
 * Problem: Given access to a node in a linked list, delete it from the list.
 */

#include <iostream>
#include <fstream>

struct node
{
    int datum;
    node* next;
};

/*
 * Requires: head and d is not null
 * Modifies: head and/or the list pointed to by head
 * Effects: removes node d from the list
 */
void delete_mid(node* &head, node* d);

/*
 * Effects: prints the list pointed to by head
 */
void print_list(node* head);

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
            n->datum = x;
            n->next = nullptr;
            if (prev != nullptr) prev->next = n;
            prev = n;
            if (node_start == nullptr) node_start = n;
        }
        infile.close();

        node* d = node_start;
        for (int i = 0; i < k; i++) d = d->next;
        delete_mid(node_start, d);

        std::cout << argv[i] << " after deletion: ";
        print_list(node_start);
        std::cout << "\n";
        prev = nullptr;
        node_start = nullptr;
    }
    return 0;
}

void delete_mid(node* &head, node* d)
{
    if (head->datum == d->datum) head = head->next;
    else
    {
        node* n = head;
        while (n->next != d) n = n->next;
        n->next = n->next->next;
    }
}

void print_list(node* head)
{
    std::cout << "[ ";
    node* n = head;
    while (n) 
    {
        std::cout << n->datum << " ";
        n = n->next;
    }
    std::cout << "]";
}