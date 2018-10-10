/*
 * Problem: Given a circular linked list, find the node at the beginning of the loop.
 * Note:    In a circular linked list, there exists a node that where its next pointer
 *          points to an earlier node
 * Test format: index of the beginning of the loop, followed by a list of values
 * Example: Input: 1
 *                  1   2   3   4     datum
 *                 (A) (B) (C) (D)    node
 *          Output: 1 (B)
 * 
 *          Input: -1 (no loop)
 *                  1   2   3   4   5     datum
 *                 (A) (B) (C) (D) (E)    node
 *          Output: null (undefined)  
 */

#include <iostream>
#include <fstream>
#include <cassert>

struct node
{
    int datum;
    node* next;
    node(int d_in, node* n_in) : datum(d_in), next(n_in) {}
};

/*
 * Requires: head is not null
 * Effects: returns the meetpoint of the two pointers in the loop 
 *          detection algorithm, returns nullptr if a loop does not exist
 */
node* detect_loop(node* head);

/*
 * Effects: returns the beginning of the loop, if it exists, otherwise
 *          returns nullptr
 */
node* find_loop_begin(node* head);

/*
 * Requires: head and n are not null
 *           n is reachable from head
 * Effects: returns the index of n in the list pointed to by head
 */
int get_node_index(node* head, node* n);

int main(int argc, char const *argv[])
{
    std::fstream infile;
    int lbegin_index = 0;
    node* lbegin_node = nullptr;
    node* start = nullptr;
    node* prev = nullptr;
    node* new_node = nullptr;
    int val;
    int node_count = 0;
    node* result = nullptr;

    for (int i = 1; i < argc; ++i)
    {
        infile.open(argv[i]);
        infile >> lbegin_index;
        while (infile >> val)
        {
            new_node = new node(val, nullptr);
            if (!prev) start = new_node;
            else prev->next = new_node;
            // log loop beginning node
            if (node_count == lbegin_index) lbegin_node = new_node;
            prev = new_node;
            ++node_count;
        }
        infile.close();
        new_node->next = lbegin_node;
        result = find_loop_begin(start);

        assert(lbegin_node == result);
        if (!result) std::cout << argv[i] << " list does not contain a loop.\n";
        else std::cout << argv[i] << " loop begins at node " << get_node_index(start, result) << ".\n";

        // reset
        lbegin_node = nullptr;
        start = nullptr;
        prev = nullptr;
        node_count = 0;
    }

    return 0;
}

node* detect_loop(node* head)
{
    node* slow = head;
    node* fast = head;
    while (1)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast) fast = fast->next;
        // if we hit the end of the list, there is no loop
        if (!slow || !fast) return nullptr;
        // meetpoint found
        if (slow == fast) return slow;
    }
}

node* find_loop_begin(node* head)
{
    // make sure the list has enough elements
    if (!head) return nullptr;
    node* slow = head;
    // find loop meet point
    node* fast = detect_loop(head);
    if (!fast) return nullptr; // no loop
    // find loop beginning
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int get_node_index(node* head, node* n)
{
    int index = 0;
    while (head != n)
    {
        head = head->next;
        ++index;
    }
    return index;
}