/*
 * Problem: Partition a linked list around value x, such that all nodes lass than x 
 *          come before all nodes greater than equal to x.
 */

#include <iostream>
#include <fstream>

struct node
{
    int datum;
    node* next;
};

void partition(node* &head, int x);
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
        partition(node_start, k);
        std::cout << argv[i] << " after partition: ";
        print_list(node_start);
        std::cout << "\n";
        prev = nullptr;
        node_start = nullptr;
    }
    return 0;
}

void partition(node* &head, int x)
{
    if (!head || !(head->next)) return;
    node* current = head;
    node* prev = nullptr;
    node* temp;
    bool altered = false;
    while (current)
    {
        if (current->datum < x && altered)
        {
            prev->next = current->next;
            temp = current;
            temp->next = head;
            head = temp;
            current = prev->next;
            altered = true;
        }
        else
        {
            prev = current;
            current = current->next;
        }
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
