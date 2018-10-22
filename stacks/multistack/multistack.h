#include <vector>
#include <iostream>

class multistack
{
public:
    multistack ();
    multistack (int size);
    void push (int val);
    void pop();
    void pop_at(int index);
    int top_at(int index);
    int top();
    size_t get_size();
private:
    std::vector<std::vector<int> > stack;
    int substack_size;
    int get_substack();
    void shift(int index);
};

multistack::multistack ()
{
    substack_size = 10;
    stack.push_back(std::vector<int>());
}

multistack::multistack (int size)
{
    substack_size = size;
    stack.push_back(std::vector<int>());
}

int multistack::get_substack()
{
    return stack.size()-1;
}

void multistack::shift(int index)
{
    for (int i = index; i < stack.size(); ++i)
    {
        for (int j = 0; j < stack[i].size()-2; ++j)
        {
            stack[i][j] = stack[i][j+1];
        }
        stack[i].pop_back();
        if (i != stack.size()-1)
        {
            stack[i].push_back(stack[i+i].front());
        }
    }
}

void multistack::push (int val)
{
    if (stack[get_substack()].size() >= substack_size)
    {
        stack.push_back(std::vector<int>());
    }
    stack[get_substack()].push_back(val);
}

void multistack::pop()
{
    if (stack[get_substack()].empty())
    {
        stack.pop_back();
    }
    stack[get_substack()].pop_back();
}

void multistack::pop_at(int index)
{
    if (index < 0 || index >= stack.size())
    {
        throw std::out_of_range("index out of range.");
    }
    stack[index].pop_back();
    // if popping from last substack
    if (index == get_substack()) return;
    // if the next stack is empty
    if (stack[index+1].empty())
    {
        stack.pop_back();
        return;
    }
    stack[index].push_back(stack[index+1].front());
    shift(index+1);
}

int multistack::top_at(int index)
{
    if (index < 0 || index >= stack.size() || stack[index].empty())
    {
        throw std::out_of_range("index out of range.");
    }
    return stack[index].back();
}

int multistack::top()
{
    if (stack[get_substack()].empty())
    {
        stack.pop_back();
    }
    return stack[get_substack()].back();
}

size_t multistack::get_size()
{
    return (stack.size()-1) * substack_size + stack[stack.size()-1].size();
}

