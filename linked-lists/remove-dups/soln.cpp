/*
 * Problem: Given an unsorted singly-linked list, remove all duplicate values.
 */

#include <iostream>
#include <unordered_map>
#include <fstream>

struct Node 
{
    Node* next;
    int data;
};

/*
 * Modifies: list pointed to by head
 * Effects: removes all duplicate elements from the list pointed to by head
 * Analysis: O(n) space and time complexity
 */
void remove_dups(Node* head);

/*
 * Modifies: list pointed to by head
 * Effects: removes all duplicate elements from the list pointed to by head
 *          using constant auxiliary space
 * Analysis: O(1) space complexity, O(n2) time complexity
 */
void remove_dups_no_buf(Node* head);

void print_list(Node* node);

int main(int argc, char **argv)
{
    std::ifstream infile;
    int x;
    Node* node = nullptr;
    Node* prev = nullptr;
    Node* node_start = nullptr;

    for (int i = 1; i < argc; ++i)
    {
        infile.open(argv[i]);
        while (infile >> x)
        {
            node = new Node;
            node->data = x;
            node->next = nullptr;
            if (prev != nullptr)
            {
                prev->next = node;
            }
            prev = node;
            if (node_start == nullptr)
            {
                node_start = node;
            }
        }
        infile.close();
        std::cout << "list [ ";
        print_list(node_start);
        std::cout << "] after duplicates removed: [ ";
        remove_dups_no_buf(node_start);
        print_list(node_start);
        std::cout << "].\n";

        prev = nullptr;
        node_start = nullptr;
    }

    return 0;
}

void remove_dups(Node* head)
{
    if (head->next == nullptr || head == nullptr) { return head; }

    std::unordered_map<int, int> hash_map; // temp buffer
    Node* current_node = head;
    Node* prev = nullptr;
    while (current_node != nullptr)
    {
        if (hash_map.find(current_node->data) != hash_map.end())
        {
            prev->next = current_node->next;
        }
        else 
        {
            hash_map.insert(std::make_pair(current_node->data, 1));
            prev = current_node;
        }
        current_node = current_node->next;
    }
}

void remove_dups_no_buf(Node* head)
{
    Node* prev;
    for (Node* current = head; current != nullptr; current = current->next)
    {
        prev = current;
        for (Node* runner = current->next; runner != nullptr; runner = runner->next)
        {
            if (runner->data == current->data) 
            {
                prev->next = runner->next;
            }
            else prev = runner;
        }
    }
}

void print_list(Node* node)
{
    Node* current_node = node;
    while (current_node != nullptr)
    {
        std::cout << current_node->data << " ";
        current_node = current_node->next;
    }
}

