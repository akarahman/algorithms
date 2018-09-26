/*
 * Problem: Given two numbers represented by linked lists, where each node represents
 *          a digit, add the two numbers and return the sum as a linked list.
 * Note:    The digits are stored in reverse order, i.e. 1's digit is stored at the head.
 */

#include <fstream>
#include <iostream>
#include <stack>
#include <cmath>

struct node
{
    int datum;
    node* next;
    node(int d_in, node* n_in) : datum(d_in), next(n_in) {}
};

/*
 * Requires: l1 and l2 represent a valid non-negative integer
 * Effects: returns the sum of l1 and l2 as a linked list (in reversed order)
 */
node* sum_lists(node* l1, node* l2);

/*
 * Effects: prints the number represented by head
 */
void print_number(node* head);

int main(int argc, char const *argv[])
{
    std::ifstream infile;
    int n;
    node* node_start_1 = nullptr;
    node* node_start_2 = nullptr;
    int multiplier;

    for (int i = 1; i < argc; ++i)
    {
        // parse integers and store as reversed linked list

        infile.open(argv[i]);
        infile >> n;
        multiplier = pow(10, floor(log10(n)));
        while (multiplier)
        {
            node_start_1 = new node(n / multiplier, node_start_1);
            n = n % multiplier;
            multiplier /= 10;
        }
        
        infile >> n;
        multiplier = pow(10, floor(log10(n)));
        while (multiplier)
        {
            node_start_2 = new node(n / multiplier, node_start_2);
            n = n % multiplier;
            multiplier /= 10;
        }

        infile.close();

        node* res = sum_lists(node_start_1, node_start_2);
        print_number(node_start_1);
        std::cout << " + ";
        print_number(node_start_2);
        std::cout << " = ";
        print_number(res);
        std::cout << "\n";

        node_start_1 = nullptr;
        node_start_2 = nullptr;
    }
    return 0;
}

node* sum_lists(node* l1, node* l2)
{
    int a = 0;
    int b = 0;
    int multiplier = 1; // list starts with 1's digit
    node* n = l1;
    node* m = l2;

    // convert linked list into integer
    while (n || m)
    {
        if (n)
        {
            a += n->datum * multiplier;
            n = n->next;
        }
        if (m)
        {
            b += m->datum * multiplier;
            m = m->next;
        }
        multiplier *= 10;
    }

    int res = a + b;
    int digit;
    node* ret_head = nullptr;
    
    // convert integer to list
    while (multiplier)
    {
        digit = res / multiplier;
        if (ret_head != nullptr || digit != 0)
        {
            if (!ret_head) ret_head = new node(digit, nullptr);
            else ret_head = new node(digit, ret_head);
        }
        res = res % multiplier;
        multiplier /= 10;
    }

    return ret_head;
}

void print_number(node* head)
{
    std::stack<int> digits;
    node* n = head;
    while (n)
    {
        digits.push(n->datum);
        n = n->next;
    }
    while (!digits.empty())
    {
        std::cout << digits.top();
        digits.pop();
    }
}