#ifndef STACK_H
#define STACK_H

#include <cstddef>

template <typename T>
class Stack
{
public:
    Stack();

    void push();
    void pop();

    T top();

    size_t size();
    bool empty();
};

#endif // STACK_H
