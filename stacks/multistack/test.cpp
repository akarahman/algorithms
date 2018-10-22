#include <cassert>
#include "multistack.h"

void test_size();
// void test_push();
// void test_pop();
void test_push_pop();
void test_pop_at_first();
void test_pop_at_last();
void test_pop_at_mid();
void test_pop_at_next_to_last_empty();

int main(int argc, char const *argv[])
{
    test_size();
    test_push_pop();
    test_pop_at_first();
    test_pop_at_last();
    test_pop_at_mid();
    return 0;
}

void test_size()
{
    multistack stack;
    assert(stack.get_size() == 0);
    for (int i = 0; i < 5; ++i)
    {
        stack.push(i);
    }
    assert(stack.get_size() == 5);
    for (int i = 0; i < 5; ++i)
    {
        stack.push(i);
    }
    assert(stack.get_size() == 10);
    for (int i = 0; i < 11; ++i)
    {
        stack.push(i);
    }
    assert(stack.get_size() == 21);
}

void test_push_pop()
{
    multistack stack;
    assert(stack.get_size() == 0);
    for (int i = 0; i < 25; ++i)
    {
        stack.push(i);
    }
    assert(stack.get_size() == 25);
    for (int i = 24; i >= 0; --i)
    {
        assert(stack.top() == i);
        stack.pop();
        assert(stack.get_size() == i);
    }
    assert(stack.get_size() == 0);
}

void test_pop_at_first()
{
    multistack stack;
    assert(stack.get_size() == 0);
    for (int i = 0; i < 25; ++i)
    {
        stack.push(i);
    }
    assert(stack.get_size() == 25);
    assert(stack.top_at(0) == 9);
    stack.pop_at(0);
    assert(stack.top_at(0) == 10);
}

void test_pop_at_last()
{
    multistack stack;
    assert(stack.get_size() == 0);
    for (int i = 0; i < 25; ++i)
    {
        stack.push(i);
    }
    assert(stack.get_size() == 25);
    assert(stack.top_at(2) == 24);
    stack.pop_at(2);
    assert(stack.top_at(2) == 23);
}

void test_pop_at_mid()
{
    multistack stack;
    assert(stack.get_size() == 0);
    for (int i = 0; i < 25; ++i)
    {
        stack.push(i);
    }
    assert(stack.get_size() == 25);
    assert(stack.top_at(1) == 19);
    stack.pop_at(1);
    assert(stack.top_at(1) == 20);
}

void test_pop_at_empty()
{
    
}

void test_pop_at_next_to_last_empty()
{
    
}