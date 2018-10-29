/*
 * Problem: Given two singly-linked lists, determine if the two lists intersect and return
 *          the intersecting node.
 * Note:    Two lists intersect if the kth node (by reference) of one lists equals
 *          the jth node of the other list.
 */

#include <fstream>
#include <iostream>

struct node 
{
    int datum;
    node* next;
    node(int d_in, node* n_in) : datum(d_in), next(n_in) {}
};

/*
 * Effects: returns the node at which the two lists l1 and l2
 *          intersect, returns nullptr if they do not intersect.
 */
node* intersects(node *l1, node* l2);

int main(int argc, char const *argv[])
{
    std::fstream infile;
    int size, val;
    node* current = nullptr;
    node* start1 = nullptr;
    node* start2 = nullptr;
    node* tail1 = nullptr;
    node* tail2 = nullptr;
    node* res = nullptr;

    for (int i = 1; i < argc; ++i)
    {
        infile.open(argv[i]);
        infile >> size;

        if (size)
        {
            // read l1
            for (int j = 0; j < size; ++j)
            {
                infile >> val;
                current = new node(val, nullptr);
                if (start1) tail1->next = current;
                else start1 = current;
                tail1 = current;
            }
        }

        // read l2
        infile >> size;
        if (size)
        {
            for (int j = 0; j < size; ++j)
            {
                infile >> val;
                current = new node(val, nullptr);
                if (start2) tail2->next = current;
                else start2 = current;
                tail2 = current;
            }
        }

        // read intersecting list
        infile >> size;
        if (size) 
        {
            infile >> val;
            current = new node(val, nullptr);
            if (tail1) tail1->next = current;
            else start1 = current;
            if (tail2) tail2->next = current;
            else start2 = current;
            tail1 = tail1->next;

            for (int j = 0; j < size-1; ++j)
            {
                infile >> val;
                current = new node(val, nullptr);
                tail1->next = current;
            }
        }

        res = intersects(start1, start2);
        if (res) std::cout << argv[i] << " intersect at value " << res->datum << "\n";
        else std::cout << argv[i] << " doesn't intersect\n";

        current = nullptr;
        start1 = nullptr;
        start2 = nullptr;
        tail1 = nullptr;
        tail2 = nullptr;
        infile.close();
    }

    return 0;
}


node* intersects(node *l1, node* l2)
{
    // if at least one list is empty, they do not intersect
    if (!l1 || !l2) return nullptr;

    int l1_len = 0;
    int l2_len = 0;
    node* l1_cur = l1;
    node* l2_cur = l2;

    // get length of lists
    while (1)
    {
        ++l1_len;
        if (l1_cur->next) l1_cur = l1_cur->next;
        else break;
    }
    while (1)
    {
        ++l2_len;
        if (l2_cur->next) l2_cur = l2_cur->next;
        else break;
    }

    // if they do not share a tail pointer, they do not intersect
    if (l1_cur != l2_cur) return nullptr;
    l1_cur = l1;
    l2_cur = l2;
    // advance the node pointer for the longer list
    if (l1_len > l2_len)
    {
        for (int i = 0; i < l1_len-l2_len; ++i) 
        {
            l1_cur = l1_cur->next;
        }
    }
    if (l2_len > l1_len)
    {
        for (int i = 0; i < l2_len-l1_len; ++i) 
        {
            l2_cur = l2_cur->next;
        }
    }
    // compare each node side by side
    while (l1_cur != l2_cur)
    {
        l1_cur = l1_cur->next;
        l2_cur = l2_cur->next;
    }
    return l1_cur;
}