#include <cassert>
#include "multistack.h"

void test_size();
void test_push();
void test_pop();
void test_push_pop();
void test_pop_at_first();
void test_pop_at_last();
void test_pop_at_mid();
void test_pop_at_next_to_last_empty();

int main(int argc, char const *argv[])
{
    test_size();
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

void test_push()
{

}

void test_pop()
{

}

void test_push_pop()
{

}

void test_pop_at_first()
{

}

void test_pop_at_last()
{

}

void test_pop_at_mid()
{

}

void test_pop_at_next_to_last_empty()
{
    
}