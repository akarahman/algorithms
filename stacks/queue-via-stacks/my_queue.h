#include <stack>

class my_queue
{
public:
    my_queue() {}
    ~my_queue() {}
    void push(int &val);
    int& top();
    void pop();
    size_t get_size();

private:
    std::stack<int> push_to;
    std::stack<int> pop_from;
    void transfer_stack();
};

void my_queue::transfer_stack()
{
    while (!push_to.empty())
    {
        pop_from.push(push_to.top());
        push_to.pop();
    }
}

void my_queue::push(int &val)
{
    push_to.push(val);
}

int& my_queue::top()
{
    if (pop_from.empty())
    {
        transfer_stack();
    }
    return pop_from.top();
}

void my_queue::pop()
{
    if (pop_from.empty())
    {
        transfer_stack();
    }
    return pop_from.pop();
}